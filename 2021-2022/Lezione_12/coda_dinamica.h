#ifndef CODA_DINAMICA_H
#define CODA_DINAMICA_H

#include "DLList.h"

template<typename T>
class Queue : protected DLList<T>{
private:
	int size;

public:
	Queue() : DLList<T>(){

    }

	bool isEmpty(){
        return size == 0;
        }

	void enqueue(T val){
		DLList<T>::insertTail(val);
		size++;

		return;
	}

	DLNode<T>* dequeue(){
		if(isEmpty())
			return nullptr;

		DLNode<T>* ptr = DLList<T>::getHead();
		DLList<T>::removeHead();
		size--;

		return ptr;
	}

	friend ostream& operator<< (ostream& os, Queue<T>& obj){
		if(obj.isEmpty()){
			os << "\nEmpty Queue" << endl;
			return os;
		}

		os << "\nQueue: " << endl;
		os << "\nSize=" << obj.size << endl;

		DLNode<T>* ptr  = obj.Head;
		os << "\nQueue starting at: " << *ptr << endl;

		while(ptr){
			os << " " << *ptr;
			ptr = ptr->getNext();
		}

		return os << "\nEnd Queue" << endl;
	}
};

#endif