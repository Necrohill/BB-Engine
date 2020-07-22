#pragma once

#ifdef BB_PLATFORM_WINDOWNS
	#ifdef BB_BUILD_DLL
		#define BBEngine_API __declspec(dllexport)
	#else
		#define BBEngine_API __declspec(dllimport)
	#endif // BB_BUILD_DLL
#else
	#error Only Windows Support
#endif // BB_PLATFORM_WINDOWNS

#define BIT(x) (1 << x)