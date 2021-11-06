#include <iostream>


//Определить комбинированный (структурный) тип, содержащий информацию о студенте: фамилия, имя, факультет, группа, e-mail.
//Выделить статический массив памяти для 30 студентов.
//Выделить динамический массив памяти для заранее неизвестного количества студентов.
//Получить доступ к первому студенту из массива, используя разыменование указателя.
//Вычислить размер памяти, занимаемый массивом студентов.
//Проитерироваться по массиву студентов, используя инкремент указателя. Вывести в консоль адрес каждой структуры студента в памяти. Вывести сообщение о величине, на которую изменяется значение указателя при инкременте.
//Вывести на консоль адреса соседних полей структуры.
//Создать структуру с таким же набором полей, но другой последовательностью. Сравнить размеры структур. Вывести на консоль адреса каждого поля для обеих структур. Сделать выводы.

struct Student{//32 bite
    const char* surname;
    const char* name;
    short faculty;
    short group;
    const char* email;

    Student() {
        surname = "lecy";
        name = "Adolf";
        faculty = 134;
        group = 13;
        email = "ffdsafads";
    }

    friend std::ostream& operator<<(std::ostream& os, Student& outObject){
        os << "\nSurname:" << sizeof(outObject.surname) << "\nName:" << sizeof(outObject.name)
           << "\nFaculty:" << sizeof(outObject.faculty) << "\nGroup:" << sizeof(outObject.group)
           << "\nEmail:" << sizeof(outObject.email);
        return  os;
    }
};

struct Student2{//32 bite
    short faculty;
    short group;
    const char* surname;
    const char* name;
    const char* email;

    Student2() {
        surname = "lecy";
        name = "Adolf";
        faculty = 134;
        group = 13;
        email = "ffdsafads";
    }

    friend std::ostream& operator<<(std::ostream& os, Student2& outObject){
        os << "\nSurname:" << sizeof(outObject.surname) << "\nName:" << sizeof(outObject.name)
        << "\nFaculty:" << sizeof(outObject.faculty) << "\nGroup:" << sizeof(outObject.group)
        << "\nEmail:" << sizeof(outObject.email);
        return  os;
    }
};

int main() {//memory
    Student staticObjects[30];
    std::cout << "How much students do you have?";
    size_t choice;
    while (!(std::cin >> choice)){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong choice!Enter again:";
    }
    Student* dynamicObjects = new Student[choice];
    dynamicObjects[0].surname = "ZEFIR";
    dynamicObjects[choice-1].email = "hello";

    std::cout << *dynamicObjects << std::endl;
    std::cout << "\nsizeOf static = " << sizeof(staticObjects) << std::endl;
    for(Student* iter =  dynamicObjects; iter != (dynamicObjects + choice); iter++){
        std::cout << "\nsizeof iter = " << sizeof(*iter) << "\naddress of iter = " << iter << "\nfields address = "
        << &iter->surname << '\n' << &iter->name << std::endl << std::endl;
    }

    Student obj1;
    Student2 obj2;
    std::cout << "\n\t\tAddress Student1\nsizeof = " << sizeof(obj1) << std::endl;
    std::cout << "\n\t\tAddress Student2\nsizeof = " << sizeof(obj2) << std::endl;


    delete[] dynamicObjects;
    return 0;
}
