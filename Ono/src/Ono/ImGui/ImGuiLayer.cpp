#include "onopch.h"
#include "ImGuiLayer.h"
#include "imgui.h"

namespace Ono
{
	void ImGuiLayer::Update()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();

		ImGui::StyleColorsDark();
	}

	void ImGuiLayer::Attach()
	{

	}

	void ImGuiLayer::Detach()
	{

	}
}

