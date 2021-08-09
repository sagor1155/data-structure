#include <iostream>

using namespace std;

template <class T>
class MinHeap
{
    private:
        T *items;
        int size = 0;
        int capacity = 10;

        int getLeftChildIndex(int parentIndex) { return (2*parentIndex + 1); }
        int getRightChildIndex(int parentIndex){ return (2*parentIndex + 2); }
        int getParentIndex(int childIndex)     { return (childIndex - 1)/2; }
        
        bool hasLeftChild(int index)  { return getLeftChildIndex(index)<size; }
        bool hasRightChild(int index) { return getRightChildIndex(index)<size; }
        bool hasParent(int index)     { return getParentIndex(index)>0; }



        void ensureCapacity(){
            if(size==capacity){
                if(capacity==0) capacity=1;
                else capacity *= 2;

                T *arr = new T(capacity);
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
            T temp = items[indexOne];
            items[indexTwo] = items[indexOne];
            items[indexOne] = temp;
        }

        void removeLast(){
            items[size-1] = 0;
            shrink();
        }

    public:
        MinHeap(){
            items = new T(capacity);
        }

        ~MinHeap(){
            delete[] items;
        }

        int getSize(){
            return size;
        }

        int getCapacity(){
            return capacity;
        }

        void clear(){
            for(int i=0; i<capacity; i++){
                items[i] = 0;
            }
            size = 0;
        }

        T peek(){
            if(size==0) throw "Heap is Empty!";
            return items[size-1];
        }

        T poll(){
            if(size==0) throw "Heap is Empty!";
            T item = items[0];
            swap(0, size-1);
            removeLast();
            heapifyDown();
            return item;
        }

        void add(T elem){
            ensureCapacity();
            items[size] = elem;
            size++;
            heapifyUp();
        }

        void heapifyDown(){

        }

        void heapifyUp(){

        }

};


int main(int argc, char** argv){
    cout << "Binary Minimum Heap\n";

    try {
        MinHeap<int> *heap = new MinHeap<int>();

        delete heap;
    }catch (const char* msg) {
        cerr << msg << endl;
    }
    
}