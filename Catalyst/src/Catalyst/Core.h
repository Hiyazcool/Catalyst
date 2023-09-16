#pragma once

#ifdef CATALYST_PLATFORM_WINDOWS
#ifdef CATALYST_BUILD_DLL
#define CATALYST_API __declspec(dllexport)
#else
#define CATALYST_API __declspec(dllimport)
#endif
#else
#error Catalyst Only Support Windows!
#endif 
