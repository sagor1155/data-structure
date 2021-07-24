#include <iostream>
#include "doubly_linked_list.hpp"


template <class T>
class Queue{
    private:
    DoublyLinkedList<T>* list = new DoublyLinkedList<T>;

    public:
    ~Queue(){ delete list; }

    Queue(){}

    void print(){
        list->print();
    }

    void clear(){
        list->clear();
    }

    T size(){
        return list->getSize();
    }

    bool isEmpty(){
        return size()==0;
    }

    void enqueue(T elem){
        list->addLast(elem);
    }

    T dequeue(){
        if(isEmpty()) throw "Empty Queue!";
        return list->removeFirst();
    }

    T peek(){
        if(isEmpty()) throw "Empty Queue!";
        return list->peekFirst();
    }

};


int main(int argc, char** argv){
    std::cout << "Queue implementation" << std::endl;
    int n=10;
    try {
        Queue<int> queue;
        for(int i=0; i<n; i++){
            queue.enqueue(i);
        }
        queue.print();
        queue.dequeue();
        queue.dequeue();
        queue.dequeue();
        queue.print();
        std::cout << "peek: " << queue.peek() << std::endl;
      
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }

    return 0;
}