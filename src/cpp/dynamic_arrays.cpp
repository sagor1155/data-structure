#include <iostream>
#include "dynamic_arrays.hpp"


int main(int argc, char** argv){
    std::cout << "Dynamic array implementation" << std::endl;
    int capacity = 10;
    try {
        DynamicArray<int> darray;
        for(int i=0; i<capacity*3; i++){
            darray.append(i);
        }
        darray.print();
        darray.removeAt(1);
        darray.print();    
        darray.set(1, 9);
        darray.print();
        std::cout << "Value at index 1: " << darray.get(1) << std::endl;
        std::cout << "Index of 28: " << darray.indexOf(28) << std::endl;
        std::cout << "Remove 29: " << darray.remove(29) << std::endl;
        darray.print();
        std::cout << "Before clear - IsEmpty?: " << darray.isEmpty() << std::endl;
        darray.clear();
        std::cout << "After  clear - IsEmpty?: " << darray.isEmpty() << std::endl;

    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }

    return 0;
}