#pragma once
#include "String.h"
using namespace HiyazUtils;
namespace HiyazUtils { 
namespace Format {
	namespace StringConstants {
		constexpr char* Colon = ": ";
		constexpr char* Comma = ", ";
		constexpr char* NewLine = "\n";
	}
	template<typename Args&... args>
	static string& FormatIntoString(Args& ..._args);
	template<typename Args&... args>
	static void FormatString(string* _destination, Args& ..._args);
	template<typename Args&... args>
	static void FormatStringList(string* _destination, Args& ..._args);
	static void FillCharArray(char* _destination, char* _source);
	static void FillCharArray(char* _destination, char*&& _source); // rValue
	static void FillCharArray(char* _destination, string* _source);
	template<typename Args&... args>
	static size_t CalculatestringLength(char* _string, Args& ..._args);
	template<typename Args&... args>
	static size_t CalculatestringLength(string* _string, Args& ..._args);
	static size_t CalculatestringLength(char* _string);
	static size_t CalculatestringLength(string* _string);
}}
