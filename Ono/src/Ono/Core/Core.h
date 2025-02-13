#pragma once
#include <iostream>

#ifdef ONO_BUILD_DLL
	#define ONO_API __declspec(dllexport)
#else
	#define ONO_API __declspec(dllimport)
#endif