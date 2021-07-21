#include <iostream>

template <class T>
class DynamicArray
{
private:
    T* arr;
    int capacity;
    int len;
public:
    ~DynamicArray(){}
    DynamicArray(){}
    DynamicArray(int capacity){
        if(capacity < 0){
            throw "Illegal Capacity!";
        }
        this->capacity = capacity;
        arr = (T*) new T(capacity);
        this->len = 0;
    }

    int size(){
        return this->len;
    }

    bool isEmpty(){
        return (this->size()==0);
    }

    void clear(){
        for(int i=0; i<this->capacity; i++){
            this->arr[i] = NULL;
        }
        this->len = 0;
    }

    T get(int index){
        if(index >= len || index < 0){
            throw "Index out of bound!";
        }
        return arr[index];
    }

    void set(int index, T elem){
        if(index >= this->len || index < 0){
            throw "Index out of bound!";
        }
        this->arr[index]  = elem;
    }

    void append(T elem){
        if(len+1 >= capacity){
            if(capacity==0) capacity=1;
            else capacity *= 2;

            T* new_arr = (T*) new T(capacity);
            for(int i=0; i<len; i++){
                new_arr[i] = arr[i];
            }
            arr = new_arr;  // arr has extra nulls padded
        }

        arr[len++] = elem;
    }

};


int main(int argc, char** argv){
    std::cout << "Dynamic array implementation" << std::endl;
    
    try {
        DynamicArray<int> darray(512);

    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }

    return 0;
}