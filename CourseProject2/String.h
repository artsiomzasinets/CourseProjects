#pragma once
#include<iostream>
class String
{
private:
	char* p_str;
	size_t p_sizeOfStr;
private:
	void getOrCheckMemory(const size_t);
	size_t findOutSize(const char*);
public:
	String();
	String(const char*);
	String(const String&);
	~String();

	String& operator=(const String&);
	String& operator=(const char*);
	friend std::ostream& operator<<(std::ostream&, String&);

	void countLastSymbol();//variant 8


};

