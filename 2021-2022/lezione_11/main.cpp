#include "node_list.h"
#include "List.h"
#include "stack.h"
#include <cstdlib>

#define DIM 10
using namespace std;


int main() {
    List<int> lista;
    Stack<int> stack;

    for(int i=0; i<DIM; i++){
        lista.insertHead(rand()%50);
        stack.push(rand()%15);

    }

    cout << lista << endl;
    lista.removeHead();
    lista.removeHead();
    lista.removeHead();
    cout << lista << endl;
    lista.insertInOrderAscending(40);
    lista.insertInOrderAscending(38);
    lista.insertInOrderAscending(50);
    cout << lista << endl;

    cout << stack << endl;
    stack.pop();
    stack.pop();
    stack.pop();
    cout << stack << endl;



}