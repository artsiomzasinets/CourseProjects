#ifndef COURSEPROJECT13_QUEUE_H
#define COURSEPROJECT13_QUEUE_H

#include <stdexcept>

namespace own {


    template<class T>
    class Queue {
    public:
        class iterator;

        Queue() noexcept;

        Queue(const Queue &) noexcept;

        Queue(Queue &&) noexcept;//конструктор перемещения
        ~Queue();

        Queue &operator=(Queue &) noexcept;

        Queue &operator=(Queue &&) noexcept;//оператор присваивания перемещением

        bool empty() const noexcept;

        size_t size() const noexcept;

        void push(T &);//insert elem to the end
        void push(T &&);

        void pop();//remove first elem

        iterator &front();

        iterator &back();

    private:
        class QueueException : public std::exception {
        public:
            QueueException() noexcept {
                message = "Something  happened";
            }

            QueueException(const char *message) noexcept {
                this->message = message;
            }

            const char *what() const noexcept override {
                return message;
            }

        private:
            const char *message;
        };

        iterator *queueIterator;// it's object that it has all elements of T type
    };

    template<class T>
    Queue<T>::Queue() noexcept {
        try {
            queueIterator = new iterator();
        } catch (std::bad_alloc &err) {
            std::cerr << err.what() << std::endl;
        } catch (...) {
            std::cerr << "Something bad happened" << std::endl;
        }
    }

    template<class T>
    Queue<T>::Queue(const Queue<T> &outObject) noexcept {
        if (*this == outObject) {
            return;
        }

        try {
            queueIterator = new iterator(*outObject.queueIterator);
        } catch (std::bad_alloc &err) {
            std::cerr << err.what() << std::endl;
        } catch (...) {
            std::cerr << "Something bad happened" << std::endl;
        }
    }

    template<class T>
    Queue<T>::Queue(Queue<T> &&outObject) noexcept {
        if (*this == outObject) {
            return;
        }

        try {
            queueIterator = outObject.queueIterator;
            outObject.queueIterator = new iterator;
        } catch (std::bad_alloc &err) {
            std::cerr << err.what() << std::endl;
        } catch (...) {
            std::cerr << "Something bad happened" << std::endl;
        }


    }

    template<class T>
    Queue<T>::~Queue<T>() {
        delete queueIterator;
    }

    template<class T>
    Queue<T> &Queue<T>::operator=(Queue<T> &outObject) noexcept {
        if (*this == outObject) {
            return *this;
        }

        if (queueIterator != nullptr) {
            delete queueIterator;
        }

        try {
            queueIterator = new iterator(*outObject.queueIterator);
        } catch (std::bad_alloc &err) {
            std::cerr << err.what() << std::endl;
        } catch (...) {
            std::cerr << "Something bad happened" << std::endl;
        }
    }

    template<class T>
    Queue<T> &Queue<T>::operator=(Queue<T> &&outObject) noexcept {
        if (*this == outObject) {
            return *this;
        }

        if (queueIterator == nullptr) {
            delete queueIterator;
        }
        queueIterator = outObject.queueIterator;
        outObject.queueIterator = new iterator;
    }

    template<class T>
    bool Queue<T>::empty() const noexcept {
        return queueIterator->isEmpty();
    }

    template<class T>
    size_t Queue<T>::size() const noexcept {
        return queueIterator->size();
    }

    template<class T>
    void Queue<T>::push(T &elem) {
        queueIterator->push(elem);
    }

    template<class T>
    void Queue<T>::push(T &&elem) {
        queueIterator->push(elem);
    }

    template<class T>
    void Queue<T>::pop() {
        queueIterator->pop();
    }

    template<class T>
    typename Queue<T>::iterator &Queue<T>::front() {
        return *queueIterator;
    }

    template<class T>
    typename Queue<T>::iterator &Queue<T>::back() {
        return *(new iterator);
    }

//--------------------this is iterator below---------------------------------------
    template<class T>
    class Queue<T>::iterator {//iterator of Queue
    public:
        iterator() noexcept {
            begin = nullptr;
            end = nullptr;
            current = nullptr;
            sizeQ = 0;
        }

        ~iterator() {
            while (current) {
                current = current->next;
                delete begin;
                begin = current;
            }
        }

        iterator(const iterator &outIter) noexcept {
            try {
                if (*this == outIter) {
                    return;
                }

                if (outIter.isEmpty()) {
                    iterator();
                    return;
                }

                begin = new Node();
                sizeQ++;
                const Node *consttempPointer = outIter.begin;// temporary pointer
                begin->elem = consttempPointer->elem;//assign  out elem to this->elem
                consttempPointer = consttempPointer->next; // move to forehand Node
                current = begin;//use "current" pointer as moving pointer

                while (consttempPointer != nullptr) {
                    current->next = new Node(consttempPointer->elem);
                    sizeQ++;
                    current->next->previous = current;//assign to the next to Node pointer  named "previous" to the current element
                    current = current->next;
                    consttempPointer = consttempPointer->next;
                }
            } catch (std::bad_alloc &err) {
                std::cerr << err.what() << "\nSome data haven't copied from iterator!" << std::endl;
            } catch (...) {
                std::cerr << "something bad happened" << std::endl;
            }

            end = current;
            current = begin;
        }

        iterator &operator++() noexcept {
            current = current->next;
            return *this;
        }

        iterator &operator++(int) noexcept {
            current = current->next;
            return *this;
        }

        iterator &operator--() noexcept {
            current = current->previous;
            return *this;
        }

        bool operator==(const iterator &outIter) const noexcept {
            return current == outIter.current;
        }

        bool operator!=(const iterator &outIter) const noexcept {
            return current != outIter.current;
        }

        T &operator*() {
            return current->elem;
        }


    public:
        void push(T &elem) {
            if (begin == nullptr) {
                begin = new Node(elem);
                sizeQ++;
                end = current = begin;
            } else {
                end->next = new Node(elem);
                sizeQ++;
                end->next->previous = end;
                end = end->next;
            }
        }

        void pop() {
            if(begin->previous == nullptr){
                delete begin;
                begin = current = end = nullptr;

            }

            if (begin != nullptr) {
                begin = begin->next;
                delete begin->previous;
                begin->previous = nullptr;
                current = begin;
                sizeQ--;
            } else {
                throw QueueException("Queue is empty!");
            }
        }

        void erase() noexcept {
            while (current != nullptr) {
                current = current->next;
                delete begin;
                begin = current;
            }
            begin = end = current = nullptr;
            sizeQ = 0;
        }

//        void erase(iterator& outIter){
//
//        }

        size_t size() const noexcept {
            return sizeQ;
        }

        bool isEmpty() const noexcept {
            return begin == nullptr ? true : false;
        }

    private:
        struct Node {
            T elem;
            Node *next;
            Node *previous;

            Node() : next(nullptr), previous(nullptr) {}

            Node(const T &param) : elem(param), next(nullptr), previous(nullptr) {}
        };

        Node *begin;//pointer to begin
        Node *end;// pointer to end of queue
        Node *current;// using only for loops
        size_t sizeQ;// size of queue
    };


}


#endif //COURSEPROJECT13_QUEUE_H
