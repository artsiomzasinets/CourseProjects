#ifndef CURRENECY_H_
#define CURRENECY_H_

#include<iostream>
#include "valuta.h"


template<class T>
class Currency {
private:
    T typeOfMoney;
    double amountOfMoney;
private:
    double exchange(const char *);// exchanging to other valuta
public:
    Currency();

    Currency(double);

    Currency &operator=(double );
    Currency &operator=(Currency &);
    Currency& operator+(Currency &);

    Currency &operator-(Currency &);

    Currency& operator+(double );

    Currency &operator-(double);

    Currency &operator*(Currency &);

    Currency &operator/(Currency &);

    void setAmountOfMoney(double);

    double getAmountOfMoney();

    void show();

    void show(std::string&);

    double getAmountOfMoneyInRightCurrency(const char*);


};

template<class T>
inline double Currency<T>::exchange(const char *val) {
    return amountOfMoney / typeOfMoney.getValutaExchangeRatio(val);
}

template<class T>
inline Currency<T>::Currency():amountOfMoney(1) {

}

template<class T>
inline Currency<T>::Currency(double temp):amountOfMoney(temp) {

}

template<class T>
inline Currency<T>& Currency<T>::operator=(double temp){
    amountOfMoney = temp;
    return *this;
}

template<class T>
inline Currency<T> &Currency<T>::operator=(Currency & outObj) {
    amountOfMoney = outObj.amountOfMoney;
    return *this;
}

template<class T>
inline Currency<T> &Currency<T>::operator+(Currency & outObj) {
    amountOfMoney += exchange(outObj.typeOfMoney.getNameOfValuta());
    return *this;
}

template<class T>
inline Currency<T> &Currency<T>::operator+(double outObj) {
    amountOfMoney += outObj;
    return *this;
}

template<class T>
inline Currency<T> &Currency<T>::operator-(double outObj) {
    amountOfMoney -= outObj;
    return *this;
}


template<class T>
inline Currency<T> &Currency<T>::operator-(Currency &outObj) {
    amountOfMoney -= exchange(outObj.typeOfMoney.getNameOfValuta());
    return *this;
}

template<class T>
inline Currency<T> &Currency<T>::operator*(Currency & outObj) {
    amountOfMoney *= exchange(outObj.typeOfMoney.getNameOfValuta());
    return *this;
}

template<class T>
inline Currency<T> &Currency<T>::operator/(Currency & outObj) {
    amountOfMoney /= exchange(outObj.typeOfMoney.getNameOfValuta());
    return *this;
}

template<class T>
inline void Currency<T>::setAmountOfMoney(double outAmount) {
    amountOfMoney = outAmount;
}

template<class T>
inline double Currency<T>::getAmountOfMoney() {
    return amountOfMoney;
}

template<class T>
inline void Currency<T>::show(){
    std::cout << amountOfMoney << " " << typeOfMoney.getNameOfValuta() << std::endl;
}

template<class T>
inline void Currency<T>::show(std::string& val) {

        std::cout << amountOfMoney << " " << typeOfMoney.getNameOfValuta() << " = ";
        if (val == "USD") {
            std::cout << exchange("USD") << " USD" << std::endl;
        }
        else if (val == "EUR") {
            std::cout << exchange("EUR") << " EUR" << std::endl;

        } else if (val== "BYR") {
            std::cout << exchange("BYR") << " BYR" << std::endl;

        } else if (val == "RUB") {
            std::cout << exchange("RUB") << " RUB" << std::endl;

        } else if (val== "UAH") {
            std::cout << exchange("UAH") << " UAH" << std::endl;

        } else if (val== "PLN") {
            std::cout << exchange("PLN") << " PLN" << std::endl;

        }

}

template<class T>
inline double Currency<T>::getAmountOfMoneyInRightCurrency(const char * val) {
    return exchange(val);
}




#endif // !CURRENECY_H_
