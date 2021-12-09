#include <iostream>
#include <ctime>

#include "queue.h"

//Напишите шаблон класса для работы с очередью. Учесть, что очереди требуется два индекса: индекс хвоста,
//куда добавляются новые элементы, и индекс головы очереди, откуда исчезают старые.
//Программист не будет совершать ошибок при написании модели очереди. Например, вместимость очереди не будет превышена,
// а из пустой очереди не будет производиться попыток удаления данных.
// Предусмотреть пользовательский ввод /вывод данных.
//Определите несколько очередей разных типов и поработайте с их данными.
//Добавьте механизм обработки исключений в программу:
// при превышении размера очереди и при попытке удаления данных из пустой очереди.
// Программа должна обеспечивать повторную попытку ввода данных пользователем без нарушения целостности содержимого очереди.


template<class T>
void enter(Queue<T> &object) {
    std::cout << "Enter element to push to Queue:";
    T choice;
    while (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Enter again:";
    }
    object.push(choice);
}

template<class T>
void generate(Queue<T> &object) {
    srand(time(0));
    std::cout << "How much elements do you wanna generate?:";
    size_t choice;
    while (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Enter again:";
    }
    object.setCapacity(choice + object.size() + 1);
    for (size_t i = 0; i < choice; i++) {
        object.push(rand() % 100);
    }
}

template<class T>
void removeQ(Queue<T> &object) {
    srand(time(0));
    std::cout << "How much elements do you wanna remove?:";
    size_t choice;

    while (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Enter again:";
    }
    for (size_t i = 0; i < choice; i++) {
        object.pop();
    }
}

int main() {
    Queue<int> obj1;
    obj1.push(5);
    obj1.push(10);
    Queue<int> obj2(obj1);
    Queue<int> obj3;
    obj3 = std::move(obj1);
    int a = 4;
    obj1.push(a);

    Queue<int> obj4;

    bool loop = true;
    while (loop) {
        std::cout
                << "1-Enter a elemet\n2-Print all\n3-Enter range to generating automatically\n4-remove\n5-exit\nChoice:";
        unsigned short choice;
        while (!(std::cin >> choice && choice >= 0 && choice <= 5)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Enter again:";
        }
        switch (choice) {
            case 1:
                enter(obj4);std::cout << std::endl;
                break;
            case 2:
                std::cout << obj4;std::cout << std::endl;
                break;
            case 3:
                generate(obj4);std::cout << std::endl;
                break;
            case 4:
                try {
                    removeQ(obj4);std::cout << std::endl;
                } catch (std::out_of_range &error) {
                    std::cerr << "\nCan not pop more. " << error.what() << std::endl;
                }
                break;
            case 5:
                loop = false;
                break;
        }
    }


//    try {
//        for (;;) {
//            obj4.pop();
//        }
//    } catch (std::underflow_error &error) {
//        std::cerr << error.what() << std::endl;
//    }


    return 0;
}
