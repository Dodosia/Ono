#pragma once
#include "onopch.h"
#include "Core.h"

namespace Ono
{
	class ONO_API Layer
	{
	public:
		Layer(const std::string& name = "Layer"){}
		virtual ~Layer(){}

		virtual void Update() = 0;
		virtual void Attach() = 0;
		virtual void Detach() = 0;
	protected:
		std::string debug_name;
	};
}
