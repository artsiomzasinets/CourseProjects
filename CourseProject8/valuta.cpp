#include "valuta.h"


void Valuta::openExchangeFile() {
    std::ifstream fin("P:\\visual studio\\CourseProjects\\CourseProject8\\exchangeRates.txt", std::ios::in);
    if(!fin.is_open()){
        assert("Can't open the file");
    } else{
        while (!fin.eof()){
            std::string tempStr;
            double tempDouble;
            fin >> tempStr >> tempDouble;
            exchangeRatio.insert({tempStr, tempDouble});
        }
    }
    fin.close();
}

const size_t Valuta::getHash(const char *val) {
    return h(val);
}

const std::map<std::string, double>& Valuta::getExchangeRatio(){

    return exchangeRatio;
}
