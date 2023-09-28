#pragma once
template<size_t Size,typename T>
class  Array {
	/* Todo :
	Iterator
	*/
public:
	constexpr int Size() const { return Size; }

	T& operator[](size_t index) { return dataArray[index]; }
	const T& operator[](size_t index) const { return dataArray[index]; }

	T* Data() { return dataArray; }
	const T* Data() const { return dataArray; }
private:
	T dataArray[Size];
};