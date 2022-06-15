#include "bst.h"
#include "bst_node.h"
#include <iostream>

using namespace std;

int main(){

    BST<int> bst;

    try {
        bst.max();
    }
    catch (const char*) {
        cout << "Empty BST" << endl;
    }
    bst.insert(5);
    bst.insert(10);
    bst.insert(15);
    bst.insert(7);
    bst.insert(8);
    bst.insert(3);
    bst.insert(1);

    bst.inorder();

    cout << "\n MIN E MAX" << endl;

    cout << "\n" << *(bst.min()) << endl;
    cout << *(bst.max()) << endl;

    cout << "\n Root e Successore" << endl;

    cout << "\n" <<*bst.getRoot() << endl;
    cout << *(bst.successor(bst.getRoot())) << endl;

/*
    cout << "\n Cancellazione " << endl;
    
    BSTNode<int>* cancellato1 = bst.remove(10);
    bst.inorder(); 
*/


}