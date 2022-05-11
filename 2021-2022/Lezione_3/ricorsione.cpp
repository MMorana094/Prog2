#include <iostream>

using namespace std;

int fattoriale(int n){
    if(n==0){
        return 1;
    } else {
        return n*fattoriale(n-1);
    }
}

int FB(int n){
    if(n == 0 || n == 1){
        return 1;
    } else {
        return FB(n-1) + FB(n-2);
    }

}

int FB2(int n){
    if(n == 0 || n == 1){
        return 1;
    }

    //Sum_1 = somma fino all'iterazione n-1 
    //Sum_2 = somma fino all'iterazione n-2
    int sum_1 = 1, sum_2 = 1, x;
    for(int i=2; i<=n; i++){
        x = sum_2;
        sum_2 = sum_1;
        sum_1 = x + sum_2;
    }
    return sum_1;
}

int main(){
    cout << "FATTORIALI" << endl;
    cout << fattoriale(2) << endl << fattoriale(3) << endl << fattoriale(5) << endl << fattoriale(10) << endl;
    cout << "FIBONACCI" <<endl;
    cout << endl << FB(2) << endl << FB(3) << endl << FB(10) << endl << FB(21) << endl;
    cout << endl << FB2(2) << endl << FB2(3) << endl << FB2(10) << endl << FB2(21) << endl;
}