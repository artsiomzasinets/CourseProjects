#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <algorithm>






typedef unsigned short us;

int main() {
    srand(time(0));
    std::vector<int> vec;
    for (int i = 0; i < 15; ++i) {
        vec.push_back(rand() % 100);
    }

    auto print = [](const auto& obj) {
        for (auto iter = obj.cbegin(); iter != obj.cend(); ++iter) {
            std::cout << *iter << ' ';
        }
        std::cout << std::endl;
    };
    print(vec);//1

    unsigned int counter{ 0 };
    std::sort(vec.begin(), vec.end(), [&counter](const int& a, const int& b) -> bool//2
    {
        if (a < b) {
            counter++;
            return true;
        }
        else {
            return false;
        }
    });
    std::cout << "Sorted vector:" << std::endl;
    print(vec);
    std::cout << "There is " << counter << " permutation" << std::endl << std::endl;

    ///////////////////////////////////////////////////////

    std::string str, subStr;
    std::cout << "Enter string:";
    std::getline(std::cin, str);
    std::cout << "Enter substring:";
    std::getline(std::cin, subStr);


    auto findSubstring = [](const std::string& str, const std::string& substr) {
        size_t result = str.find(substr);
        if (result != std::string::npos) {
            std::cout << "The first mention is " << result << std::endl << std::endl;
        }
        else {
            std::cout << "There is not mention" << std::endl << std::endl;
        }
    };
    findSubstring(str, subStr);

    /////////////////////////////////////////////////
    std::vector<int> obj;
    auto generation = [&obj]( us right=0, us middle = 0) {
        if (middle == 0) {
            for (us i = 0; i < right; ++i) {
                obj.push_back(i);
            }
        }
        else if(!obj.empty()){
            obj.erase(obj.begin(), obj.begin()+ middle);
            for (us i = 1; i <= middle; ++i) {
                obj.push_back(obj.back() + 1);
            }

        }
        else {
            for (us i = middle; i < right + middle; ++i) {
                obj.push_back(i);
            }
        }

    };
    generation(10);
    print(obj);
    generation(10, 2);
    print(obj);


    return 0;
}