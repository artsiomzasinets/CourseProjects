//Реализаци простых контейнеров
// Составить программу, которая содержит текущую информацию о заявках на авиабилеты. Каждая заявка включает:
// пункт назначения;
// номер рейса;
// фамилию и инициалы пассажира;
// желаемую дату вылета.
//Программа должна обеспечивать:
// хранение всех заявок в виде стека или очереди;
// добавление заявок в список;
// удаление заявок;
// вывод заявок по заданному номеру рейса и дате вылета;
// вывод всех заявок.



#include <iostream>
#include <string>
#include "Queue.h"

struct AirTicket {


    friend std::ostream &operator<<(std::ostream &os, AirTicket &outObj) {
        os << "Destination = " << outObj.destination << "\nNumber of flight = " << outObj.numberOfFlight
           << "\nSurname and name = " << outObj.SN << "\nFlight date(day/month) = " << outObj.day << "/" << outObj.month
           << std::endl;
        return os;
    }

    friend void operator>>(std::istream &in, AirTicket &outObj) {
        in.clear();
        in.ignore(1000, '\n');
        std::cout << "\nDestination(string) = ";
        std::getline(in, outObj.destination);
        std::cout << "Number of flight(number) = ";
        in >> outObj.numberOfFlight;
        in.ignore(100, '\n');
        std::cout << "Surname and name(string) = ";
        std::getline(in, outObj.SN);
        std::cout << "Flight date(day/month) = ";
        in >> outObj.day >> outObj.month;
        in.clear();
        in.ignore(1000, '\n');
    }


    std::string destination;
    unsigned short numberOfFlight;
    std::string SN;//surname and name;
    unsigned short day, month;


};


int main() {
    own::Queue<AirTicket> tickets;
    unsigned short choice;
    bool exit = true;
    while (exit) {// menu
        std::cout
                << "\n1-add ticket\n2-delete ticket\n3-print by number of flight\n4-print by fight date\n5-print all\n6-exit\nSelect:";
        while (!(std::cin >> choice && choice <= 6)) {
            std::cin.clear();
            std::cin.ignore(10, '\n');
            std::cout << "Choose again:";
        }

        AirTicket tempObj;
        switch (choice) {
            case 1:
                std::cin >> tempObj;
                tickets.push(std::move(tempObj));
                break;
            case 2:
                tickets.pop();
                std::cout << "ticket has been deleted from queue!" << std::endl;
                break;
            case 3:
                size_t choiceNumberOfFlight;
                std::cout << "Enter number of flight:";
                while (!(std::cin >> choiceNumberOfFlight)) {
                    std::cin.clear();
                    std::cin.ignore(10, '\n');
                    std::cout << "Enter again:";
                }
                std::cout << "\t\tPrint by number of flight\n";
                for (own::Queue<AirTicket>::iterator iter = tickets.front(); iter != tickets.back(); iter++) {
                    if ((*iter).numberOfFlight == choiceNumberOfFlight) {
                        std::cout << *iter << std::endl;
                    }
                }
                break;
            case 4:
                size_t choiceDayMonth[2];
                std::cout << "Enter fight date(day month):";
                while (!(std::cin >> choiceDayMonth[0] >> choiceDayMonth[1])) {
                    std::cin.clear();
                    std::cin.ignore(10, '\n');
                    std::cout << "Enter again:";
                }
                std::cout << "\t\tPrint by fight date\n";
                for (own::Queue<AirTicket>::iterator iter = tickets.front(); iter != tickets.back(); iter++) {
                    if ((*iter).day == choiceDayMonth[0] && (*iter).month == choiceDayMonth[1]) {
                        std::cout << *iter << std::endl;
                    }
                }
                break;
            case 5:
                std::cout << "\t\tPrint all\n";
                for (own::Queue<AirTicket>::iterator iter = tickets.front(); iter != tickets.back(); iter++) {
                    std::cout << *iter << std::endl;
                }
                break;
            case 6:
                exit = false;
                break;
        }
    }


    return 0;
}
