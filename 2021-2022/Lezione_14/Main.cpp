#include "grafo.h"

int main(){
    grafo<int> g(10);

    g.addVertice(1);
    g.addVertice(2);
    g.addVertice(3);
    g.addEdge(1, 2);
    g.addEdge(3, 2);
}