#include "Ono.h"

class ExampleLayer : public Ono::Layer
{
public:
	ExampleLayer(const std::string& name) : Layer(name) {}
	~ExampleLayer() {}

	void Update() override
	{
		//std::cout << "ExampleLayer is running";
	}

	void Attach() override
	{

	}

	void Detach() override
	{

	}
};

class Game : public Ono::App
{
public:
	Game()
	{
		PushLayer(new ExampleLayer("Example Layer"));
	}
	~Game() {}
};

Ono::App* Ono::CreateApp()
{
	return new Game;
}