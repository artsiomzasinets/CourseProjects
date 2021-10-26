//
// Created by artom on 24.10.2021.
//

#include "WorkerOfCompany.h"

double WorkerOfCompany::getSalaryPerHour() {
    return salaryPerHour;
}

void WorkerOfCompany::setSalaryPerHour(double salary) {
    salaryPerHour = salary;
}

const char* WorkerOfCompany::getNameOfCompany() {
    return nameOfCompany;
}

void WorkerOfCompany::setNameOfCompany(const char * name) {
    nameOfCompany = name;
}

double WorkerOfCompany::salaryForCertainPeriod(Period period) {
    double result;
    switch (period) {
        case Period::hour:result = salaryPerHour; break;
        case Period::day: result = salaryPerHour * 8; break;
        case Period::mounth:result = salaryPerHour * 8 * 22; break;
        case Period::year:result = salaryPerHour * 8 * 22 * 12;break;
    }
    return result;
}
