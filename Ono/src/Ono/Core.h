#pragma once

#ifdef ONO_PLATFORM_WINDOWS
	#ifdef ONO_BUILD_DLL
		#define ONO_API __declspec(dllexport)
	#else
		#define ONO_API __declspec(dllimport)
	#endif
#else
	#error Ono only support Windows!
#endif