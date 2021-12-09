//#include <iostream>
//#include <cmath>
//#include <vector>
//#include <chrono>
//#include <random>
//#include <ctime>
//#include <algorithm>
//#include <iomanip>
//
//
//template<typename T>
//void combSort(T& arr,size_t size) {// сортировака расческой
//
//    double range = 1.247;//const number
//    double temp = size / range;
//    size_t step = std::round(temp);
//    while (temp > 1)
//    {
//        for (size_t h = step, l = 0; h < size; ++h, ++l)
//        {
//            if (arr[l] > arr[h]) {
//                std::swap(arr[l], arr[h]);
//            }
//        }
//        temp /= range;
//        step = std::round(temp);
//    }
//}
//
//template<typename T>
//void simpleSort(T& arr,size_t size) {// сортировака пузырьком
//    for(size_t i = 0; i < size; i++){
//        for(size_t j = 0; j < i; j++){
//            if(arr[j] > arr[i])
//                std::swap(arr[i], arr[j]);
//        }
//    }
//
//
//}
//
//
//template<typename T>
//T&  myfind(std::vector<T>& arr, T elem){
//    for(auto i: arr){
//        if(i == elem){
//            return i;
//        }
//    }
//}
//
//
//
//int main() {//algorithms
//    std::srand(time(0));
//    std::vector<int> obj1, obj2,obj3,obj4,obj5;
//
//    size_t sizeOfElem = 100000;
//    for(size_t i = 0;  i < sizeOfElem; i++){
//        obj1.push_back(rand());
//    }
//    obj2 = obj1;
//    obj3 = obj1;
//    obj4 = obj1;
//    obj5 = obj1;
//    //my sort
//    auto start_time = std::chrono::steady_clock::now();
//    combSort(obj1,obj1.size());
//    auto end_time = std::chrono::steady_clock::now();
//    std::chrono::duration<double> result = end_time - start_time;
//    std::cout << "time of my sort:"<< '\t' << result.count() << std::endl;
//    //simple sort
//    start_time = std::chrono::steady_clock::now();
//    simpleSort(obj5, obj5.size());
//    end_time = std::chrono::steady_clock::now();
//    result = end_time - start_time;
//    std::cout << "time of my simple sort:"<< '\t' << result.count() << std::endl;
//    //standard sort
//    start_time = std::chrono::steady_clock::now();
//    std::sort(obj2.begin(), obj2.end());
//    end_time = std::chrono::steady_clock::now();
//    result = end_time - start_time;
//    std::cout << "time of standard sort:"<< '\t' << result.count() << std::endl;
//    //my find
//    start_time = std::chrono::steady_clock::now();
//    myfind(obj3, 34);
//    end_time = std::chrono::steady_clock::now();
//    result = end_time - start_time;
//    std::cout << "time of my find:"<< '\t' <<std::setprecision(15)<< result.count() << std::endl;
//    //standard find
//    start_time = std::chrono::steady_clock::now();
//    std::find(obj3.begin(), obj3.end(),34);
//    end_time = std::chrono::steady_clock::now();
//    result = end_time - start_time;
//    std::cout << "time of standard find:" <<std::setprecision(15) << '\t' << result.count() << std::endl;
//    return 0;
//}

#include <iostream>

int main()
{



    return 0;
}