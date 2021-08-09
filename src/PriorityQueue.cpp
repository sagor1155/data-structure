#include <iostream>
#include "PriorityQueue.hpp"

using namespace std;

int main(int argc, char** argv){
    cout << "Priority Queue Using MinHeap\n";

    try {
        PriorityQueue<int> *pqueue = new PriorityQueue<int>();
        for(int i=1; i<16; i++){ 
            pqueue->add(i);
        }
        pqueue->add(3);
        pqueue->print();
        // pqueue->poll();
        // pqueue->print();
        // pqueue->poll();
        // pqueue->print();
        // pqueue->add(1);
        // pqueue->print();
        // pqueue->add(3);
        // pqueue->print();      

        // pqueue->removeAt(7);
        pqueue->remove(8);
        pqueue->print();

        while(!pqueue->isEmpty()){
            cout << pqueue->poll() << "  ";
        }
        cout << "\n";
        
        delete pqueue;
    }catch (const char* msg) {
        cerr << msg << endl;
    }
}