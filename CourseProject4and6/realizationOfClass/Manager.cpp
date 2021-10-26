//
// Created by artom on 24.10.2021.
//

#include "Manager.h"

Manager::Manager(double salaryH, const char * nameComp) {
    salaryPerHour = salaryH;
    nameOfCompany = nameComp;
}

const char *Manager::typeOfEmployee() {
    return employeeType;
}
