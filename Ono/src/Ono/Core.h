#pragma once

#ifdef ON_PLATFORM_WINDOWS
	#ifdef ON_BUILD_DLL
		#define ONO_API __declspec(dllexport)
	#else
		#define ONO_API __declspec(dllimport)
	#endif
#else
	#error Ono only support Windows!
#endif