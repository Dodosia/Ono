#include "onopch.h"
#include "Application.h"

namespace Ono
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		ONO_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (!m_Window->shouldClose())
		{
			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}
			m_Window->OnUpdate();
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}
}

