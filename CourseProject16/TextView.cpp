//
// Created by artom on 20.11.2021.
//

#include "TextView.h"

TextView::TextView( OwnString && outObject) {
    std::cout << "TextView constructor" << std::endl;
    str = outObject;
}

TextView::~TextView() {
    std::cout << "Destracort" << std::endl;
}
