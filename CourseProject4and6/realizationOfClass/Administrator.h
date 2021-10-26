//
// Created by artom on 24.10.2021.
//

#ifndef COURSEPROJECT4AND6_ADMINISTRATOR_H
#define COURSEPROJECT4AND6_ADMINISTRATOR_H
#include "../abstractClass/WorkerOfCompany.h"

class Administrator: public WorkerOfCompany{
private:
    const char* employeeType = "Administrator";
public:
    Administrator(double, const char*);//salaryPerHour, name of company
    const char *typeOfEmployee() override;
};


#endif //COURSEPROJECT4AND6_ADMINISTRATOR_H
