

#ifndef COURSEPROJECT11_QUEUE_H
#define COURSEPROJECT11_QUEUE_H

template<class T>
class Queue {
private:
    struct Node{
        T elem;
        Node* previous;
        Node* next;
    };


    Node* begin;
    Node* end;
private:
public:
    Queue();
    Queue(size_t );
    Queue(const Queue&);

};



#endif //COURSEPROJECT11_QUEUE_H
