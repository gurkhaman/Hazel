#pragma once

#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"

// Introduces a layer to the system

namespace Hazel
{
	class HAZEL_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach()
		{
		}

		virtual void OnDetach()
		{
		}

		virtual void OnUpdate()
		{
		}

		virtual void OnEvent(Event& e)
		{
		}

		virtual void OnImGuiRender()
		{
		}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}
