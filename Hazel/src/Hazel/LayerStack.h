#pragma once

#include "Hazel/Core.h"
#include "Layer.h"

#include <vector>

/* Basically a way to manage layers with ways to add or remove layers or overlays
 * Layers are stored in a vector containing pointers to the Layers
 */

namespace Hazel
{
	class HAZEL_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
		unsigned int m_LayerInsertIndex = 0; // index starts at 0
	};
}