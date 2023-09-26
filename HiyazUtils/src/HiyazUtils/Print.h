#pragma once
#include <string>
#include <iostream>
class IPrintable {
	public:
		virtual char* PrintInfo() = 0;
};

	static void Print(char* _string) {
		std::cout << _string;
	}
	static void Print(IPrintable* _printable) {
		Print((char*)_printable->PrintInfo());
	}
	static void Print(std::string _string) {
		std::cout << _string;
	}
	template<typename T>
	static void Print(T _type) {
		std::cout << _type;
	}
	template<typename First,typename...Args>
	static void Print(First first, Args ...args) {
		print(first);
		Print(args...);
	}
	static void PrintL(char* _string) {
		std::cout << _string << "\n";
	}
	static void PrintL(IPrintable* _printable) {
		PrintL((char*)_printable->PrintInfo());
	}
	static void PrintL(std::string _string) {
		std::cout << _string << "\n";
	}
	template<typename T>
	static void PrintL(T _type) {
		std::cout << _type << "\n";
	}
	template<typename First, typename...Args>
	static void PrintL(First first, Args ...args) {
		PrintL(first);
		PrintL(args...);
	}
	static void PrintC(char* _string) {
		std::cout << _string << ", ";
	}
	static void PrintC(IPrintable* _printable) {
		PrintC((char*)_printable->PrintInfo());
	}
	static void PrintC(std::string _string) {
		std::cout << _string << ", ";
	}
	template<typename T>
	static void PrintC(T _type) {
		std::cout << _type << ", ";
	}
	template<typename First, typename...Args>
	static void PrintC(First first,Args ...args) {
		PrintC(first);
		PrintC(args...);			
	};

