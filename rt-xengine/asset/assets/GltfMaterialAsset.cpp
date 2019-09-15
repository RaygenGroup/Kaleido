#include "pch.h"

#include "asset/assets/GltfMaterialAsset.h"
#include "system/Engine.h"
#include "asset/AssetManager.h"
#include "asset/assets/GltfFileAsset.h"
#include "asset/util/GltfAux.h"
#include "asset/assets/GltfTextureAsset.h"
#include "asset/assets/DummyAssets.h"

bool GltfMaterialAsset::Load(MaterialPod* pod, const fs::path& path)
{
	const auto pPath = path.parent_path();
	auto pParent = AssetManager::GetOrCreate<GltfFilePod>(pPath);

	const auto info = path.filename();
	const auto ext = std::stoi(&info.extension().string()[1]);

	tinygltf::Model& model = pParent->data;

	auto& gltfMaterial = model.materials.at(ext);
	
	// factors
	auto bFactor = gltfMaterial.pbrMetallicRoughness.baseColorFactor;
	pod->baseColorFactor = { bFactor[0], bFactor[1], bFactor[2], bFactor[3] };
	pod->metallicFactor = static_cast<float>(gltfMaterial.pbrMetallicRoughness.metallicFactor);
	pod->roughnessFactor = static_cast<float>(gltfMaterial.pbrMetallicRoughness.roughnessFactor);
	auto eFactor = gltfMaterial.emissiveFactor;
	pod->emissiveFactor = { eFactor[0], eFactor[1], eFactor[2] };

	// scales/strenghts
	pod->normalScale = static_cast<float>(gltfMaterial.normalTexture.scale);
	pod->occlusionStrength = static_cast<float>(gltfMaterial.occlusionTexture.strength);

	// alpha
	pod->alphaMode = GltfAux::GetAlphaMode(gltfMaterial.alphaMode);

	pod->alphaCutoff = static_cast<float>(gltfMaterial.alphaCutoff);
	// doublesided-ness
	pod->doubleSided = gltfMaterial.doubleSided;


	auto LoadTexture = [&](auto textureInfo, PodHandle<TexturePod>& sampler, int32& textCoordIndex, bool useDefaultIfMissing = true)
	{
		if (textureInfo.index != -1)
		{
			tinygltf::Texture& gltfTexture = model.textures.at(textureInfo.index);

			//auto textPath = pPath / ("#" + (!gltfTexture.name.empty() ? gltfTexture.name : "sampler") + "." + std::to_string(textureInfo.index));
			auto textPath = pPath / ("#sampler." + std::to_string(textureInfo.index));

			sampler = AssetManager::GetOrCreate<TexturePod>(textPath);

			textCoordIndex = textureInfo.texCoord;
		}
		else
		{
			sampler = DefaultTexture::GetDefault();
		}

		return true;
	};

	// samplers
	auto& baseColorTextureInfo = gltfMaterial.pbrMetallicRoughness.baseColorTexture;
	LoadTexture(baseColorTextureInfo, pod->baseColorTexture, pod->baseColorTexCoordIndex);

	auto& emissiveTextureInfo = gltfMaterial.emissiveTexture;
	LoadTexture(emissiveTextureInfo, pod->emissiveTexture, pod->emissiveTexCoordIndex);

	auto& normalTextureInfo = gltfMaterial.normalTexture;
	LoadTexture(normalTextureInfo, pod->normalTexture, pod->normalTexCoordIndex, false);

	// TODO: pack if different
	auto& metallicRougnessTextureInfo = gltfMaterial.pbrMetallicRoughness.metallicRoughnessTexture;
	auto& occlusionTextureInfo = gltfMaterial.occlusionTexture;

	// same texture no need of packing
	//if(metallicRougnessTextureInfo.index == occlusionTextureInfo.index)
	{
		LoadTexture(metallicRougnessTextureInfo, pod->occlusionMetallicRoughnessTexture, pod->occlusionMetallicRoughnessTexCoordIndex);
	}
	return true;
}
