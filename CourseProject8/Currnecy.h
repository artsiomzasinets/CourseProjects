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

    Currency &operator*(Currency &);

    Currency &operator/(Currency &);

    void setAmountOfMoney(double);

    double getAmountOfMoney();

    void show();

    void show(const char *);

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
inline void Currency<T>::show(const char *val) {
    if (val == typeOfMoney.getNameOfValuta()) {
        std::cout << "\nYou entered the equal currency!" << std::endl;
    } else {
        std::cout << amountOfMoney << " " << typeOfMoney.getNameOfValuta() << " = ";
        const size_t typeOfMoneyHash = typeOfMoney.getHash(val);

        if (typeOfMoneyHash == typeOfMoney.getHash("USD")) {
            std::cout << exchange("USD") << " USD" << std::endl;
        } else if (typeOfMoneyHash == typeOfMoney.getHash("EUR")) {
            std::cout << exchange("EUR") << " EUR" << std::endl;

        } else if (typeOfMoneyHash == typeOfMoney.getHash("BYR")) {
            std::cout << exchange("BYR") << " BYR" << std::endl;

        } else if (typeOfMoneyHash == typeOfMoney.getHash("RUB")) {
            std::cout << exchange("RUB") << " RUB" << std::endl;

        } else if (typeOfMoneyHash == typeOfMoney.getHash("UAH")) {
            std::cout << exchange("UAH") << " UAH" << std::endl;

        } else if (typeOfMoneyHash == typeOfMoney.getHash("PLN")) {
            std::cout << exchange("PLN") << " PLN" << std::endl;

        }

    }

}

template<class T>
inline double Currency<T>::getAmountOfMoneyInRightCurrency(const char * val) {
    return exchange(val);
}


#endif // !CURRENECY_H_
