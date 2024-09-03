#pragma once

#include "Ono/Core.h"
#include "Ono/Log.h"

#include "Ono/Window.h"
#include "Ono/LayerStack.h"

namespace Ono
{
	class ONO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }

	private:
		std::unique_ptr<Window> m_Window;
		static Application* s_Instance;

		bool m_Running = false;
		LayerStack m_LayerStack;
	};

	Application* CreateApplication();
}

