#include <iostream>
#include "linked_list.hpp"

int main(int argc, char** argv){
    std::cout << "Singly linked list implementation" << std::endl;

    try {
        LinkedList<int> list;
        for(int i=1; i<11; i++){
            list.addFirst(i);
        }
        list.print();
        std::cout << "removed: " << list.removeFirst() << std::endl;
        list.print();
        std::cout << "removed: " << list.removeLast() << std::endl;
        list.print();
        std::cout << "removed: " << list.removeFirst() << std::endl;
        list.print();
        std::cout << "removed: " << list.removeLast() << std::endl;
        list.print();
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }

    return 0;
}