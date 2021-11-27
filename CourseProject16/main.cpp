//1Реализовать собственную строку myStr/вектор myVec с поддержкой семантики перемещения.
//Предусмотреть возможность вывода сообщений о том,
//какой конструктор/деструктор вызывается (например, метод класса с параметром типа char).

//2Создать класс TextView/VectorView: закрытый член типа myStr/myVec+конструктор с одним константным параметром,
//инициализированным с использованием std::move(). Обратить внимание на влияние модификаторов объектов.
#include <iostream>

#include "OwnString.h"
#include "TextView.h"

int main() {//l-value, r-value
    size_t size = 10;
    char* c = new char[size];

    OwnString str1(c,size);
    OwnString str2;
    str2 = std::move(str1);

    TextView tv(std::move(str2));

    return 0;
}
