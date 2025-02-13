#include "onopch.h"
#include "LayerStack.h"

namespace Ono
{
	LayerStack::LayerStack()
	{
		layer_insert = layers.begin();
	}

	LayerStack::~LayerStack()
	{
		Cleanup();
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		layer_insert = layers.emplace(layer_insert, layer);
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(layers.begin(), layers.end(), layer);
		if (it != layers.end())
		{
			layers.erase(it);
			layer_insert--;
		}
	}

	void LayerStack::PopOverLay(Layer* overlay)
	{
		auto it = std::find(layers.begin(), layers.end(), overlay);
		if (it != layers.end())
		{
			layers.erase(it);
		}
	}

	void LayerStack::Cleanup()
	{
		for (Layer* layer : layers)
		{
			delete layer;
		}
	}
}
