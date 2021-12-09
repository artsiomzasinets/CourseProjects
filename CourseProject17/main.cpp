#include <iostream>
#include <vector>
#include "SharedPtr.h"

class test{
public:
    test(){
        std::cout << "constrycotrTEST" << std::endl;
    }
    ~test(){
        std::cout << "destrycotroTEST" << std::endl;
    }
};

int main() {//SmartPointer
    test *a = new test;
    ownPtr<test> ptr(a);
    ownPtr<test> ptr2(ptr);
    ownPtr<test> ptr3;
    ptr3 = ptr;


    return 0;
}
