#pragma once

#include "Ono/Layer.h"

namespace Ono
{
	class ONO_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();

	private:
		float m_Time = 0.0f;
	};
}