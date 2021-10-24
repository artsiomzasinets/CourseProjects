#include<iostream>
#include"String.h"



int main() {

	String obj;
	String obj1 = "hello";
	String obj2 = "it's me";
	obj2 = "hello it's m e ";
	obj1 = obj2; 
	std::cout << obj1 << std::endl;
	obj1.countLastSymbol();
	std::cout << obj1 << std::endl;

	
	
	return 0;
}