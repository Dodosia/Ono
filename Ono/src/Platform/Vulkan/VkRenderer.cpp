#include "onopch.h"
#include "VkRenderer.h"
#include "Vulkan.h"
#include "GLFW/glfw3.h"

namespace Ono
{
	Renderer* Renderer::Create()
	{
		return new VkRenderer();
	}

	VkRenderer::VkRenderer()
	{
		Init();
	}

	VkRenderer::~VkRenderer()
	{
		Clear();
	}

	void VkRenderer::Init()
	{

	}

	void VkRenderer::Clear()
	{
		
	}

	void VkRenderer::InitPipeline()
	{

	}

	void VkRenderer::CreateInstance()
	{
		VkApplicationInfo appInfo{};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "Hello Triangle";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "Ono";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_0;

		VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;

		uint32_t glfwExtensionCount = 0;
		const char** glfwExtensions;
		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		createInfo.enabledExtensionCount = glfwExtensionCount;
		createInfo.ppEnabledExtensionNames = glfwExtensions;

		createInfo.enabledLayerCount = 0;

		VK_CHECK(vkCreateInstance(&createInfo, nullptr, &vkInstance));
	}
}

