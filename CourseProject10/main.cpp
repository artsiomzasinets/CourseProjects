#include <iostream>



struct Employee{
    std::string SNP; // фамилия имя отчество
    unsigned short dayOfBirthday;
    unsigned short mounthOfBirthday;
    unsigned short yearOfBirthday;
    char sex;
};

int main() {
//    1 загрузить данные из файла
//    2 ввести данные
//    3 добавление данных
//    4 сортировка базы данных по алфавиту (по фамилии)
//    5 сортировка базы данных по возрасту
//    6 вывод: список людей, родившихся в заданном месяце
//    7  вывод: фамилию самого старшего мужчины
//    8 вывод: все фамилии, начинающиеся с заданной буквы
//    0 выход из программы

    unsigned short choice;
    std::cout << "1 download data from file \n"
                 "2 enter a data\n"
                 "3 add some data\n"
                 "4 sorting database by alphabet (by surname)\n"
                 "5 sorting database by age\n"
                 "6 print: people list who borned on following month:\n"
                 "7  print: surname the oldest man: \n"
                 "8 print: all surname which start from following letter\n"
                 "0 exit" << std::endl;
    while (!(std::cin >> choice && choice >=0 && choice <= 8)){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter again:";
    }
    switch (choice) {
        case 1: break;
        case 2: break;
        case 3: break;
        case 4: break;
        case 5: break;
        case 6: break;
        case 7: break;
        case 8: break;
        case 0: break;
    }

    return 0;
}
