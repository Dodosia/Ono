#include <Ono.h>

class Sandbox : public Ono::Application
{
public:

	Sandbox()
	{

	}

	virtual ~Sandbox()
	{

	}
};

Ono::Application* Ono::CreateApplication()
{
	return new Sandbox();
}