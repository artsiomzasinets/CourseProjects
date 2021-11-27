#pragma once
#include<iostream>

template<class T>
class Array
{
private:
	T** arr;// arr[sizeOfHeight][sizeOfWidth]
	size_t sizeOfHeight;
	size_t sizeOfWidth;
private:

	void deleteMemory() {
		for (size_t i = 0; i < sizeOfHeight; ++i) {
			delete[] arr[i];
		}
		delete[]  arr;
	}


	void giveNewMemory(size_t outSizeOfHeight, size_t outSizeOfWidth) {
		if (arr != nullptr)
		{
			deleteMemory();
		}
		sizeOfHeight = outSizeOfHeight;
		sizeOfWidth = outSizeOfWidth;
		arr = new T* [sizeOfHeight];
		for (size_t i = 0; i < sizeOfHeight; ++i) {
			arr[i] = new T[sizeOfWidth];
		}
	}

	void copyFromOutObject(T** outArr) {
		for (size_t i = 0; i < sizeOfHeight; ++i) {
			for (size_t j = 0; j < sizeOfWidth; ++j) {
				arr[i][j] = outArr[i][j];
			}
		}
	}
public:
	Array():arr(nullptr), sizeOfHeight(0), sizeOfWidth(0) {
		std::cout << "\nDefault constructor" << std::endl;
	}

	Array(T** outArr, size_t outSizeOfHeight, size_t outSizeOfWidth) {
		std::cout << "\nconstructor with param" << std::endl;
		giveNewMemory(outSizeOfHeight, outSizeOfWidth);
		copyFromOutObject(outArr);
		
	}

	Array(const Array& outObject) {
		std::cout << "\ncopy constructor" << std::endl;
		if (outObject.arr== nullptr) {
			arr = nullptr;
			sizeOfHeight = 0;
			sizeOfWidth = 0;
		}
		
			giveNewMemory(outObject.sizeOfHeight, outObject.sizeOfWidth);
			copyFromOutObject(outObject.arr);
		
		
	}


	Array& operator=(const  Array& outObject) {
		std::cout << "\ncopy operator" << std::endl;
		if (outObject.arr == nullptr) {
			arr = nullptr;
			sizeOfHeight = 0;
			sizeOfWidth = 0;
		}
		
			giveNewMemory(outObject.sizeOfHeight, outObject.sizeOfWidth);
			copyFromOutObject(outObject.arr);
		
		return *this;
	}

	~Array() {
		std::cout << "\nDestructor" << std::endl;
		deleteMemory();
	}


	void show() {
		for (size_t i = 0; i < sizeOfHeight; ++i) {
			for (size_t j = 0; j < sizeOfWidth; ++j) {
				std::cout << arr[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}


	friend unsigned short task(Array& obj) { //2 Определить количество строк, содержащих хотя бы один нулевой элемент
		unsigned short counter = 0;
		bool isZero;
		for (size_t i = 0; i < obj.sizeOfHeight; ++i) {
			isZero = false;
			for (size_t j = 0; j < obj.sizeOfWidth; ++j) {
				if (obj.arr[i][j] == 0) {
					isZero = true;
				}
			}
			if (isZero) {
				counter++;
			}
		}
		return counter;
	}

};

