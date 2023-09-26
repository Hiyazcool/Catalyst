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
		_memccpy(stringArray, _charArray, sizeof(char), stringSize + 1);
	}
	void string::Set(char*&& _charArray) {
		if (stringArray != NULL)
			delete[] stringArray;
		stringSize = strlen(_charArray);
		memmove(stringArray, _charArray, sizeof(char));
	}
	void string::Set(string*&& _string) {
		if (stringArray != NULL)
			delete[] stringArray;
		stringSize = strlen(_string->GetArray());
		memmove(stringArray, _string->GetArray(), sizeof(char));
	}
	void string::Set(string* _string) {
		if (stringArray != NULL)
			delete[] stringArray;
		stringSize = strlen(_string->GetArray());
		_memccpy(stringArray, _string->GetArray(), sizeof(char), stringSize + 1);
	}
	void string::Set(string _string) {
		if (stringArray != NULL)
			delete[] stringArray;
		stringSize = strlen(_string());
		_memccpy(stringArray, _string(), sizeof(char), stringSize + 1);
	}
	void string::Set(string&& _string) {
		if (stringArray != NULL)
			delete[] stringArray;
		stringSize = strlen(_string());
		memmove(stringArray, _string(), sizeof(char));
	}
	string::string(const char* _charArray) :
		stringSize(strlen(_charArray)),
		stringArray(stringArray = new char[stringSize + 1]) {
		_memccpy(stringArray, _charArray, sizeof(char), stringSize + 1);
#ifdef DEBUG
		std::cout << "Created String";
#endif // DEBUG
	}
	string::string(const char*&& _charArray, bool isRef) :
		stringSize(strlen(_charArray)),
		stringArray(stringArray = new char[stringSize + 1]) {
		_memccpy(stringArray, _charArray, sizeof(char), stringSize + 1);
#ifdef DEBUG
		std::cout << "Created String";
#endif // DEBUG
	}
	string::string(string* _string) {

	}
	string::string(string& _string) {

	}
	string::~string() {
#ifdef DEBUG
		std::cout << "Deleted String";
#endif // DEBUG
		delete[] stringArray;
	}

}