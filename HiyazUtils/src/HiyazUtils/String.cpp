#include "String.h"
#include <iostream>
#include "Format.h"
namespace HiyazUtils {
	
	const char* string::GetArray() {
		return stringArray;
	}
	void string::Set(char* _charArray) {
		if (stringArray != NULL)
			delete[] stringArray;
		stringSize = strlen(_charArray);
		stringArray = new char[stringSize + 1];
		_memccpy(stringArray, _charArray, sizeof(char), stringSize + 1);
	}
	void string::Set(char*&& _charArray) {
		if (stringArray != NULL)
			delete[] stringArray;
		stringSize = strlen(_charArray);
		stringArray = new char[stringSize + 1];
		memmove(stringArray, _charArray, sizeof(char));
	}
	void string::Set(string*&& _string) {
		if (stringArray != NULL)
			delete[] stringArray;
		stringSize = strlen(_string->GetArray());
		stringArray = new char[stringSize + 1];
		memmove(stringArray, _string->GetArray(), sizeof(char));
	}
	void string::Set(string* _string) {
		if (stringArray != NULL)
			delete[] stringArray;
		stringSize = strlen(_string->GetArray());
		stringArray = new char[stringSize + 1];
		_memccpy(stringArray, _string->GetArray(), sizeof(char), stringSize + 1);
	}
	void string::Set(string _string) {
		if (stringArray != NULL)
			delete[] stringArray;
		stringSize = strlen(_string());
		stringArray = new char[stringSize + 1];
		_memccpy(stringArray, _string(), sizeof(char), stringSize + 1);
	}
	void string::Set(string&& _string) {
		if (stringArray != NULL)
			delete[] stringArray;
		stringSize = strlen(_string());
		memmove(stringArray, _string(), sizeof(char));
	}
	string::string() :
		stringSize(0),
		stringArray(nullptr){
	}
	string::string(const char* _charArray) :
		stringSize(strlen(_charArray)),
		stringArray(nullptr) {
		stringArray = new char[stringSize + 1];
		_memccpy(stringArray, _charArray, sizeof(char), stringSize + 1);
#ifdef DEBUG
		std::cout << "Created String";
#endif // DEBUG
	}
	string::string(const char*&& _charArray, bool isRef) :
		stringSize(strlen(_charArray)),
		stringArray(nullptr) {
		stringArray = new char[stringSize + 1];
		_memccpy(stringArray, _charArray, sizeof(char), stringSize + 1);
#ifdef DEBUG
		std::cout << "Created String";
#endif // DEBUG
	}
	string::~string() {
		std::cout << "Deleted String " << stringArray << "\n";
		
		delete[] stringArray;
	}
	void string::Clear() {
		if (stringArray != NULL)
			delete[] stringArray;
		stringSize = 0;
	}
	bool const string::CompareStrings(const char* _arrayOne, const char* _arrayTwo) const {
		if (strlen(_arrayOne) != strlen(_arrayTwo))
			return false;
		for (int i = 0; i < strlen(_arrayOne); i++)
			if (_arrayOne[i] == _arrayTwo[i])
				continue;
			else
				return false;
		return true;
	}

}