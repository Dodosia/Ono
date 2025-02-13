#pragma once
#include "onopch.h"

extern Ono::App* Ono::CreateApp();

int main()
{
	Ono::App* app = Ono::CreateApp();
	app->Run();
	delete app;
}