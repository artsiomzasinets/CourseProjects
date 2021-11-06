#include <iostream>


int main() {

    return 0;
}

//
//class Fraction{
//private:
//    double a, b;
//public:
//    Fraction(double a , double b){
//        if(b == 0)
//            throw std::runtime_error("Error!!! b = 0!!! in class");
//        this->a = a;
//        this->b = b;
//    }
//    double result(){
//        return a / b;
//    }
//
//    friend std::ostream& operator<<(std::ostream &os, Fraction& obj){
//        os << "a = " << obj.a << "\nb = " << obj.b << "\nresultOfDivision = " << obj.result() << std::endl;
//        return  os;
//    }
//};
//
//int fun(double a, double b){
//    if(b ==0)
//        throw std::invalid_argument("b = 0 !!!! in function");
//    else{
//        return a/b;
//    }
//}
////--------------------------main
//double a,b;
//try{
//std::cout << "Enter a and b:";
//while(!(std::cin >> a >> b)){
//std::cin.clear();
//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//std::cout << "Wrong enter!\nEnter again:";
//}
//std::cout << "result = " << fun(a,b) << std::endl;
//}catch (std::invalid_argument& error){
//std::cerr <<  error.what() << std::endl;
//}catch (...){
//std::cerr << "something bad happened" << std::endl;
//}
//
//try{
//Fraction(35, 0);
//}catch (std::runtime_error& error){
//std::cerr << error.what() << std::endl;
//}catch(...){
//std::cerr << "something bad happened" << std::endl;
//}
//
//try{
//Fraction obj(35, 5);
//std::cout << obj;
//Fraction a(30,0);
//
//} catch (std::exception& error) {
//std::cerr << error.what() << std::endl;
//}catch(...){
//std::cerr << "something bad happened" << std::endl;
//}