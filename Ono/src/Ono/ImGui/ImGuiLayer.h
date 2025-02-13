#pragma once

#include "Ono/Core/Core.h"
#include "Ono/Core/Layer.h"

namespace Ono
{
	class ONO_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer(const std::string& name = "ImGuiLayer") {}
		virtual ~ImGuiLayer() {}

		void Update() override;
		void Attach() override;
		void Detach() override;
	protected:
		std::string debug_name;
	};
}