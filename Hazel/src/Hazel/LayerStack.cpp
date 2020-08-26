#include "hzpch.h"
#include "LayerStack.h"

/*
 *  Contains the functions for layer management
 *  We use an index mainly m_LayerInsertIndex to navigate
 *  ourselves through the vector containing Layer pointers.
 */

namespace Hazel
{
	LayerStack::LayerStack()
	{
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
			delete layer;
	}

	
	void LayerStack::PushLayer(Layer* layer) // inserts layer, increases the index by one
	{
		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
		m_LayerInsertIndex++;
	}

	void LayerStack::PushOverlay(Layer* overlay) // adds overlay all the way at the back
	{
		m_Layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer* layer) // finds the specific layer and erases it, also reduces the index
	{
		auto const it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			m_LayerInsertIndex--;
		}
	}
	
	void LayerStack::PopOverlay(Layer* overlay) // finds the specific overlay and erases it
	{
		auto const it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
			m_Layers.erase(it);
	}
}
