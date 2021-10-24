#include<iostream>

class Vehicle
{
private:
	double amountKmOfOneTransportation;
	size_t priceOfTransport;
	size_t averageCostToServicePerYear;
public:
	Vehicle():amountKmOfOneTransportation(0), priceOfTransport(0), averageCostToServicePerYear(0) {

	}

	Vehicle(size_t amountKmOfOneTransportation, size_t priceOfTransport, size_t averageCostToServicePerYear) {
		this->amountKmOfOneTransportation = amountKmOfOneTransportation;
		this->priceOfTransport = priceOfTransport;
		this->averageCostToServicePerYear = averageCostToServicePerYear;
	}

	~Vehicle() {

	}

	double getAmountKmOfOneTransportation() const {
		return amountKmOfOneTransportation;
	}

	size_t getPriceOfTransport() const {
		return priceOfTransport;
	}

	size_t getAverageCostToServicePerYear() const {
		return averageCostToServicePerYear;
	}

	void setAmountKmOfOneTransportation(const double& value) {
		amountKmOfOneTransportation = value;
	}

	void setPriceOfTransport(const size_t& value) {
		priceOfTransport = value;
	}

	void setAverageCostToServicePerYear(const size_t& value) {
		averageCostToServicePerYear = value;
	}

	void show() {
		std::cout << "amountKmOfOneTransportation = " << amountKmOfOneTransportation << std::endl << "priceOfTransport = " << 
			priceOfTransport << std::endl << "averageCostToServicePerYear = " << averageCostToServicePerYear << std::endl;
	}
};


class Car:public Vehicle {
private:
	double costOfOneKm;
public:
	Car():costOfOneKm(0) {
		setAverageCostToServicePerYear(0);
		setPriceOfTransport(0);
		setAmountKmOfOneTransportation(0);
	}

	Car(double costOfOneKm,  size_t amountKmOfOneTransportation, size_t priceOfTransport = 0, size_t averageCostToServicePerYear = 0) {
		this->costOfOneKm = costOfOneKm;
		setAverageCostToServicePerYear(averageCostToServicePerYear);
		setPriceOfTransport(priceOfTransport);
		setAmountKmOfOneTransportation(amountKmOfOneTransportation);
	}
	
	~Car() {

	}

	void showAll() {
		std::cout << "\t\tCar\n";
		show();
		std::cout << "costOfOneKm = " << costOfOneKm << std::endl << std::endl;
	}

	double commonPriceOfTransportation()const {
		return getAmountKmOfOneTransportation() * costOfOneKm;
	}
};


class Motobike:public Vehicle {
private:
	double costOfOneKm;
public:
	Motobike() :costOfOneKm(0){
		setAverageCostToServicePerYear(0);
		setPriceOfTransport(0);
		setAmountKmOfOneTransportation(0);
	}

	Motobike(unsigned short costOfOneKm, size_t amountKmOfOneTransportation, size_t priceOfTransport = 0, size_t averageCostToServicePerYear = 0) {
		this->costOfOneKm = costOfOneKm;
		setAverageCostToServicePerYear(averageCostToServicePerYear);
		setPriceOfTransport(priceOfTransport);
		setAmountKmOfOneTransportation(amountKmOfOneTransportation);
	}

	~Motobike() {

	}

	void showAll() {
		std::cout << "\t\tMotobike\n";
		show();
		std::cout << "costOfOneKm = " << costOfOneKm << std::endl << std::endl;
	}

	double commonPriceOfTransportation() const {
		return getAmountKmOfOneTransportation() * costOfOneKm;
	}
};

class Bike:public Vehicle {
private:
	 double costOfCyclistPerHour;
public:
	Bike() :costOfCyclistPerHour(0){
		setAverageCostToServicePerYear(0);
		setPriceOfTransport(0);
		setAmountKmOfOneTransportation(0);
	}

	Bike(double costOfCyclistPerHour, size_t amountKmOfOneTransportation, size_t priceOfTransport = 0, size_t averageCostToServicePerYear =0) {
		this->costOfCyclistPerHour = costOfCyclistPerHour;
		setAverageCostToServicePerYear(averageCostToServicePerYear);
		setPriceOfTransport(priceOfTransport);
		setAmountKmOfOneTransportation(amountKmOfOneTransportation);
	}

	~Bike() {

	}

	void showAll() {
		std::cout << "\t\tBike\n";
		show();
		std::cout << "costOfCyclistPerHour = " << costOfCyclistPerHour << std::endl << std::endl;
	}

	double commonPriceOfTransportation() const {
		return getAmountKmOfOneTransportation() * costOfCyclistPerHour;
	}
};


int main() {
	Car obj1(12.5,100);
	Motobike obj2(8.6, 80);
	Bike obj3(2.5, 20);
	obj1.showAll();
	obj2.showAll();
	obj3.showAll();
	std::cout << "car = " << obj1.commonPriceOfTransportation() << "$" << std::endl;
	std::cout << "motobike = " << obj2.commonPriceOfTransportation() << "$" << std::endl;
	std::cout << "bike = " << obj3.commonPriceOfTransportation() << "$" << std::endl;
	std::cout << std::endl;
	auto common = [](const Car& objCar, const Motobike& objMoto, const Bike& objBike) -> double
	{
		return objCar.commonPriceOfTransportation() + objMoto.commonPriceOfTransportation() + objBike.commonPriceOfTransportation();
	};
	std::cout << "Common price = " << common(obj1, obj2, obj3) << "$" << std::endl;


	return 0;
}