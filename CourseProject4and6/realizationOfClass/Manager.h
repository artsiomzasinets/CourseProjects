//
// Created by artom on 24.10.2021.
//

#ifndef COURSEPROJECT4AND6_MANAGER_H
#define COURSEPROJECT4AND6_MANAGER_H
#include "../abstractClass/WorkerOfCompany.h"

class Manager: public WorkerOfCompany {
private:
    const char* employeeType = "Manager";
public:
    Manager(double, const char*);//salaryPerHour, name of company
    const char *typeOfEmployee() override;
};


#endif //COURSEPROJECT4AND6_MANAGER_H
