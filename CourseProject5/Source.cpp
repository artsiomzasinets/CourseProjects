#include<iostream>
#include<random>
#include<ctime>

#include"Array.h"

int main() {
	srand(time(0));
	size_t size = 5;
	int** arr = new int* [size];
	for (size_t i = 0; i < size; ++i) {
		arr[i] = new int[size];
		for (size_t j = 0; j < size; ++j) {
			arr[i][j] = rand() % 10;
		}
	}


	Array<int> obj(arr,size, size);
	obj.show();
	std::cout << task(obj);//friend object
	Array<int> obj1(obj);
	Array<int> obj2;
	obj2 = obj;
	
	return 0;
}