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
