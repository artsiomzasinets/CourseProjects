
#ifndef COURSEPROJECT8_VALUTA_H
#define COURSEPROJECT8_VALUTA_H

#include <map>
#include <fstream>
#include <cassert>

class Valuta {
private:
    std::map<std::string, double> exchangeRatio;

protected:
    std::hash<const char *> h;

    void openExchangeFile();// copy file into exchangeRatio
    const std::map<std::string, double> &getExchangeRatio();

    virtual double getValutaExchangeRatio(const char *) = 0;// return 1 currency to other type of currency
    virtual const char *getNameOfValuta() = 0;

public:
    const size_t getHash(const char *);

};// for a new inherit classes from Valuta, you have to override next methods:  getValutaExchangeRatio, getNameOfValuta,



class USD : public Valuta {
public:
    USD(){
        openExchangeFile();
    }

    double getValutaExchangeRatio(const char *currency) override {
        auto var = getExchangeRatio();
        return var["USD"] / var[currency];
    }

    const char *getNameOfValuta() override {
        return "USD";
    }


};

class EUR : public Valuta {
public:

    EUR(){
        openExchangeFile();
    }



    double getValutaExchangeRatio(const char *currency) override {
        auto var = getExchangeRatio();
        return var["EUR"] / var[currency];
    }

    const char *getNameOfValuta() override {
        return "EUR";
    }


};

class BYR : public Valuta {
public:
    BYR(){
        openExchangeFile();
    }



    double getValutaExchangeRatio(const char *currency) override {
        auto var = getExchangeRatio();
        return var["BYR"] / var[currency];
    }

    const char *getNameOfValuta() override {
        return "BYR";
    }


};

class RUB : public Valuta {
public:
    RUB(){
        openExchangeFile();
    }



    double getValutaExchangeRatio(const char *currency) override {
        auto var = getExchangeRatio();
        return var["RUB"] / var[currency];
    }

    const char *getNameOfValuta() override {
        return "RUB";
    }


};

class UAH : public Valuta {
public:
    UAH(){
        openExchangeFile();
    }



    double getValutaExchangeRatio(const char *currency) override {
        auto var = getExchangeRatio();
        return var["UAH"] / var[currency];
    }

    const char *getNameOfValuta() override {
        return "UAH";
    }

};

class PLN : public Valuta {
public:
    PLN(){
        openExchangeFile();
    }



    double getValutaExchangeRatio(const char *currency) override {
        auto var = getExchangeRatio();
        return var["PLN"] / var[currency];
    }

    const char *getNameOfValuta() override {
        return "PLN";
    }

};


#endif //COURSEPROJECT8_VALUTA_H
