#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

template<class C, class V>
std::vector<typename C::iterator> find_all(C &c, V v) {
    std::vector<typename C::iterator> tempObject;
    for (typename C::iterator iter = c.begin(); iter != c.end(); iter++) {
        if (*iter == v) {
            tempObject.push_back(iter);
        }
    }
    return tempObject;
}

template<class T, class F>
typename T::iterator find_if(typename T::iterator b, typename T::iterator e, F f) {
    for(typename T::iterator i = b;i != e;i++){
        if(f(*i)){
            return i;
        }
    }
}

int main() {//own algorithm
    const std::vector<int> data = {1, 3,3,3, 5, 6, 7, 8};
    auto lower = std::upper_bound(data.begin(), data.end(), 3);
    std::cout << *lower << " and index " << std::distance(data.begin(), lower) << std::endl;

    std::vector<int> obj1, obj2;
    srand(time(0));
    for (size_t i = 0; i < 50; i++) {
        obj1.push_back(rand() % 11);
        obj2.push_back(rand() % 50);
    }

    auto result = find_all(obj1, 10);
    for(auto i: result){
        std::cout << "elements "<< *i << " has index = " <<  std::distance(obj1.begin(), i) << std::endl;
    }

    std::cout << "obj1 = ";
    for (auto i: obj1) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::transform(obj1.begin(), obj1.end(), obj2.begin(), [](int var) { return var + 10; });
    std::cout << "obj2 = ";
    for (auto i: obj2) {
        std::cout << i << " ";
    }

    auto res = find_if(obj2.begin(), obj2.end(),[](int a){return a == 20;});
    std::cout << "\nres = " << *res << "\tindex = "<< std::distance(obj2.begin(), res) << std::endl;


    return 0;
}
