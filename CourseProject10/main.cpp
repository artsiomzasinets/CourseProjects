#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <algorithm>


struct Employee {
    std::string SNP; // фамилия имя отчество
    unsigned short dayOfBirthday;
    unsigned short mounthOfBirthday;
    unsigned short yearOfBirthday;
    bool isMan;
};

void downloadDataFromFile(std::vector<Employee> &object, const char *);//1 загрузить данные из файла
void enterData(std::vector<Employee> &object);//2 ввести данные//done
void addSomeData(std::vector<Employee> &object);//3 добавление данных
void sortDataBySurname(const char *);//4 сортировка базы данных по алфавиту (по фамилии)
void sortDataByAge(const char*);//5 сортировка базы данных по возрасту
void printDataWhoBorn( const char*);//6 вывод: список людей, родившихся в заданном месяце
void printSurnameTheOldestMan(const char*);//7вывод: фамилию самого старшего мужчины
void printAllSurnameStartsFromLetter(const char*);//8 вывод: все фамилии, начинающиеся с заданной буквы
void saveData(const std::vector<Employee> &object, const char *, bool);

void printDataAll( std::vector<Employee> &object, const char*);

void addDataToVector(std::vector<Employee> &object);

int main() {
    const char *fileName = "../database.db";

    std::vector<Employee> object;
    bool exit = true;
    unsigned short choice;
    while (exit) {
        std::cout << "\n1 download data from file \n"
                     "2 enter a data(if file has some data, the method delete them)\n"
                     "3 add some data\n"
                     "4 sorting database by alphabet (by surname)\n"
                     "5 sorting database by age\n"
                     "6 print: people list who born on following month\n"
                     "7 print: surname the oldest man: \n"
                     "8 print: all surname which start from following letter\n"
                     "9 print: all\n"
                     "0 exit" << std::endl << "Choose:";
        while (!(std::cin >> choice && choice >= 0 && choice <= 9)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong choice!\nEnter again:";
        }
        switch (choice) {
            case 1:
                downloadDataFromFile(object, fileName);
                break;
            case 2:
                enterData(object);
                saveData(object, fileName, false);
                break;
            case 3:
                addSomeData(object);
                saveData(object, fileName, true);
                break;
            case 4:
                sortDataBySurname(fileName);
                break;
            case 5:
                sortDataByAge(fileName);
                break;
            case 6:
                printDataWhoBorn(fileName);
                break;
            case 7:
                printSurnameTheOldestMan(fileName);
                break;
            case 8:
                printAllSurnameStartsFromLetter(fileName);
                break;
            case 9:printDataAll(object,fileName);break;
            case 0:
                exit = false;
                break;
        }
    }


    return 0;
}

void downloadDataFromFile(std::vector<Employee> &object, const char *file) {
    if(!object.empty()){
        object.clear();
    }

    std::ifstream fin(file, std::ios_base::in);
    if (fin.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "\nFile is empty" << std::endl;
        return;
    }


    if (fin.is_open()) {
        while (!fin.eof()) {
            Employee temp;

            std::getline(fin, temp.SNP, '|');
            fin >> temp.dayOfBirthday >> temp.mounthOfBirthday >> temp.yearOfBirthday >> temp.isMan;
            object.push_back(temp);
            fin.ignore(1, '\n');
        }
    } else {
        std::cerr << "file doesn't open" << std::endl;
    }
    fin.close();
}


void enterData(std::vector<Employee> &object) {
    addDataToVector(object);
}

void addSomeData(std::vector<Employee> &object) {
    addDataToVector(object);
}


void sortDataBySurname(const char *file) {
    std::vector<Employee> temp;
    downloadDataFromFile(temp, file);


    std::sort(temp.begin(), temp.end(), [](Employee &obj1, Employee &obj2) {
        int i =0;
        for(;obj1.SNP[i] ==obj2.SNP[i];i++){}
        if(obj1.SNP[i] < obj2.SNP[i]){
            return true;
        }
    });


    saveData(temp, file, false);
}


void sortDataByAge( const char* file) {
    std::vector<Employee> temp;
    downloadDataFromFile(temp, file);


    std::sort(temp.begin(), temp.end(), [](Employee &obj1, Employee &obj2) {
        if(obj1.yearOfBirthday == obj2.yearOfBirthday){
            if(obj1.mounthOfBirthday == obj2.mounthOfBirthday){
                if(obj1.dayOfBirthday < obj2.dayOfBirthday){
                    return true;
                }
            }
        }else{
            return obj1.yearOfBirthday < obj2.yearOfBirthday;
        }
    });


    saveData(temp, file, false);
}


void printDataWhoBorn(const char* file) {
    std::vector<Employee> temp;
    downloadDataFromFile(temp, file);
    unsigned short month;
    std::cout << "Enter month:";
    while (!(std::cin >> month && month >= 1 && month <= 12)){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter again(1-12):";
    }
    for(int  i = temp.size() - 1; i >= 0; i--){
        if(temp[i].mounthOfBirthday != month){
            temp.erase(temp.begin() + i);
        }
    }
    if(temp.empty()){
        std::cout << "There is not person who born in " << month << " month" << std::endl;
    }else{
        std::cout << "There are  who born in " << month << " month:";
        printDataAll(temp, file);
    }

}


void printSurnameTheOldestMan(const char* file) {
    std::vector<Employee> temp;
    std::vector<Employee>::iterator result;
    downloadDataFromFile(temp, file);


    result = std::max_element(temp.begin(), temp.end(), [](Employee &obj1, Employee &obj2) {
        if(obj1.isMan < obj2.isMan)
            return true;
        if(obj1.yearOfBirthday < obj2.yearOfBirthday
        || obj1.yearOfBirthday == obj2.yearOfBirthday && obj1.mounthOfBirthday > obj2.mounthOfBirthday
        || obj1.yearOfBirthday == obj2.yearOfBirthday && obj1.mounthOfBirthday == obj2.mounthOfBirthday && obj1.dayOfBirthday > obj2.dayOfBirthday)
        {
            return true;
        } else {
            return false;
        }
    });
    std::cout << "\nThe oldest man is " << result->SNP << std::endl;
}


void printAllSurnameStartsFromLetter(const char* file) {
    std::vector<Employee> temp;
    downloadDataFromFile(temp, file);
    std::cout << "Enter the symbol:";
    char letter;
    while (!(std::cin >> letter && std::isalpha(letter))){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Wrong symbol!Enter again:";
    }
    std::cout << '\n';
    std::for_each(temp.begin(), temp.end(),[letter](Employee& elem){
        if(tolower(elem.SNP[0]) == tolower(letter)){
            std::cout << elem.SNP << std::endl;
        }
    });
}

void saveData(const std::vector<Employee> &object, const char *file, bool flag) {

    std::ifstream fin(file);
    if (fin.peek() == std::ifstream::traits_type::eof()) {
        flag = false;
    }
    fin.close();
    if (object.empty()) {
        std::cout << "\nNothing to save to the file" << std::endl;
        return;
    }


    std::ofstream fout;


    if (flag)// if flag == true add to the end of file
        fout.open(file, std::ios_base::app);
    else
        fout.open(file);


    if (fout.is_open()) {

        if (flag)
            fout << '\n';

        for (std::vector<Employee>::const_iterator iter = object.cbegin(); iter != object.cend(); iter++) {
            fout << iter->SNP;
            fout.put('|');
            fout << iter->dayOfBirthday;
            fout << ' ';
            fout << iter->mounthOfBirthday;
            fout << ' ';
            fout << iter->yearOfBirthday;
            fout << ' ';
            fout << iter->isMan;
            if (iter + 1 != object.cend())
                fout << std::endl;
        }
    } else {
        std::cerr << "File doesn't open" << std::endl;
    }
    fout.close();
}

void printDataAll(std::vector<Employee> &object, const char* file) {
    std::cout << '\n';

    downloadDataFromFile(object, file);

    std::cout << '\n';

    for (std::vector<Employee>::const_iterator iter = object.cbegin(); iter != object.cend(); iter++) {
        std::cout << "SNP: " << iter->SNP << "\nBirthday: " << iter->dayOfBirthday << "-"
                  << iter->mounthOfBirthday << "-" << iter->yearOfBirthday << "\nSex: "
                  << (iter->isMan ? "man" : "women") << '\n' << std::endl;
    }

    std::system("pause");
}

void addDataToVector(std::vector<Employee> &object) {
    std::cout << std::endl;
    std::cin.clear();
    std::cout << "How match people do you want to enter?\nEnter:";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    unsigned short choice;
    while (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter only letter!\nEnter:";
    }
    try {
        for (unsigned short i = 0; i < choice; i++) {
            Employee temp;
            std::cout << "\t\t***Enter data for " << i << " human***\n";
            std::cout << "SurnameNamePatronymic: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, temp.SNP, '\n');

            std::cout << "Birthday(ex:14 4 2204): ";

            while (!(std::cin >> temp.dayOfBirthday >> temp.mounthOfBirthday >> temp.yearOfBirthday
                     && temp.dayOfBirthday >= 1 && temp.dayOfBirthday <= 31
                     && temp.mounthOfBirthday >= 1 && temp.mounthOfBirthday <= 12)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Not right enter, please enter again\nEnter(ex:14 4 2204):";
            }

            std::cout << "Sex(m/w): ";
            char s;

            while (!(std::cin >> s && (s == 'm' || s == 'w'))) {
                std::cout << "Not right choice, please enter again\nEnter(m/w):";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            if (s == 'm') {
                temp.isMan = true;
            } else {
                temp.isMan = false;
            }

            object.push_back(temp);
        }
    } catch (...) {
        std::cerr << "Something bad happen.Fail" << std::endl;
    }
}