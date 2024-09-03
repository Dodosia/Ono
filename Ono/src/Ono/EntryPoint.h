#pragma once

#ifdef ONO_PLATFORM_WINDOWS

extern Ono::Application* Ono::CreateApplication();

int main(int argc, char** argv)
{
	Ono::Log::Init();

	Ono::Application* app = Ono::CreateApplication();
	app->Run();
	delete app;
}

#endif