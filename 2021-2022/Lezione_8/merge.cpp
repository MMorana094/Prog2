#include <iostream>
#include <ctime>
#include <climits>
#include <fstream>
using namespace std;

/* 
    METODO NATURAL MERGE 
si prendono due array ordinati con qualsiasi dimensione e li si uniscono
in un unico array ordinato.
Es.
[3 5 7 8 11 13] + [4 7 9 14 15] =
[3 4 5 7 7 8 9 11 13 14 15]

*/

void print(int *v, int n){
    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}


void rmerge(int *A, int n, int *B, int m, int *C){
    if(n==0 && m==0){
        return;
    }
    if(n==0){
        C[0] = B[0];
        rmerge(A, n, B+1, m-1, C+1);
        return;
    }
    if(m==0){
        C[0] = A[0];
        rmerge(A+1, n-1, B, m, C+1);
        return;
    }
    if(A[0]<B[0]){
        C[0] = A[0];
        rmerge(A+1, n-1, B, m, C+1);
    } else {
        C[0] = B[0];
        rmerge(A, n, B+1, m-1, C+1);
    }
}

void rmerge2(int *A, int n, int *B, int m, int *C){
    if(n==0 && m==0){
        return;
    }
    if( m == 0 ||(n>0 && A[0]<B[0])){
        C[0] = A[0];
        rmerge2(A+1, n-1, B, m, C+1);
    } else {
        C[0] = B[0];
        rmerge2(A, n, B+1, m-1, C+1);
    }
}

void nmerge(int *A, int n, int *B, int m, int *C){
int i , j, k;
i = j = k = 0;
while(i<n && j<m){
    if(A[i]<B[j]){
        C[k++] = A[i++];
    } else {
        C[k++] = B[j++];
        }
    }
        while(j<m){
            C[k++] = B[j++];
        } 
        while(i<n){
            C[k++] = A[i++];
        }  
}

int main(){

    int b[] = {3, 5, 7, 8, 11, 13};
    int a[] = {4, 7, 9, 14, 15};
    int m = 6;
    int n = 5;
    int c[n+m];

    print(a, n);
    print(b, m);
    nmerge(a, n, b, m, c);
    print(c, n+m);

    

}