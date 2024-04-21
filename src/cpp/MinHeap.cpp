#include <iostream>
#include "MinHeap.hpp"

using namespace std;


int main(int argc, char** argv){
    cout << "Binary Minimum Heap\n";

    try {
        MinHeap<int> *heap = new MinHeap<int>();
        for(int i=1; i<16; i++){
            // for min heap
            heap->add(i);

            // for max heap 
            // heap->add((-1) * i);
        }
        heap->print();
        heap->poll();
        heap->print();
        heap->poll();
        heap->print();
        heap->add(1);
        heap->print();
        heap->add(3);
        heap->print();

        int n = heap->getSize();
        for(int i=0; i<n; i++){
            // for min heap
            cout << heap->poll() << "  ";

            // for max heap
            // cout << (-1) * heap->poll() << "  ";
        }
        cout << "\n";
        delete heap;
    }catch (const char* msg) {
        cerr << msg << endl;
    }
    
}