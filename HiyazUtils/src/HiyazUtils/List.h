#pragma once
#include <iostream>
namespace HiyazUtils {
	template<typename T>
	class List
	{
		/* Todo:
		Iterator
		Delete certain index
		Emplace in certain index
		*/
	public:
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
		template<typename ... Args>
		T& EmplaceBack(Args&&... args) {
			if (dataSize > dataCapacity - 1)
				ReAlloc(dataCapacity + dataCapacity / 2);
			new(&dataArray[dataSize]) T(std::forward<Args>(args)...);
			return dataArray[dataSize++];
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