#include <iostream>
#include <cstdlib>

using namespace std;

void insertion(int arr[], int len){
    int temp, j;

    for(int i=1; i<len; i++){
        temp = arr[i];
        for(int j=i; j>0;  j--){
            if(temp < arr[j-1]){
                arr[j] = arr[j-1];
            } else {
                break;
            }
        }
    arr[j] = temp;
    }
}

void insertion2(int arr[], int len){
    int temp, j;
    for(int i=1; i<len; i++) { 
		temp=arr[i]; 
            j=i-1; 
		while((arr[j]>temp) && (j>=0)) { 
			    arr[j+1]=arr[j]; 
                j--;
            } 
		arr[j+1]=temp; 
		} 
}

void print(int arr[], int len){
    for(int i=0; i<len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int n = 10;
    int arr[n];
    for(int i=0; i<n; i++){
        arr[i] = rand()%11;
    }

    print(arr, n);
    insertion2(arr, n);
    cout << endl;
    print(arr, n);
    
}