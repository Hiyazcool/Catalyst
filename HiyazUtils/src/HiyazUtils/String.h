#pragma once
#include<iostream>
namespace HiyazUtils {
	/*
			String&& versions of Operators ---- Later Time
				check that it is not stealing other variables values unless intended
	*/
	void Work() {
			}
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
		void Clear();
	private:
		bool const CompareStrings(const char* _arrayOne, const char* _arrayTwo) const;
		static const char* Simplify(char* _value) {
			return _value;
		}
		static const char* Simplify(const char* _value) {			
			return _value;
		}
		static const char* Simplify(string* _value) {
			return (*_value)();
		}
		static const char* Simplify(string& _value) {
			return _value();
		}
#pragma region AddTo
		template<typename...Rest>
		static void AddTo(int& _index, char* _dstString, const char* _srcString, Rest..._rest) {
			for (int i = 0; i < strlen(_srcString); i++, _index++)
				_dstString[_index] = _srcString[i];
			AddTo(_index, _dstString, _rest...);
		}
		template<typename...Rest>
		static void AddTo(int& _index, char* _dstString, char* _srcString, Rest..._rest) {
			for (int i = 0; i < strlen(_srcString); i++, _index++)
				_dstString[_index] = _srcString[i];
			AddTo(_index, _dstString, _rest...);
		}
		template<typename...Rest>
		static void AddTo(int& _index, char* _dstString, string _srcString, Rest..._rest) {
			for (int i = 0; i < strlen(_srcString()); i++, _index++)
				_dstString[_index] = _srcString()[i];
			AddTo(_index, _dstString, _rest...);
		}
		template<typename...Rest>
		static void AddTo(int& _index, char* _dstString, string* _srcString, Rest..._rest) {
			for (int i = 0; i < strlen((*_srcString)()); i++, _index++)
				_dstString[_index] = (*_srcString)()[i];
			AddTo(_index, _dstString, _rest...);
		}
		template<typename DstString>
		static void AddTo(int& _index, DstString _dstString) {
			_dstString[_index] = 0;
			return;
		}
#pragma endregion
#pragma region TotalStringSize
		template<typename... Rest>
		static int TotalStringSize(string _firstString, Rest... _rest) {
			return (strlen(_firstString()) + TotalStringSize(_rest...));
		}
		template<typename... Rest>
		static int TotalStringSize(string* _firstString, Rest... _rest) {
			return (strlen((*_firstString)()) + TotalStringSize(_rest...));
		}
		template<typename... Rest>
		static int TotalStringSize(char* _firstString, Rest... _rest) {
			return (strlen(_firstString) + TotalStringSize(_rest...));
		}
		template<typename... Rest>
		static int TotalStringSize(const char* _firstString, Rest... _rest) {
			return (strlen(_firstString) + TotalStringSize(_rest...));
		}
		static int TotalStringSize(string _firstString) {
			return (strlen(_firstString()));
		}
		static int TotalStringSize(string* _firstString) {
			return (strlen((*_firstString)()));
		}
		static int TotalStringSize(char* _firstString) {
			return (strlen(_firstString));
		}
		static int TotalStringSize(const char* _firstString) {
			return (strlen(_firstString));
		}
#pragma endregion
		template<typename...Args>
		static string* ConstructString(Args ... _args) {
			size_t size = TotalStringSize(_args...);
			char* newArray = new char[size + 1];
			int _index = 0;
			int& index = _index;
			AddTo(index, newArray, _args...);
			string* strPointer = new string(newArray);
			return strPointer;		
		}
		template<typename...Args>
		static void ConstructString(string* _dstString, Args ... _args) {
			char* newArray = new char[TotalStringSize(_args...) + 1];
			int _index = 0;
			int& index = _index;
			AddTo(index, newArray, _args...);
			if (_dstString == nullptr || _dstString == NULL)
				_dstString = new string(newArray);
			else
				_dstString->Set(newArray);
		}
		char* stringArray;
		size_t stringSize;
	public:
		string();
		string(const char* _charArray);
		string(const char*&& _charArray, bool isRef);
		template<typename T, typename Y, typename...Args>
		string(T _first, Y _second, Args... _args) :
			stringSize(TotalStringSize(_first, _args...)),
			stringArray(ConstructString(_first, _args...)) {
		}	
		~string();
		template<typename T>
		string* operator+(T& _otherArray) noexcept {	
			return ConstructString(stringArray, Simplify(_otherArray));
		}
		template<typename T>
		void operator+=(T _otherArray) {
			ConstructString(stringArray, _otherArray);
		}
		template<typename T>
		void operator=(T _otherArray) {
			Set(_otherArray);
		}
		template<typename T>
		bool operator<(T& _otherArray) const {
			return strlen(stringArray) < strlen(Simplify(_otherArray));
		}
		template<typename T>
		bool operator>(T& _otherArray) const {
			return strlen(stringArray) > strlen(Simplify(_otherArray));
		}
		template<typename T>
		bool operator<=(T& _otherArray) const {
			return strlen(stringArray) < strlen(Simplify(_otherArray)) + 1;
		}
		template<typename T>
		bool operator>=(T& _otherArray) const {
			return strlen(stringArray) + 1  > strlen(Simplify(_otherArray));
		}
		template<typename T>
		bool operator==(T& _otherArray) const {
			return CompareStrings(stringArray, Simplify(_otherArray));
		}
		template<typename T>
		bool operator!=(T& _otherArray) const {
			return CompareStrings(stringArray, Simplify(_otherArray));
		}
	};
	std::ostream& operator<<(std::ostream& stream, const string& string) {
		stream << string();
		return stream;
	}
}