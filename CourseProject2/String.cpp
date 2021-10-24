#include "String.h"


void String::getOrCheckMemory(const size_t outSize) {
	if (p_str == nullptr) {
		p_str = new char[outSize];
		p_sizeOfStr = outSize;
	}
	else if(p_sizeOfStr == outSize)
	{
		return;
	}
	else
	{
		delete[] p_str;
		p_str = new char[outSize];
		p_sizeOfStr = outSize;
	}
}

size_t String::findOutSize(const char* outStr) {
	size_t counter = 0;
	while (outStr[counter] != '\0')
	{
		++counter;
	}
	return counter; 
}


String::String(): p_str(nullptr), p_sizeOfStr(0)
{
	std::cout << "constructo " << std::endl;
}

String::String(const char* outStr)
{
	size_t sizeOfoutStr = findOutSize(outStr);
	getOrCheckMemory(sizeOfoutStr);
	for (size_t i = 0; i < sizeOfoutStr; ++i) {
		p_str[i] = outStr[i];
	}
	std::cout << "constructo with param" << std::endl;
}

String::String(const String& outObject)
{
	getOrCheckMemory(outObject.p_sizeOfStr);
	for (size_t i = 0; i < findOutSize(outObject.p_str); ++i) { // check function, because '\0'?
		p_str[i] = outObject.p_str[i];
	}
	std::cout << "constructo copy" << std::endl;
}

String::~String()
{
	delete[] p_str;
	p_sizeOfStr = 0;
	std::cout << "deconstruct" << std::endl;
}

String& String::operator=(const String& outObject)
{
	if (this == &outObject) {
		return *this;
	}

	getOrCheckMemory(outObject.p_sizeOfStr);
	for (size_t i = 0; i < p_sizeOfStr; ++i) {
		p_str[i] = outObject.p_str[i];
	}
	return *this;
}

String& String::operator=(const char* outStr)
{
	size_t sizeOfoutStr = findOutSize(outStr);
	getOrCheckMemory(sizeOfoutStr);
	for (size_t i = 0; i < p_sizeOfStr; ++i) {
		p_str[i] = outStr[i];
	}
	return *this;
}


std::ostream& operator<<(std::ostream& os, String& obj)
{
	for (size_t i = 0; i < obj.p_sizeOfStr; ++i) {
		os << obj.p_str[i];
	}

	return os;
}



void String::countLastSymbol()
{
	char theSymbol;
	size_t temp = 1;
	while (!isalpha(p_str[p_sizeOfStr - temp]))// finding last symbol
	{
		++temp;
	}
	theSymbol = p_str[p_sizeOfStr - temp];

	size_t amountTheSymbol = 0;
	for (size_t i = 0; i < p_sizeOfStr; ++i) {
		if (theSymbol == p_str[i]) {//counting theSymbol
			amountTheSymbol++;
		}
		if (p_str[i] == ' ') {//replacing a space to theSymbol
			p_str[i] = theSymbol;
		}
	}

}


