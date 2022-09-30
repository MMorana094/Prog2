#ifndef DLNODE_H
#define DLNODE_H

#include <iostream>

using namespace std;

template<typename T>
class DLNode{

	T val;
	DLNode<T>* Next;
	DLNode<T>* Prev;

	template<typename U>
	friend class DLList;

public:

	DLNode(T val){
        this->val = val;
		this->Next = nullptr;
		this->Prev = nullptr;
	}

	T getVal(){
        return this->val;
        }

	DLNode<T>* getNext(){
        return this->Next;
        }

	DLNode<T>* getPrev(){
        return this->Prev;
        }

	friend ostream& operator<< (ostream& os, const DLNode<T>& obj){
        os << "Node Key = " << obj.val << endl;
        return os;
        }
};

#endif