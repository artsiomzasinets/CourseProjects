#include <vector>
#include<ctime>
#include<algorithm>
#include<iostream>
#include<map>
#include <cassert>


class Bag {
private:
    struct Things {

        Things(std::string name, double w, double p){
            nameThing = name;
            weight = w;
            price = p;
            weightDividedToPrice = w / p;
        }

        double weight;
        double price;
        std::string nameThing;
        double weightDividedToPrice;
    };

    std::vector<Things> things;
    double capacityOfBag;

public:

    Bag(double);

    Bag(const Bag &);

    Bag &operator=(const Bag &);

    void setCapacityOfBag(double);

    void add(std::string nameThing, double weight, double price);

    void result();
};

Bag::Bag(double capOfBag):capacityOfBag(capOfBag){

}

Bag::Bag(const Bag &outObj) {
    capacityOfBag = outObj.capacityOfBag;
    things.assign(outObj.things.begin(), outObj.things.end());
}

Bag &Bag::operator=(const Bag &outObj) {
    capacityOfBag = outObj.capacityOfBag;
    things.clear();
    things.assign(outObj.things.begin(), outObj.things.end());
    return *this;
}


void Bag::setCapacityOfBag(double cap) {
    assert(cap != 0);
    capacityOfBag = cap;
}

void Bag::add(std::string nameThing, double weight, double price) {
    Things tempObj(nameThing, weight, price);
    things.push_back(tempObj);
}


void Bag::result() {
    std::sort(things.begin(), things.end(), [](Things& elem1, Things& elem2){
        return elem1.weightDividedToPrice < elem2.weightDividedToPrice;});

    double temp = 0;
    for(std::vector<Things>::iterator i = things.begin(); i != things.end(); i++){
        temp += i->weight;
        if(temp  >= capacityOfBag){// check for (temp) is less than capacity bag
            for(std::vector<Things>::iterator it = things.end(); it !=i; it--)
                things.erase(i);
            break;
        }
    }

    for(auto i: things){
        std::cout << i.nameThing << "\tWeight: " << i.weight << "\tPrice: " << i.price << "\tWeight/Price: "
        << i.weightDividedToPrice << std::endl;
    }
}


int main() {
//    srand(time(0));
//    int sizeOfvector = 20;
//
//    std::vector<int> obj1;
//    std::vector<int> obj2(sizeOfvector /2);
//    for (size_t i = 0; i < sizeOfvector; i++) {
//    	obj1.push_back(rand() % 100);
//    }
//
//    //std::copy(obj1.begin() + obj1.size()/ 2, obj1.end(), obj2.begin());
//    obj2.assign(obj1.begin() + obj1.size() / 2, obj1.end());
//
//    for (auto i = obj1.begin(); i != obj1.end(); i++) {
//    	std::cout << " " << *i;
//    }
//    std::cout << std::endl;
//    for (auto i = obj2.begin(); i != obj2.end(); i++) {
//    	std::cout << " " << *i;
//    }
    //----------------------------------------------
    std::cout << std::endl << std::endl;
    Bag obj(7.6);
    obj.add("book", 1, 10);
    obj.add("laptop", 2.1, 3600);
    obj.add("phone", 0.443, 1000);
    obj.add("iron", 4, 5.45);
    obj.add("sweater", 0.556, 30);
    obj.add("monitor", 5, 1103);
    obj.add("book", 1, 10);
    obj.result();


    return 0;
}