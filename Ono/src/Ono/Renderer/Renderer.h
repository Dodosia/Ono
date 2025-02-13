#pragma once

#include "Ono/Core/Core.h"

namespace Ono
{
	class Renderer
	{
	public:
		static Renderer* Create();
	protected:
		virtual void Init() = 0;
		virtual void Clear() = 0;
	};
}