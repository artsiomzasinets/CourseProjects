//
// Created by artom on 24.10.2021.
//

#ifndef COURSEPROJECT4AND6_PROGRAMER_H
#define COURSEPROJECT4AND6_PROGRAMER_H
#include "../abstractClass/WorkerOfCompany.h"

class Programer: public WorkerOfCompany {
private:
    const char* employeeType = "Programmer";
public:
    Programer(double, const char*);//salaryPerHour, name of company
    const char *typeOfEmployee() override;
};


#endif //COURSEPROJECT4AND6_PROGRAMER_H
