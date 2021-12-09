

#ifndef COURSEPROJECT11_QUEUE_H
#define COURSEPROJECT11_QUEUE_H

#include <stdexcept>

template<class T>
class Queue {
private:
    struct Node{
        T elem;
        Node* next;
        Node(): next(nullptr){}
        Node(T& temp): elem(temp), next(nullptr){}
    };
    Node* begin;
    Node* end;
    size_t sizeQ;
    size_t capacity;//TODO capacity
private:
    void copy(const Queue&);
    void remove();// delete Nodes
public:
    Queue();
    Queue(const Queue&);
    Queue(Queue&&);//конструктор перемещения
    ~Queue();
    Queue& operator=(Queue&);
    Queue& operator=(Queue&&);//оператор присваивания перемещением

    bool empty() const;
    size_t size() const;
    void setCapacity(size_t);

    void push(T&);//insert elem to the end
    void push(T&&);
    void pop();//remove first elem

    template<class Q>
    friend std::ostream& operator<<(std::ostream&, const Queue<Q>&);

};

template<class T>
inline void Queue<T>::copy(const Queue<T> &outObj) {

    Node* outPointer = outObj.begin;//указатель на начало внешней очереди
    Node* thisPointer = nullptr;//указатель данной очереди
    try {
        begin = new Node;
        begin->elem = outPointer->elem;
        thisPointer = begin;
        outPointer = outPointer->next;
        sizeQ++;

        while (outPointer){
            thisPointer->next = new Node;
            thisPointer = thisPointer->next;//перемещаем указатель на следующий элемент
            thisPointer->elem = outPointer->elem;
            outPointer = outPointer->next;//перемещаем указатель на следующий элемент
            sizeQ++;

        }
    }catch(std::bad_alloc& ex){
        std::cerr << "Memory couldn't get " << ex.what() << std::endl;
    }
    catch (...){
        std::cerr << "Something bad happened" << std::endl;
    }

    end = thisPointer;
    capacity = outObj.capacity;

}



template<class T>
inline void Queue<T>::remove() {
    if(sizeQ != 0){
        Node* temp = begin;
        while (temp->next){
            temp = temp->next;
            delete begin;
            begin = temp;
        }
        begin = nullptr;
        end = nullptr;
        capacity = sizeQ = 0;
    }
}

template<class T>
inline Queue<T>::Queue():begin(nullptr), end(nullptr), sizeQ(0), capacity(0) {

}
template<class T>
inline Queue<T>::Queue(const Queue<T> & outObj) {
    if(outObj.empty()){
        Queue();
    }else{
        capacity = 0;
        sizeQ = 0;
        begin = nullptr;
        end = nullptr;
        copy(outObj);
    }
}

template<class T>
inline Queue<T>::Queue(Queue<T> &&outObj) {
    begin = outObj.begin;
    end = outObj.end;
    sizeQ = outObj.sizeQ;
    capacity = outObj.capacity;
    outObj.begin = nullptr;
    outObj.end = nullptr;
    outObj.sizeQ = 0;
    outObj.capacity = 0;
}

template<class T>
inline Queue<T>::~Queue<T>() {
    remove();
}


template<class T>
inline Queue<T> &Queue<T>::operator=(Queue<T> &outObj) {
    if(this == &outObj){
        return *this;
    }
    if(!empty()){
        remove();
    }else{
        copy(outObj);
    }
    return *this;
}

template<class T>
inline Queue<T> &Queue<T>::operator=(Queue<T> &&outObj) {
    if(this == &outObj){
        return *this;
    }
    if(!empty()){
        remove();
    }else{
        begin = outObj.begin;
        end = outObj.end;
        sizeQ = outObj.sizeQ;
        capacity = outObj.capacity;
        outObj.begin = nullptr;
        outObj.end = nullptr;
        outObj.sizeQ = 0;
        outObj.capacity = 0;
    }
    return *this;
}

template<class T>
bool Queue<T>::empty() const{
    if(sizeQ == 0){
        return true;
    }else{
        return false;
    }
}

template<class T>
inline  size_t Queue<T>::size() const{
    return sizeQ;
}

template<class T>
inline void Queue<T>::push(T& outElem) {
    try {
        if(sizeQ + 1 == capacity){
            std::cerr << "Can't push. Capacity is full" << std::endl;
            return;
        }

        Node * temp =  new Node(outElem);
        if(sizeQ > 0){
            end->next = temp;
            end = end->next;
            sizeQ++;
        }else{
            capacity = 5;
            begin = new Node(outElem);
            end = begin;
            sizeQ = 1;
        }
    }catch(std::bad_alloc& ex){
        std::cerr << "Memory couldn't get. it's impossible to add new elem " << ex.what() << std::endl;
    }
    catch (...){
        std::cerr << "Something bad happened" << std::endl;
    }

}

template<class T>
inline void Queue<T>::push(T&& outElem) {
    try {
        if(sizeQ + 1 == capacity){
            std::cerr << "Can't push. Capacity is full" << std::endl;
            return;
        }
        Node * temp =  new Node(outElem);
        if(sizeQ > 0){
            end->next = temp;
            end = end->next;
            sizeQ++;
        }else{
            capacity = 5;
            begin = new Node(outElem);
            end = begin;
            sizeQ = 1;
        }
    }catch(std::bad_alloc& ex){
        std::cerr << "Memory couldn't get. it's impossible to add new elem " << ex.what() << std::endl;
    }
    catch (...){
        std::cerr << "Something bad happened" << std::endl;
    }

}

template<class T>
inline void Queue<T>::pop() {
    if(empty()){
        throw std::out_of_range("Queue is empty");
    }
    T ret = begin->elem;
    Node* temp = begin->next;
    delete begin;
    begin = temp;
    sizeQ--;
}
template<class T>
inline std::ostream& operator<<(std::ostream& os, const Queue<T>& outObject) {
    if(outObject.empty()){
        os << "Queue is empty!" << std::endl;
        return os;
    }
    auto tempPointer = outObject.begin;
    os << "Elems:";
    while (tempPointer){
        os << tempPointer->elem << "->";
        tempPointer = tempPointer->next;
    }
    os << std::endl;
    return os;
}

template<class T>
void Queue<T>::setCapacity(size_t c) {
    capacity = c;
}


#endif //COURSEPROJECT11_QUEUE_H
