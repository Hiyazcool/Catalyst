#pragma once
#include <string>
#include <iostream>
#include "Format.h"
namespace HiyazUtils {
namespace Print {
	class IPrintable {
		public:
			virtual char* PrintInfo() = 0;
	};
	template<typename Args&...args>
	inline const static void const Print(Args& ..._args) {
		Print(FormatString(_args));
	}
	inline const static void const Print(const char* _pointer);
	inline const static void const Print(const std::string _pointer);
	inline const static void const Print(const string* _pointer);
	inline const static void const Print(const IPrintable _pointer);

	template<typename T, typename Args&...args>
	inline const static void const PrintL(bool _isSeperateLines = True, T _string, Args& ..._args) {
		if (_isSeperateLines) 
			Print(FormatStringList(_string, _args));
		else
			PrintL(FormatString(_string, _args));
	}
	inline const static void const PrintL(const char* _pointer);
	inline const static void const PrintL(const std::string _pointer);
	inline const static void const PrintL(const string* _pointer);
	inline const static void const PrintL(const IPrintable _pointer);
}}
