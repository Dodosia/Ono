#include <Ono.h>

class ExampleLayer : public Ono::Layer
{
public:
	ExampleLayer() : Layer("Example")
	{

	}

	void OnUpdate() override
	{
		//ONO_INFO("ExampleLayer::Update");
	}
};

class Sandbox : public Ono::Application
{
public:

	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Ono::ImGuiLayer());
	}

	virtual ~Sandbox()
	{

	}
};

Ono::Application* Ono::CreateApplication()
{
	return new Sandbox();
}