//Создать объекты разработанных классов и проверить работу реализованных в них методов
//работник -> менеджер,организация,программист. методы(средняя зарплата)

#include<iostream>
#include <vector>
#include<algorithm>

#include "realizationOfClass/Administrator.h"
#include "realizationOfClass/Manager.h"
#include "realizationOfClass/Programer.h"

Period selectPeriod();

int main() {
    Administrator objAdm(9.8, "IOSEntertainment");
    Manager objMang(11.3, "ZefirProduction");
    Programer objProg(16.4, "ZapoliaNet");
    std::vector<WorkerOfCompany *> objArr;
    objArr.push_back(&objAdm);
    objArr.push_back(&objMang);
    objArr.push_back(&objProg);
    //------------------------------------------------------
    Period choice = selectPeriod();
    std::for_each(objArr.begin(), objArr.end(), [choice](WorkerOfCompany *elem) {
        std::cout << '\n' << elem->typeOfEmployee() << " salary in company " << elem->getNameOfCompany() << " = "
                  << elem->salaryForCertainPeriod(choice) << '$' << std::endl;;
    });
    //---------------------------------------------------------
    Period choiceOfPeriod = selectPeriod();
    double averageSalary = 0;
    std::for_each(objArr.begin(), objArr.end(), [&averageSalary, choiceOfPeriod](WorkerOfCompany *elem) {
        averageSalary += elem->salaryForCertainPeriod(choiceOfPeriod);//sum salary all employees
    });
    averageSalary /= objArr.size();
    std::cout << "Average salary is " << averageSalary << '$' << std::endl;
    return 0;
}


Period selectPeriod() {
    Period choiceOfPeriod;
    unsigned short choice;
    std::cout << "\nEnter period for calculating average salary:\n1-hour\n2-day\n3-mounth\n4-year" << std::endl
              << "Choice:";
    while (!(std::cin >> choice && choice >= 1 && choice <= 4)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong choice!\nEnter again:";
    }
    switch (choice) {
        case 1:
            choiceOfPeriod = Period::hour;
            break;
        case 2:
            choiceOfPeriod = Period::day;
            break;
        case 3:
            choiceOfPeriod = Period::mounth;
            break;
        case 4:
            choiceOfPeriod = Period::year;
            break;
    }
    return choiceOfPeriod;
}