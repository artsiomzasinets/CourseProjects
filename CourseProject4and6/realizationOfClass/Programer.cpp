//
// Created by artom on 24.10.2021.
//

#include "Programer.h"

Programer::Programer(double salaryH, const char *nameComp) {
    salaryPerHour = salaryH;
    nameOfCompany = nameComp;
}

const char *Programer::typeOfEmployee() {
    return employeeType;
}
