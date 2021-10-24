#include<random>
#include"Vector.h"




int main() {
	
	Vector<int> obj1{ 1,3,4,-5,-5, 0,265,656,462,0,2 };
	std::cout << "doSomethingGood = ";
	obj1.doSomethingGood();
	obj1.show();
	obj1.changedNegativeElementsToSquare();
	std::cout << "changedNegativeElementsToSquare = ";
	obj1.show();
	Vector<int> obj2(obj1);
	srand(time(0));
	for (int i = 0; i < 25; ++i) {
		obj1.push_back(rand() % 100);
		obj2.push_back(rand() % 100);
	}
	obj1 = obj2;
	std::cout << "obj2 = "; obj2.show();
	obj2.combSort();
	std::cout << "obj2 = "; obj2.show();
	std::cout << "max = " << obj2.max() << std::endl << "min = " << obj2.min() << std::endl << "average = " << obj2.average() 
		<< std::endl;
	for (int i = 0; i < 15; ++i) {
		obj1.pop();
	}
	std::cout << "obj1 = "; obj1.show();
		


	

	return 0;
}