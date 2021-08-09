#ifndef MINIMUM_HEAP_H
#define MINIMUM_HEAP_H

#include <iostream>

using namespace std;

template <class T>
class MinHeap
{
    private:
        T *items;
        int size = 0;
        int capacity = 0;
        
        int getLeftChildIndex(int parentIndex) { return (2*parentIndex + 1); }
        int getRightChildIndex(int parentIndex){ return (2*parentIndex + 2); }
        int getParentIndex(int childIndex)     { return (childIndex - 1)/2; }
        
        bool hasLeftChild(int index)  { return getLeftChildIndex(index)<size; }
        bool hasRightChild(int index) { return getRightChildIndex(index)<size; }
        bool hasParent(int index)     { return getParentIndex(index)>=0; }

        T leftChild(int index)  { return items[getLeftChildIndex(index)]; }
        T rightChild(int index) { return items[getRightChildIndex(index)]; }
        T parent(int index)     { return items[getParentIndex(index)]; }

        void ensureCapacity(){
            if(size==capacity){
                if(capacity==0) capacity=1;
                else capacity *= 2;

                T *arr = new T[capacity];
                for(int i=0; i<size; i++){
                    arr[i] = items[i];
                }
                items = arr;
            }
        }

        void shrink(){
            if(size > 0){
                T* arr = new T[size-1];
                for(int i=0; i<size-1; i++){
                    arr[i] = items[i];
                }
                items = arr;
                capacity = --size;
            }
        }

        void swap(int indexOne, int indexTwo){
            if(indexOne >= size || indexTwo >= size) throw "Index Out of Bound!";
            T temp = items[indexTwo];
            items[indexTwo] = items[indexOne];
            items[indexOne] = temp;
        }

        void removeLast(){
            items[size-1] = 0;
            shrink();
        }

        void heapifyDown(int index){    // index = 0 for root element 
            while(hasLeftChild(index)){
                int smallerChildIndex = getLeftChildIndex(index);
            
                if(hasRightChild(index) && rightChild(index)<leftChild(index)){
                    smallerChildIndex = getRightChildIndex(index);
                }

                if(items[index] < items[smallerChildIndex]){
                    break;
                }else{
                    swap(index, smallerChildIndex);
                    index = smallerChildIndex;
                }
            }
        }

        void heapifyUp(int index){  // index = 0 for last element 
            while (hasParent(index)){
                if(items[index] >= parent(index)){
                    break;
                }else{
                    swap(index, getParentIndex(index));
                    index = getParentIndex(index);
                }
            }
        }

    public:
        MinHeap(){
            size = 0;
            capacity = 0;
            items = NULL;
        }

        MinHeap(int capacity){
            size = 0;
            this->capacity = capacity;
            items = new T[this->capacity];
        }

        ~MinHeap(){
            delete items;
        }

        int getSize(){
            return size;
        }

        int getCapacity(){
            return capacity;
        }

        bool isEmpty(){
            return getSize()==0;
        }

        void clear(){
            for(int i=0; i<capacity; i++){
                items[i] = 0;
            }
            size = 0;
        }

        void print(){
            cout << "[Heap: " << size << "]  ";
            for(int i=0; i<size; i++){
                cout << items[i] << "  ";
            }
            cout << "\n";
        }

        void print(string str){
            cout << "[" <<  str << ": " << size << "]  ";
            for(int i=0; i<size; i++){
                cout << items[i] << "  ";
            }
            cout << "\n";
        }

        T peek(){
            if(size==0) throw "Heap is Empty!";
            return items[size-1];
        }

        T poll(){
            if(size==0) throw "Heap is Empty!";
            T item = items[0];
            swap(0, size-1);    // items[0] = items[size-1];
            removeLast();       // size--;
            heapifyDown(0);
            return item;
        }

        void add(T elem){
            ensureCapacity();
            items[size] = elem;
            size++;
            heapifyUp(size-1);
        }

        bool remove(T elem){
            // Linear removal via search, O(n)
            for(int i=0; i<size; i++){
                if(items[i]==elem){
                    removeAt(i);
                    return true;
                }
            }

            // Logarithmic removal with map, O(log(n))
            
            return false;
        }

        T removeAt(int index){
            if(index >= size) throw "Index Out of Bound!";
            T item = items[index];
            items[index] = items[size-1];
            size--;
            if(hasParent(index) && (parent(index) > items[index])){
                heapifyUp(index);
            }else{
                heapifyDown(index);
            }
            return item;
        }

};

#endif // MINIMUM_HEAP_H