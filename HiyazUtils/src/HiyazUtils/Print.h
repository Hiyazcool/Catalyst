#pragma once
#include <string>
#include <iostream>
#include "Format.h"
namespace HiyazUtils {
namespace Print {
	class IPrintable {  // Seperate Into Seperate File So Format and Print Can use it without conflicting with eachother
		public: 
			// Used to Display All Relevent Info for Debugging Purposes Default Overloaded to Print with Implicit Cast to Char*
			virtual const char* const PrintDebugInfo() = NULL; 
			// Operator Overload Simple as that
			operator const char*() const { return PrintDebugInfo(); }
			// Used to Display Critical Info, that Would Pertain to Testing
			virtual const char* const ToString() = NULL;
	};
	template<typename Args&...args>
	inline const static void const Print(Args& ..._args) {
		Print(FormatString(_args));
	}
	inline const static void const Print(const char* _pointer);
	inline const static void const Print(const std::string _pointer);
	inline const static void const Print(const string* _pointer);
	inline const static void const Print(const IPrintable* _pointer);

	template<typename T, typename Args&...args>
	inline const static void const PrintL(bool _isSeperateLines = True, T _string, Args& ..._args) {
		if (_isSeperateLines) 
			Print(FormatIntoStringList(_string, _args));
		else
			PrintL(FormatString(_string, _args));
	}
	inline const static void const PrintL(const char* _pointer);
	inline const static void const PrintL(const std::string _pointer);
	inline const static void const PrintL(const string* _pointer);
	inline const static void const PrintL(const IPrintable* _pointer);
}}
