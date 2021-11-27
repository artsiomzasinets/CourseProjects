//
// Created by artom on 20.11.2021.
//

#ifndef COURSEPROJECT16_TEXTVIEW_H
#define COURSEPROJECT16_TEXTVIEW_H
#include <iostream>
#include "OwnString.h"

class TextView {
    OwnString str;
public:
    TextView(OwnString&&);
    ~TextView();
};


#endif //COURSEPROJECT16_TEXTVIEW_H
