#include <iostream>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void print_array(int* arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubble_sort(int *arr, int n){
    for(int i=0; i<n; i++){
        for(int j=1; j<n; j++){
            if(arr[j] < arr[j-1]){
                swap(&arr[j], &arr[j-1]);
            }
        }
        print_array(arr, n);
    }
}

void selection_sort(int *arr, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[i]){
                swap(&arr[i], &arr[j]);
            }
        }
        print_array(arr, n);
    }
}

void insertion_sort(int *arr, int n){
    for(int i=1; i<n; i++){
        int current = arr[i];
        int hole = i;
        while(hole>0 && arr[hole-1]>current){
            arr[hole] = arr[hole-1];
            hole--;
        }
        arr[hole] = current;

        print_array(arr, n);
    }
}

int main(int argc, char** argv){
    const int n=5;
    int arr[n] = {12, 45, 8, 5, 16};
    cout << "Array: " << endl;
    print_array(&arr[0], n);
    cout << "--------------------" << endl;
    insertion_sort(&arr[0], n);
    cout << "--------------------" << endl;
    cout << "Sorted Array: " << endl;
    print_array(&arr[0], n);
    return 0;
}