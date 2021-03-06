#pragma once

#include "renderer/renderers/vulkan/DeviceWrapper.h"
#include "asset/pods/ModelPod.h"
#include "world/nodes/geometry/GeometryNode.h"
#include "vulkan/vulkan.hpp"

namespace vlkn {
// TODO: From https://vulkan-tutorial.com/en/Vertex_buffers/Index_buffer
// store multiple buffers, like the vertex and index buffer, into a single VkBuffer and use offsets in commands like
// vkCmdBindVertexBuffers. The advantage is that your data is more cache friendly in that case, because it's closer
// together. It is even possible to reuse the same chunk of memory for multiple resources if they are not used
// during the same render operations, provided that their data is refreshed, of course. This is known as aliasing
// and some Vulkan functions have explicit flags to specify that you want to do this.

// PERF: batching
struct GeometryGroup {

	vk::UniqueBuffer vertexBuffer;
	vk::UniqueDeviceMemory vertexBufferMemory;

	vk::UniqueBuffer indexBuffer;
	vk::UniqueDeviceMemory indexBufferMemory;

	std::unique_ptr<Texture> albedoText;

	// one for each swapchain image
	// TODO: check
	// https://stackoverflow.com/questions/36772607/vulkan-texture-rendering-on-multiple-meshes this
	std::vector<vk::DescriptorSet> descriptorSets;

	uint32 indexCount{ 0u };
};

class Model {
	std::vector<GeometryGroup> m_geometryGroups;


public:
	Model(DeviceWrapper& device, Descriptors* descriptors, PodHandle<ModelPod> handle);

	const std::vector<GeometryGroup>& GetGeometryGroups() const { return m_geometryGroups; }

	// Prefer using the observer system instead of direct pointers.
	GeometryNode* m_model;
};
} // namespace vlkn
