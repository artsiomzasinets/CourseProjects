//
// Created by artom on 20.11.2021.
//

#include "OwnString.h"

OwnString::OwnString():str(nullptr), sizeOfStr(0) {
    std::cout << "Default constructor" << std::endl;
}

OwnString::OwnString(char *outStr, ui outSize):str(outStr),sizeOfStr(outSize) {
    std::cout << "constructor with parameters" << std::endl;
}

OwnString::OwnString(const OwnString & outObject) {
    std::cout << "Copy constructor" << std::endl;
    sizeOfStr = outObject.sizeOfStr;
    str = new char[sizeOfStr];
    for(ui i = 0; i < sizeOfStr; i++){
        str[i] = outObject.str[i];
    }
}

OwnString::OwnString(OwnString && outObject) noexcept{
    std::cout << "Move constructor" << std::endl;
    str = outObject.str;
    sizeOfStr = outObject.sizeOfStr;
    outObject.str = nullptr;
    outObject.sizeOfStr = 0;
}

OwnString& OwnString::operator=(const OwnString & outObject) {
    std::cout << "Copy operator " << std::endl;
    delete[] str;
    sizeOfStr = 0;
    sizeOfStr = outObject.sizeOfStr;
    str = new char[sizeOfStr];
    for(ui i = 0; i < sizeOfStr; i++){
        str[i] = outObject.str[i];
    }
    return *this;
}

OwnString &OwnString::operator=(OwnString && outObject) noexcept {
    std::cout << "Move operator" << std::endl;
    delete[] str;
    str = outObject.str;
    sizeOfStr = outObject.sizeOfStr;
    outObject.str = nullptr;
    outObject.sizeOfStr = 0;
}

OwnString::~OwnString() {
    std::cout << "Destracotor" << std::endl;
    delete[] str;
}
