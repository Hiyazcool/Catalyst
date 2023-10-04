#pragma once
#include <string>
#include <iostream>
#include "Format.h"
namespace HiyazUtils {
namespace Print {
	class IPrintable {  // Seperate Into Seperate File So Format and Prin Can use it without conflicting with eachother
			virtual const char* const PrintInfo() = 0;
		public: 
			operator const char*() const { return PrintInfo; }
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
