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

#ifdef ONO_ENABLE_ASSERTS
	#define ONO_ASSERT(x, ...) { if(!(x)) { ONO_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ONO_CORE_ASSERT(x, ...) { if(!(x)) { ONO_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ONO_ASSERT(x, ...)
	#define ONO_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)