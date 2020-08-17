#include "hzpch.h"
#include <Hazel.h>

class ExampleLayer : public Hazel::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if(Hazel::Input::IsKeyPressed(HZ_KEY_TAB))
			HZ_INFO("{0} key is pressed", HZ_KEY_TAB);
	}

	void OnEvent(Hazel::Event& e) override
	{
		// HZ_TRACE("{0}", e);
	}
};

class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Hazel::ImGuiLayer());
	}

	~Sandbox()
	{
	}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}
