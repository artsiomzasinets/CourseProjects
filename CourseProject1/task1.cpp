#include<iostream>


struct Student
{
	Student() :sizeOfNameSurname(50), surname(nullptr), name(nullptr){
		
	}

	Student(const Student& obj) {
		sizeOfNameSurname = obj.sizeOfNameSurname;
		surname = new char[sizeOfNameSurname];
		name = new char[sizeOfNameSurname];

		for (int i = 0; i < sizeOfNameSurname; ++i) {
			surname[i] = obj.surname[i];
			name[i] = obj.name[i];
		}
		for (int i = 0; i < 3; ++i) {
			marks[i] = obj.marks[i];
		}
	}

	Student operator=(const Student& obj) {

		if (surname != nullptr && name != nullptr) {
			delete[] surname;
			delete[] name;
		}
		sizeOfNameSurname = obj.sizeOfNameSurname;
		surname = new char[sizeOfNameSurname];
		name = new char[sizeOfNameSurname];
	
		for (int i = 0; i < sizeOfNameSurname; ++i) {
			surname[i] = obj.surname[i];
			name[i] = obj.name[i];
		}
		for (int i = 0; i < 3; ++i) {
			marks[i] = obj.marks[i];
		}
		return *this;
	}

	~Student() {
		delete[] surname;
		delete[] name;
	}
	
	void setAllData() {
		if (surname == nullptr && name == nullptr) {
			surname = new char[sizeOfNameSurname];
			name = new char[sizeOfNameSurname];
		}

		std::cout << std::endl << "Surname:"; enterCharData(surname, sizeOfNameSurname); std::cout << std::endl;
		std::cout << "Name:"; enterCharData(name, sizeOfNameSurname); std::cout << std::endl;
		for (int i = 0; i < 3; ++i) {
			std::cout << i + 1  << " mark for subject:"; enterNumberData(marks[i]);
		}
		
	}

	void show()  const {
		if (surname != nullptr && name != nullptr) {
			std::cout << std::endl << "*****************" << std::endl;
			std::cout << "Surname:" << surname << std::endl;
			std::cout << "Name:" << name << std::endl;
			std::cout << "First mark:" << marks[0] << std::endl;
			std::cout << "Second mark:" << marks[1] << std::endl;
			std::cout << "Third mark:" << marks[2] << std::endl;;
			std::cout << "*****************" << std::endl;
		}
		else
		{
			std::cout << "it's empty struct" << std::endl;
		}
		
	}


	short returningTheLeastMark() const { //it's for other variant
		unsigned short temp = -1;
		for (int i = 0; i < 3; ++i) {
			if (marks[i] < temp) {
				temp = marks[i];
			}
		}
		return temp;

	}

	short returningTheSumOfMarks() const {// it's a mine variant
		unsigned short temp(0);
		for (int i = 0; i < 3; ++i) {
			temp += marks[i];
		}
		return temp;
	}

	
	
private:
	char* surname;
	char* name;
	unsigned short marks[3];
private:
	 unsigned short sizeOfNameSurname;

private:




	bool checkerForLetter(const char* str) {// it's to check symbols for correct input
		int counter = 0;
		while (str[counter] != '\0') {
			if (!isalpha(str[counter])) {
				return false;
			}
			++counter;
		}
		return true;
	}

	void enterCharData(char* str,const int& size) {// method for inputting char data
		while (true)
		{
			std::cin.getline(str, size, '\n');
			if (checkerForLetter(str)) {
				break;
			}
			else {
				std::cout << "Wrong symbols, please enter only letter!" << std::endl << "Enter again:";
			}
		}
	}

	void enterNumberData(unsigned short& mark) {
		while (true) {
			if (std::cin >> mark && mark <= 100) {
				break;
			}
			else {
				std::cout << "Wrong symbols, please enter only number!" << std::endl << "Enter again:";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//it ignores all symbols befor '\n'
			}
			
		}
	
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//it ignores all symbols befor '\n'
	}

};


void printAllElementsOfArray(const Student* obj, const  unsigned short& sizeOfArray) {
	for (int i = 0; i < sizeOfArray; ++i) {
		obj[i].show();
	}
}

void enterAllElementsOfArray(Student* obj, const unsigned short& sizeOfArray) {
	for (int i = 0; i < sizeOfArray; ++i) {
		std::cout << "\t\tStudent|" << i + 1 << "|" << std::endl;
		obj[i].setAllData();
		
	}
}

void descendingSort(Student* arr, const unsigned short& sizeOfArray) {//comb sort
	
	double range = 1.247;//const number
	double temp = sizeOfArray / range;
	unsigned short step = std::round(temp);
	while (temp > 1)
	{
		for (int h = step, l = 0; h < sizeOfArray; ++h, ++l)
		{
			if (arr[l].returningTheSumOfMarks() < arr[h].returningTheSumOfMarks()) {
				Student tempObj = arr[l];
				arr[l] = arr[h];
				arr[h] = tempObj;
			}
		}
		temp /= range;
		step = std::round(temp);
	}
	
}


int main() {

	unsigned short numberOfStudent;
	std::cout << "Enter number of students(more than 5):";
	while(true){
		if (std::cin >> numberOfStudent && numberOfStudent >=3) {
			break;
		}
		else {
			std::cout << "Wrong symbols, please enter only number!" << std::endl << "Enter again:";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		
	}

	Student* structOfStudent = new Student[numberOfStudent];//2
	std::system("cls");
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	enterAllElementsOfArray(structOfStudent, numberOfStudent);//3
	std::system("cls");
	printAllElementsOfArray(structOfStudent, numberOfStudent);//4
	system("pause");
	descendingSort(structOfStudent, numberOfStudent);//5 по убыванию |cуммарный балл по 3-м предметам
	system("cls");
	std::cout << "\tSorted" << std::endl;
	printAllElementsOfArray(structOfStudent, numberOfStudent);//6

	

	delete[] structOfStudent;
	return 0;
}