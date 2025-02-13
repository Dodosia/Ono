#include "onopch.h"
#include "App.h"

#include <glad/glad.h>

namespace Ono
{
	App::App()
	{
		window = std::unique_ptr<Window>(Window::Create());
	}

	App::~App()
	{
		
	}

	void App::Run()
	{
		while (!window->ShouldClose())
		{
			renderer = std::unique_ptr<Renderer>(Renderer::Create());
			for (auto layer : layer_stack)
			{
				layer->Update();
			}
			window->Update();
		}
	}

	void App::PushLayer(Layer* layer)
	{
		layer_stack.PushLayer(layer);
	}

	void App::PushOverlay(Layer* overlay)
	{
		layer_stack.PushOverlay(overlay);
	}
}

