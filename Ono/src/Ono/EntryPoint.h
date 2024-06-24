#pragma once

#ifdef ON_PLATFORM_WINDOWS

extern Ono::Application* Ono::CreateApplication();

int main(int argc, char** argv)
{
	printf("Hello!");
	auto app = Ono::CreateApplication();
	app->Run();
	delete app;
}

#endif