#pragma once
#include "onopch.h"
#include "Core.h"
#include "Layer.h"

namespace Ono
{
	class ONO_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		void PopLayer(Layer* layer);
		void PopOverLay(Layer* layer);

		std::vector<Layer*>::iterator begin() { return layers.begin(); }
		std::vector<Layer*>::iterator end() { return layers.end(); }
	private:
		void Cleanup();

		std::vector<Layer*> layers;
		std::vector<Layer*>::iterator layer_insert;
	};
}
