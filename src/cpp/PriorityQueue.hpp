#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
#include "MinHeap.hpp"

template <class T>
class PriorityQueue{
    private:
        MinHeap<T> *heap;

    public:
        PriorityQueue(){
            heap = new MinHeap<T>();
        }

        ~PriorityQueue(){
            delete heap;
        }

        int size(){
            return heap->getSize();
        }

        void clear(){
            heap->clear();
        }

        bool isEmpty(){
            return size()==0;
        }

        void print(){
            heap->print("PQUEUE");
        }

        T peek(){
            return heap->peak();
        }

        void add(T elem){
            heap->add(elem);
        }

        T poll(){
            return heap->poll();
        }

        bool remove(T elem){
            return heap->remove(elem);
        }

        T removeAt(int index){
            return heap->removeAt(index);
        }


};

#endif // PRIORITY_QUEUE_H