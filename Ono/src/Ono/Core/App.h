#pragma once
#include "onopch.h"

#include "Core.h"
#include "Window.h"
#include "LayerStack.h"
#include "Ono/Renderer/Renderer.h"

namespace Ono
{
	class ONO_API App
	{
	public:
		App();
		virtual ~App();

		void Run();
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		std::unique_ptr<Window> window;
		std::unique_ptr<Renderer> renderer;
		LayerStack layer_stack;
	};

	App* CreateApp();
}

