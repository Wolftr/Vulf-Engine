#pragma once

#ifdef VULF_PLATFORM_WINDOWS
	#ifdef VULF_BUILD_DLL
		#define VULF_API __declspec(dllexport)
	#else
		#define VULF_API __declspec(dllimport)
	#endif
#else
	#error Vulf Engine is not supported on this platform!
#endif

#ifdef VULF_ENABLE_ASSERTS
	#define VULF_ASSERT(x, ...) { if(!(x)) { VULF_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define VULF_CORE_ASSERT(x, ...) { if(!(x)) { VULF_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define VULF_ASSERT(x, ...)
	#define VULF_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)