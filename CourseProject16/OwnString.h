//
// Created by artom on 20.11.2021.
//

#ifndef COURSEPROJECT16_OWNSTRING_H
#define COURSEPROJECT16_OWNSTRING_H
#include <iostream>

typedef unsigned int ui;

class OwnString {
public:
    OwnString();
    OwnString(char*, ui);
    OwnString(const OwnString&);
    OwnString(OwnString&&) noexcept;
    OwnString& operator=(const OwnString&);
    OwnString& operator=(OwnString&&) noexcept;
    ~OwnString();

private:
    char* str;
    ui sizeOfStr;
};


#endif //COURSEPROJECT16_OWNSTRING_H
