#pragma once
#include <iostream>
#include <iterator>
#include "IPrintable.h"
#include "Define.h"
namespace HiyazUtils {
	/*
		Todo:
			Dedicated Search Function
			Remove Function
				Via Index or Search
			Add At Place Function
				Via Index
				Or In Front
			Shift Array Left Or Right
				Maybe do Via offset index variable????
					reduce lag of manually moving variables
					Would need Bounds checking
					Temporary index shift while Async creates new???
						Could be Fun
			Comparison
				Between list
					Return Instances of Same obj / seperate for same types
				num of Items
			Scramble
				Create a Second Array of Indexs Temp then Async them into another??
					Check if index is null if true go to new location to provide easier access?
						Lock ones being used on Main
			ToString Function
				A TryToString to all obj in list

			Add a Free Index Array?


			Make a Queue Object
	
	*/
	template<typename T>
	class ListIterator {
	public:
		using ValueType = T::ValueType;
		using PointerType = ValueType*;
		using ReferenceType = ValueType&;
		ListIterator(PointerType _ptr) :
			ptr(_ptr) {
		}
		ListIterator& operator++() {
			ptr++;
			return *this;
		}
		ListIterator operator++(int) {
			ListIterator iterator = *this;
			++(*this);
			return iterator;
		}
		ListIterator& operator--() {
			ptr--;
			return *this;
		}
		ListIterator operator--(int) {
			ListIterator iterator = *this;
			--(*this);
			return iterator;
		}
		ReferenceType operator[](int _index) {
			return *(ptr + _index);
		}
		PointerType operator->() {
			return ptr;
		}
		ReferenceType operator*() {
			return *ptr;
		}
		bool operator==(const ListIterator& other) const {
			return ptr != other.ptr;
		}
		bool operator!=(const ListIterator& other) const {
			return !(*this == other);
		}
	private:
		PointerType ptr;
	};
	template<typename T>
	class List : IPrintable
	{
		virtual const char* PrintDebugInfo() {
			return "Not Implemented Yet";
		}
		operator const char* () { return PrintDebugInfo(); }
		virtual const char* const ToString() {
			return "Not Implemented Yet";
		}
	public:
		using ValueType = T;
		using Iterator = ListIterator<List<T>>;
		List() {

			ReAlloc(5);
		}
		~List() {
			Clear();
			::operator delete(dataArray, dataCapacity * sizeof(T));
		}
		void PushBack(const T& value) {
			if (dataSize > dataCapacity - 1)
				ReAlloc(dataCapacity + dataCapacity / 2);
			dataArray[dataSize] = value;
			dataSize++;
		}
		void PushBack(T&& value) {
			if (dataSize > dataCapacity - 1)
				ReAlloc(dataCapacity + dataCapacity / 2);
			dataArray[dataSize] = std::move(value);
			dataSize++;
		}
		void Popback() {
			if (dataSize > 0) {
				dataSize--;
				dataArray[dataSize].~T();
			}
		}
		void Clear()
		{
			for (size_t i = 0; i < dataSize; i++)
				dataArray[i].~T();
			dataSize = 0;
		}
		T& operator[](size_t index) {
			if (index > dataSize + 1) {

			}
			return dataArray[index];
		}
		const T& operator[](size_t index) const {
			if (index > dataSize + 1) {

			}
			return dataArray[index];
		}
		size_t const GetSize() const { return dataSize; }
		size_t GetSize() { return dataSize; }
		template<typename ... Args>
		T& EmplaceBack(Args&&... args) {
			if (dataSize > dataCapacity - 1)
				ReAlloc(dataCapacity + dataCapacity / 2);
			new(&dataArray[dataSize]) T(std::forward<Args>(args)...);
			return dataArray[dataSize++];
		}
		uint AddWithIndex(T& _value) {
			if (dataSize > dataCapacity - 1)
				ReAlloc(dataCapacity + dataCapacity / 2);
			dataArray[dataSize] = _value;
			return dataSize++;
		}
		template<typename ComparisonType>
		bool operator==(ComparisonType _other) {
			if (typeid(ValueType) == typeid(ComparisonType))
				return true;
			return false;
		}
		template<typename ComparisonType>
		bool operator!=(ComparisonType _other) {
			if (typeid(ValueType) == typeid(ComparisonType))
				return false;
			return true;
		}
		
		void operator+=(auto _other) {
			EmplaceBack(_other);
		}
		
		void operator-=(T _other) {
			
		}
		void operator-=(uint _other) {
			if (_other < dataSize && _other > -1)
				dataArray[_other] = NULL;
		}
		Iterator begin() {
			return Iterator(dataArray);
		}
		Iterator end() {
			return Iterator(dataArray + dataSize);
		}
	private:
		void ReAlloc(size_t _capacity) {


			T* newBlock = (T*)::operator new(_capacity * sizeof(T));

			if (_capacity < dataSize)
				dataSize = _capacity;

			for (size_t i = 0; i < dataSize; i++)
				newBlock[i] = std::move(dataArray[i]);
			//for (size_t i = 0; i < dataSize; i++)
			//	dataArray[i].~T();
			::operator delete(dataArray, dataCapacity * sizeof(T));
			dataArray = newBlock;
			dataCapacity = _capacity;
		}
		T* dataArray = nullptr;
		size_t dataSize = 0;
		size_t dataCapacity = 0;
	};
}