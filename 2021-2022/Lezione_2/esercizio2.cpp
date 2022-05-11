#include <iostream>

#define MAX_N 100

using namespace std;

void leggiElementi(double* v, int& num){
    num = 0;
    double temp;
    cout << "inserisci elemento, premere 0 per uscire" << endl;
    for(int i=0; i<MAX_N; i++){
        cin >> temp;
        if(temp == 0){
            break;
        } else {
            v[i] = temp;
            num++;
        }
    }
}

void stampaElementi(double* v, int num){
    for(int i=0; i<num; i++){
        cout << i << ")" << v[i] << endl;
    }
    cout << endl;
}

int main(){
    
    double* arr = new double[MAX_N];
    int x;
    int num = 0;
    leggiElementi(arr, num);
    cout << endl;
    stampaElementi(arr, num);
        
}