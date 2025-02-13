#pragma once

#include "onopch.h"
#include "Ono/Core/Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Ono
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow();
		~WindowsWindow();
		bool ShouldClose() override;
		void Update() override;

	private:
		void Init() override;
		void Shutdown() override;

		GLFWwindow* window;
	};
}