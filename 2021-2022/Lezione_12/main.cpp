#include "DLList.h"
#include "coda_dinamica.h"
#include <cstdlib>

#define DIM 10

int main(){
    DLList<int> List1;
    Queue<int> Queue1;

    for(int i=0; i<DIM; i++){
        List1.insertHead(rand()%50);
        Queue1.enqueue(rand()%50);
    }

    cout << List1 << endl;
    List1.removeHead();
    List1.removeHead();
    List1.removeHead();
    List1.removeTail();
    cout << List1 << endl;

    cout << Queue1 << endl;
    Queue1.dequeue();
    Queue1.dequeue();
    Queue1.dequeue();
    Queue1.dequeue();
    cout << Queue1 << endl;
}