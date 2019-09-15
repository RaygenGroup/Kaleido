#pragma once

#include "system/reflection/Reflector.h"
#include <filesystem>

namespace fs = std::filesystem;

struct AssetPod
{
	virtual ~AssetPod() = default; // Ensure assetpod is polymorphic
};

struct DeletableAssetPod : AssetPod
{

};

template<typename N>
constexpr bool is_deletable_pod_v = std::is_base_of_v<DeletableAssetPod, N>;

template<typename PodTypeT>
struct PodHandle
{
public:
	using PodType = PodTypeT;
	static_assert(std::is_base_of_v<AssetPod, PodType>, "Pod type should be a pod");
private:
	size_t podId{ 0 };

	PodType* DebugGetPointer() const 
	{
		return Engine::GetAssetManager()->__Internal_MaybeFindPod<PodType>(podId);
	}

public:
	PodType* operator->() const
	{
		assert(podId != 0);
		PodType* pod = Engine::GetAssetManager()->__Internal_MaybeFindPod<PodType>(podId);
		// TODO: If deletable pods get implemented, load on create non deletable pods in asset manager.
		//if constexpr (is_deletable_pod_v<PodType>)
		//{
			if (pod == nullptr) 
			{
				pod = Engine::GetAssetManager()->__Internal_RefreshPod<PodType>(podId);
			}
		//}
		assert(pod);
		return pod;
	}

	bool HasBeenAssigned() const
	{
		return podId != 0;
	}

	friend class AssetManager;
};