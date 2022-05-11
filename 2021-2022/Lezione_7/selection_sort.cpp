#include <iostream>
#include <cstdlib>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void print(int arr[], int len){
    for(int i=0; i<len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sel_sort(int arr[], int len){
    int index_Min;
    for(int i=0; i<len; i++){
        index_Min = i;
        for(int j=i+1; j<len; j++){
            if(arr[j] < arr[index_Min])
                index_Min=j;
        }
    swap(arr[i], arr[index_Min]);
    }
}

int main(){

    int n = 10;
    int arr[n];
    for(int i=0; i<n; i++){
        arr[i] = rand()%11;
    }

    print(arr, n);
    sel_sort(arr, n);
    cout << endl;
    print(arr, n);
}