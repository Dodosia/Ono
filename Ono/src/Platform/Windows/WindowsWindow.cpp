#include "onopch.h"
#include "WindowsWindow.h"

namespace Ono
{
	static bool is_glfwInitialized = false;

	Window* Window::Create()
	{
		return new WindowsWindow();
	}

	WindowsWindow::WindowsWindow()
	{
		Init();
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	bool WindowsWindow::ShouldClose()
	{
		bool is_closed = glfwWindowShouldClose(window);
		return is_closed;
	}

	void WindowsWindow::Update()
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	void WindowsWindow::Init()
	{
		if (!is_glfwInitialized)
		{
			int success = glfwInit();

			is_glfwInitialized = true;
		}

		window = glfwCreateWindow(500, 500, "Window", nullptr, nullptr);
		glfwMakeContextCurrent(window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		//glfwSetWindowUserPointer(window, &windowData);
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(window);
	}
}
