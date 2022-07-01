#include <iostream>
#include <climits>

using namespace std;

void update (int *a, int *b){
    *a = *a + *b;
    *b = - (*a + *b);


}

int main(){

    int a = 4 , b = 5;
    int *pa = &a, *pb = &b;

    update(pa, pb);
    cout << a << endl << b << endl;

}