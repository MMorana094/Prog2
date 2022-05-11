#include <iostream>

using namespace std;

void primi(int* arrPrimi, int &cont, int n){
    cont = 0;
    for(int i=2; i<=n; i++){
        bool primo = true;

        for(int j=2; j<(i/2)+1; j++){
            if(i%j == 0){
                primo = false;
                break;
            }
        }
        if(primo == true){
            cout << i << " è primo." << endl;
            arrPrimi[cont++] = i;
        }
    }
}

int main(){
    int primo[3];
    int count;
    primi(primo, count, 7);
    cout << endl;
    for(int i=0; i<count; i++){
        cout << primo[i] << " ";
    }
}