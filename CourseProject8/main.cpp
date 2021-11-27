#include <iostream>

#include"Currnecy.h"



int main() {
    //TODO user enter
	Currency<USD> objUsd(15.5);
    Currency<EUR> objEur(9.8);
    Currency<BYR> objByr;
    objByr = objUsd.getAmountOfMoneyInRightCurrency("BYR") + objEur.getAmountOfMoneyInRightCurrency("BYR");
    objByr.show();
    objUsd.show("EUR");
    objUsd.show("RUB");


	return 0;
}