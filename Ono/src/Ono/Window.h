#pragma once

#include "onopch.h"
#include "Ono/Core.h"

namespace Ono
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Ono Engine",
			unsigned int width = 1280,
			unsigned int height = 720) : Title(title), Width(width), Height(height)
		{
		}
	};

	class ONO_API Window
	{
	public:
		virtual ~Window();

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
		virtual bool shouldClose() = 0;

	protected:
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
		};
	};
}