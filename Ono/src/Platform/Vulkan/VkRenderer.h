#pragma once

#include "Ono/Renderer/Renderer.h"
#include "VkPipeline.h"

namespace Ono
{
	class VkRenderer : public Renderer
	{
	public:
		VkRenderer();
		~VkRenderer();
	private:
		void Init() override;
		void Clear() override;

		void InitPipeline();
		void CreateInstance();

		VkInstance vkInstance;
	};
}