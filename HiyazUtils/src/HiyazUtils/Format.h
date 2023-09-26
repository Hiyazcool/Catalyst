#pragma once
using namespace HiyazUtils;
#include "String.h"
namespace HiyazUtils {
class Format {
	char* Simplify(char* _value) {
		return _value;
	}
	const char* Simplify(const char* _value) {
		return _value;
	}
	char* Simplify(string* _value) {
		return (*_value)();
	}
	char* Simplify(string _value) {
		return _value();
	}
	template<typename Src, typename...Rest>
	static void AddTo(int& _index, char* _dstString, Src _srcString, Rest..._rest) {
		for (int i = 0; i < strlen(_srcString); i++, _index++)
			_dstString[_index] = _srcString[i];
		AddTo(_index, _dstString, _rest...);
	}
	template<typename Src, typename...Rest>
	static void AddTo(int& _index, char* _dstString, Src&& _srcString, Rest..._rest) {
		for (int i = 0; i < strlen(_srcString); i++, _index++)
			_dstString[_index] = _srcString[i];
		AddTo(_index, _dstString, _rest...);
	}
	template<typename DstString>
	static void AddTo(int& _index, DstString _dstString) {
		_dstString[_index] = 0;
		return;
	}
public:
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
		AddTo(index, newArray,_args...);
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
};


}