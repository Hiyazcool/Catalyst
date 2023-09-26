#pragma once
#include<iostream>
namespace HiyazUtils {
	/*
		Operator Overloads
			=, +, +=, ==,!=, <, >, <=, >=

			String&& versions of Operators 
				check that it is not stealing other variables values unless intended
	*/
	class string {
	private:
	public:
		const char* operator()() const {
			return stringArray;
		}
		char* operator()() {
			return stringArray;
		}
		const char* GetArray();
		void Set(char* _charArray);
		void Set(char*&& _charArray);
		void Set(string*&& _string);
		void Set(string* _string);
		void Set(string _string);
		void Set(string&& _string);
	private:
		static char* Simplify(char* _value) {
			return _value;
		}
		static const char* Simplify(const char* _value) {
			return _value;
		}
		static char* Simplify(string* _value) {
			return (*_value)();
		}
		static char* Simplify(string _value) {
			return _value();
		}
		template<typename Src, typename...Rest>
		static void AddTo(int& _index, char* _dstString, Src _srcString, Rest..._rest) {
			for (int i = 0; i < strlen(Simplify(_srcString)); i++, _index++)
				_dstString[_index] = Simplify(_srcString)[i];
			AddTo(_index, _dstString, _rest...);
		}
		template<typename DstString>
		static void AddTo(int& _index, DstString _dstString) {
			_dstString[_index] = 0;
			return;
		}
		template<typename FirstString, typename... Rest>
		static size_t TotalStringSize(FirstString _firstString, Rest... _rest) {
			return(strlen(Simplify(_firstString)) + TotalStringSize(_rest...));
		}
		template<typename FirstString>
		static size_t TotalStringSize(FirstString _firstString) {
			return(strlen(Simplify(_firstString)));
		}
		template<typename...Args>
		static string* ConstructString(Args ... _args) {
#ifdef DEBUG
			std::cout << "Construct String";
#endif // DEBUG
			char* newArray = new char[TotalStringSize(_args...) + 1];
			int _index = 0;
			int& index = _index;
			AddTo(index, newArray, _args...);
			string* strPointer(new string(newArray));
			return strPointer;
		}
		template<typename...Args>
		static void ConstructString(string* _dstString, Args ... _args) {
#ifdef DEBUG
			std::cout << "Construct String w/ Source";
#endif // DEBUG
			char* newArray = new char[TotalStringSize(_args...) + 1];
			int _index = 0;
			int& index = _index;
			AddTo(index, newArray, _args...);
			if (_dstString == nullptr || _dstString == NULL)
				_dstString = new string(newArray);
			else
				_dstString->Set(newArray);
			return;

		}
		char* stringArray;
		size_t stringSize;
	public:
		string(const char* _charArray);
		string(const char*&& _charArray, bool isRef);
		template<typename T, typename Y, typename...Args>
		string(T _first, Y _second, Args... _args) :
			stringSize(TotalStringSize(_first, _args...)),
			stringArray(ConstructString(_first, _args...)) {
#ifdef DEBUG
			std::cout << "Created String";
#endif // DEBUG
		}
		string(string* _string);
		string(string& _string);
		~string();
		template<typename T>
		string* operator+(T _otherArray) {
			return ConstructString(stringArray, Simplify(_otherArray));
		}
		template<typename T>
		void operator+=(T _otherArray) {
			ConstructString(stringArray, _otherArray);
		}
		void operator=(char* _otherArray) {
			Set(_otherArray);
		}
		void operator=(char*&& _otherArray) {
			Set(_otherArray);
		}
		void operator=(string _otherArray) {
			Set(_otherArray);
		}
		void operator=(string* _otherArray) {
			Set(_otherArray);
		}
		void operator=(string&& _otherArray) {
			Set(_otherArray);
		}
	};
	std::ostream& operator<<(std::ostream& stream, const string& string) {
		stream << string();
		return stream;
	}
}
//#include "String.cpp"