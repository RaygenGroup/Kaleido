#pragma once

#include "renderer/renderers/vulkan/DeviceWrapper.h"

#include <vulkan/vulkan.hpp>

namespace vlkn {
class Swapchain {

	vk::UniqueSwapchainKHR m_handle;

	vk::Format m_imageFormat;
	vk::Extent2D m_extent;

	std::vector<vk::Image> m_images;
	std::vector<vk::UniqueImageView> m_imageViews;

	vk::UniqueRenderPass m_renderPass;

	std::vector<vk::UniqueFramebuffer> m_framebuffers;

	DeviceWrapper& m_assocDevice;
	vk::SurfaceKHR m_assocSurface;

	// WIP: depth image
	vk::UniqueImage m_depthImage;
	vk::UniqueDeviceMemory m_depthImageMemory;
	vk::UniqueImageView m_depthImageView;


public:
	Swapchain(DeviceWrapper& device, vk::SurfaceKHR surface);

	vk::SwapchainKHR Get() const { return m_handle.get(); }
	vk::Format GetImageFormat() const { return m_imageFormat; }
	vk::Extent2D GetExtent() const { return m_extent; }
	vk::RenderPass GetRenderPass() const { return m_renderPass.get(); }
	std::vector<vk::Image> GetImages() const { return m_images; }
	std::vector<vk::ImageView> GetImageViews() const { return vk::uniqueToRaw(m_imageViews); }
	std::vector<vk::Framebuffer> GetFramebuffers() const { return vk::uniqueToRaw(m_framebuffers); }

	uint32 GetImageCount() const { return static_cast<uint32>(m_images.size()); }
};
} // namespace vlkn
