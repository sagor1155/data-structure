#include <iostream>
#include "linked_list.hpp"

template <class T>
class Stack{
    private:
    LinkedList<T>* list = new LinkedList<T>;

    public:
    Stack(){}
    ~Stack(){ delete list; } 

    void print(){
        list->print();
    }

    int size(){
        return list->getSize();
    }

    void clear(){
        list->clear();
    }

    bool isEmpty(){
        return size()==0;
    }

    void push(T elem){
        list->addLast(elem);
    }

    T pop(){
        if(isEmpty()) throw "Empty Stack!";
        return list->removeLast();
    }

    T peek(){
        return list->peekLast();
    }
};


int main(int argc, char** argv){
    std::cout << "Stack implementation" << std::endl;
    int n=10;
    try {
        Stack<int> stack;
        for(int i=0; i<n; i++){
            stack.push(i);
        }
        stack.print();
        stack.pop();
        stack.pop();
        stack.pop();
        stack.print();
        std::cout << "peek: " << stack.peek() << std::endl;
      
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }

    return 0;
}