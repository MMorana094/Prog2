#include <iostream>

using namespace std;

int main(){
    int arr1[100];
    cout << "byte Arr1 = " << sizeof(arr1) << endl;

    for(int i=0; i<100; i++){
        cout << arr1[i] << " ";
    }
    cout << endl << endl;

    int arr2[] = {11, 12, 13, 14};
    cout << "byte Arr2 = " << sizeof(arr2) << endl;
    int n_arr2 = sizeof(arr2)/ sizeof(int);
    cout << "nell'array2 vi sono " << n_arr2 << " elementi" << endl;

    for(int i=0; i<n_arr2; i++){
        cout << "\t" << arr2[i];
    }
    cout << endl;
    int* arr3 = new int[100];
    cout << sizeof(*arr3) << endl;
}