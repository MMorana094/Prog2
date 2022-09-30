#include "sorting.h"
#include <cstdlib>

#define DIM 10

int main(){

    int* arr = new int[DIM];
    int* arr1 = new int[DIM];
    int* arr2 = new int[DIM];;
    int* arr3 = new int[DIM];
    int* arr4 = new int[DIM];

    for(int i=0; i<DIM; i++){
        arr[i] = rand()%50;
        arr1[i] = rand()%50;
        arr2[i] = rand()%50;
        arr3[i] = rand()%50;
        arr4[i] = rand()%50;
    }

    cout << "Selection Sort : "<< endl;
    cout << "before : " << endl;
    print(arr,DIM);
    cout << "after : " << endl;
    selection_sort(arr, DIM);
    print(arr, DIM);
    cout << endl;

    cout << "Insertion Sort : " << endl;
    cout << "before : " << endl;
    print(arr1,DIM);
    cout << "after : " << endl;
    insertion_sort(arr1, DIM);
    print(arr1, DIM);
    cout << endl;

    cout << "Quick Sort : " << endl;
    cout << "before : " << endl;
    print(arr2,DIM);
    cout << "after : " << endl;
    quick_sort(arr2, DIM);
    print(arr2, DIM);
    cout << endl;

    cout << "Bubble Sort : " << endl;
    cout << "before : " << endl;
    print(arr3,DIM);
    cout << "after : " << endl;
    bubble_sort(arr3, DIM);
    print(arr3, DIM);
    cout << endl;

    cout << "Merge Sort : " << endl;
    cout << "before : " << endl;
    print(arr4,DIM);
    cout << "after : " << endl;
    bubble_sort(arr4, DIM);
    print(arr4, DIM);
    cout << endl;
}