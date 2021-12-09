

#include"Currnecy.h"
#include <vector>
#include <algorithm>


int main() {
    std::vector<std::string> typeOfMoney;
    typeOfMoney.emplace_back("USD");
    typeOfMoney.emplace_back("EUR");
    typeOfMoney.emplace_back("RUB");
    typeOfMoney.emplace_back("PLN");




    size_t amountOfMoneyBYR;
    std::cout << "how much of valuta do you have in BYR?\nEnter:";
    while (!(std::cin >> amountOfMoneyBYR)) {
        std::cin.clear();
        std::cin.ignore(10, '\n');
        std::cout << "Enter again pls:";
    }
    Currency<BYR> objByr(amountOfMoneyBYR);

    unsigned short  choiceOfValuta;


    std::cout << "1-UDS\n2-EUR\n3-Convert in all\nEnter:";
    while (!(std::cin >> choiceOfValuta && choiceOfValuta >= 1 && choiceOfValuta <= 3)) {
        std::cin.clear();
        std::cin.ignore(10, '\n');
        std::cout << "Enter again pls:";
    }
    if(choiceOfValuta != 3){
        size_t amountOfMoney;
        std::cout << "how much of valuta do you want to convert in BYR?\nEnter:";
        while (!(std::cin >> amountOfMoney)) {
            std::cin.clear();
            std::cin.ignore(10, '\n');
            std::cout << "Enter again pls:";
        }
        Currency<USD> objUsd(amountOfMoney);
        Currency<EUR> objEur(amountOfMoney);
        unsigned short choiceOfOperator;
        std::cout << "1-'+'\n2-'-'\nEnter:";
        while (!(std::cin >> choiceOfOperator && choiceOfOperator >= 1 && choiceOfOperator <= 2)) {
            std::cin.clear();
            std::cin.ignore(10, '\n');
            std::cout << "Enter again pls:";
        }

        switch (choiceOfOperator) {
            case 1:
                choiceOfOperator = 1;
                break;
            case 2:
                choiceOfOperator = 2;
                break;
        }
        switch (choiceOfValuta) {
            case 1:
                if (choiceOfOperator == 1) {
                    objByr = objUsd.getAmountOfMoneyInRightCurrency("BYR") + objByr.getAmountOfMoneyInRightCurrency("BYR");
                    objByr.show();
                } else if (choiceOfOperator == 2) {
                    objByr = objByr.getAmountOfMoneyInRightCurrency("BYR") - objUsd.getAmountOfMoneyInRightCurrency("BYR");
                    objByr.show();
                }
                break;
            case 2:
                if (choiceOfOperator == 1) {
                    objByr = objEur.getAmountOfMoneyInRightCurrency("BYR") + objByr.getAmountOfMoneyInRightCurrency("BYR");
                    objByr.show();
                } else if (choiceOfOperator == 2) {
                    objByr = objByr.getAmountOfMoneyInRightCurrency("BYR") - objEur.getAmountOfMoneyInRightCurrency("BYR");
                    objByr.show();
                }
                break;

        }
    }else{
        std::for_each(typeOfMoney.begin(), typeOfMoney.end(), [&objByr](std::string& elem){
            std::cout << std::endl;
            objByr.show(elem);
        });
    }



    return 0;
}