#pragma once
#include "Core.h"

namespace Ono
{
	class ONO_API Window
	{
	public:
		static Window* Create();
		virtual bool ShouldClose() = 0;
		virtual void Update() = 0;
	protected:
		virtual void Init() = 0;
		virtual void Shutdown() = 0;
	};
}