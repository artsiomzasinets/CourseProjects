
#ifndef COURSEPROJECT17_SHAREDPTR_H
#define COURSEPROJECT17_SHAREDPTR_H
template<class T>
class ownPtr{
public:

    ownPtr():pointer(nullptr), counter(nullptr) { std::cout << "Constryctor" << std::endl;}

    ownPtr(T* outPtr)noexcept {
        pointer = outPtr;
        counter = new size_t(1);
        std::cout << "Constryctor" << std::endl;
    }

    ownPtr(ownPtr& outPtr)noexcept {
        if(outPtr.pointer == nullptr){
            pointer = nullptr;
            counter = 0;
            return;
        }
        pointer = outPtr.pointer;
        counter = outPtr.counter;
        *counter += 1;
        std::cout << "Constryctor" << std::endl;
    }

    ownPtr(ownPtr&& outPtr)noexcept {
        pointer = outPtr.pointer;
        counter = outPtr.counter;
        outPtr.pointer = nullptr;
        outPtr.counter = nullptr;
        std::cout << "Constryctor" << std::endl;
    }

    ~ownPtr(){
        std::cout << "Destryctor" << std::endl;
        remove();
    }

    ownPtr& operator=(ownPtr&& outPtr)noexcept{
        std::cout << "operatormove" << std::endl;
        remove();
        pointer = outPtr.pointer;
        counter = outPtr.counter;
        outPtr.pointer = nullptr;
        outPtr.counter = nullptr;
        return *this;
    }

    ownPtr& operator=(ownPtr& outPtr)noexcept {
        std::cout << "operatorcopy" << std::endl;
        pointer = outPtr.pointer;
        counter = outPtr.counter;
        *counter += 1;
        return *this;
    }

    T& operator*()const noexcept {
        return *pointer;
    }

    T* operator->()const noexcept {
        return pointer;
    }

    size_t use_count()const {
        return *counter;
    }

private:
    void remove()noexcept{
        *counter -= 1;
        if(*counter == 0){
            delete pointer;
        }
    }
private:
    T* pointer;
    size_t* counter;
};


#endif //COURSEPROJECT17_SHAREDPTR_H
