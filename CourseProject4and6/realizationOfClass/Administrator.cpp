//
// Created by artom on 24.10.2021.
//

#include "Administrator.h"

const char *Administrator::typeOfEmployee() {
    return employeeType;
}

Administrator::Administrator(double salaryH, const char * nameComp) {
    salaryPerHour = salaryH;
    nameOfCompany = nameComp;
}


