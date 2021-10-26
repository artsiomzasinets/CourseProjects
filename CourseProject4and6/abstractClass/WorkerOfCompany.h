//
// Created by artom on 24.10.2021.
//

#ifndef COURSEPROJECT4AND6_WORKEROFCOMPANY_H
#define COURSEPROJECT4AND6_WORKEROFCOMPANY_H
#include <chrono>

#include "../interface/ICompany.h"
#include "../interface/IEmployee.h"

enum Period{
    hour,
    day,
    mounth,
    year
};

class WorkerOfCompany: public IEmployee, public ICompany{
protected:
    double salaryPerHour;
    const char* nameOfCompany;
public:
    double getSalaryPerHour() override;
    void setSalaryPerHour(double) override;

    const char* getNameOfCompany() override;
    void setNameOfCompany(const char*) override;


    double salaryForCertainPeriod(Period);
public:
    virtual const char* typeOfEmployee() = 0;
};


#endif //COURSEPROJECT4AND6_WORKEROFCOMPANY_H
