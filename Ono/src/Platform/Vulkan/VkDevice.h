#pragma once

#include "vulkan/vulkan.h"

namespace Ono
{
	struct QueueFamilyIndices 
	{
		std::optional<uint32_t> graphicsFamily;

		bool isComplete() 
		{
			return graphicsFamily.has_value();
		}
	};


	class VkGpuDevice
	{
	public:
		VkGpuDevice(VkInstance& instance);
		~VkGpuDevice();
	private:
		void Init();
		void Clear();
		void PickPhysicalDevice();

		bool isDeviceSuitable(VkPhysicalDevice device);
		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

		VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
		VkInstance _instance;
	};
}