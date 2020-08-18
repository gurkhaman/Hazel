#include "hzpch.h"
#include <Hazel.h>

#include "imgui/imgui.h"

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

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello nice");
		ImGui::End();
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
	}

	~Sandbox()
	{
	}
};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}
