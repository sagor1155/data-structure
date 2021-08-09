#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>

template <class T>
class DynamicArray
{
    private:
    T* arr;
    int capacity;
    int len;

    public:
    ~DynamicArray() { delete[] arr; }
    
    DynamicArray() : arr(NULL) { }

    DynamicArray(int capacity){
        if(capacity < 0){
            throw "Illegal Capacity!";
        }
        this->capacity = capacity;
        arr = (T*) new T[capacity];
        this->len = 0;
    }

    // print array
    void print(){
        std::cout << "[ARRAY]  ";
        for(int i=0; i<len; i++){
            std::cout << arr[i] << "  " ;
        }
        std::cout << "" << std::endl;
    }

    // get the array size
    int size(){
        return this->len;
    }

    // check empty
    bool isEmpty(){
        return (this->size()==0);
    }

    // clear whole array data
    void clear(){
        for(int i=0; i<this->capacity; i++){
            this->arr[i] = 0;
        }
        this->len = 0;
    }

    // get data from specific index
    T get(int index){
        if(index >= len || index < 0){
            throw "Index out of bound!";
        }
        return arr[index];
    }

    // set data to specific index
    void set(int index, T elem){
        if(index >= this->len || index < 0){
            throw "Index out of bound!";
        }
        this->arr[index]  = elem;
    }

    // append data at the end 
    void append(T elem){
        if(len+1 >= capacity){
            if(capacity==0) capacity=1;
            else capacity *= 2;

            T* new_arr = new T[capacity];
            for(int i=0; i<len; i++){
                new_arr[i] = arr[i];
            }
            arr = new_arr;  // arr has extra nulls padded
        }

        arr[len++] = elem;
    }

    // remove data from specific index
    T removeAt(int index){
        if(index >= len || index < 0){
            throw "Index out of bound!";
        }
        T data = arr[index];
        T* new_arr = new T[len-1];
        for(int i=0, j=0; i<len; i++, j++){
            if(i==index){
                j--;
            }else{
                new_arr[j] = arr[i];
            }
        }
        arr = new_arr;
        capacity = --len;
        return data;   
    }

    bool remove(T data){
        for(int i=0; i<len; i++){
            if(arr[i]==data){
                this->removeAt(i);
                return true;
            }
        }
        return false;
    }

    int indexOf(T data){
        for(int i=0; i<len; i++){
            if(arr[i]==data){
                return i;
            }
        } 
        return -1;       
    }

};



#endif  // DYNAMIC_ARRAY_H