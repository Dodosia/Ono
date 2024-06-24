#pragma once

#include "Core.h"

namespace Ono
{
	class ONO_API Application
	{
	public:
		Application();
		void Run();
		virtual ~Application();
	};

	Application* CreateApplication();
}

