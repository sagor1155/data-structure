#include <iostream>
#include "doubly_linked_list.hpp"


int main(int argc, char** argv){
    std::cout << "Doubly linked list implementation" << std::endl;

    try {
        DoublyLinkedList<int> list;
        for(int i=1; i<11; i++){
            list.addLast(i);
        }
        list.print();
        std::cout << "removed: " << list.removeFirst() << std::endl;
        list.print();
        std::cout << "removed: " << list.removeLast() << std::endl;
        list.print();
        std::cout << "removed: " << list.removeAt(3) << std::endl;
        list.print();
        std::cout << "removed: " << list.removeAt(6) << std::endl;
        list.print();

        list.remove(3);
        list.print();

    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }

    return 0;
}