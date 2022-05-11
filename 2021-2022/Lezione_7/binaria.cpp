#include <iostream>
#include <cstdlib>

using namespace std;

bool Binaria(int arr[], int len, int value){ //PER ARRAY ORDINATI
    bool found = false;
    int start = 0;
    int end = len-1;
    while(!found && (start != end)){
        int mid = start + ((end-start)/2);

    cout << "start=" << start << ", end=" << end << ", mid=" << mid << endl;

        if(arr[mid] == value){
            found = true;
            cout << "trovato" << endl;
        } else if(value < arr[mid]){    //metà inferiore
        //qui bisogna aggiornare la fine e il punto di mezzo
            end = mid;
            //mid = (len-start)/2;
        } else {
            start = mid+1;
            //mid = (len-start)/2;
        }
    }
    return found;
}

int main(){
    int n = 10;
    int arr[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Binaria(arr, n, 2);

}