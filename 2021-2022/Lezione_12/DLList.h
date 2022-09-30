#ifndef DLLIST_H
#define DLLIST_H

#include "DLNode.h"

template<typename T>
class DLList{

protected:
	DLNode<T>* Head;
	DLNode<T>* Tail;

public:

	DLList(){
		Head = nullptr;
		Tail = nullptr;
	}

	DLNode<T>* getHead(){
        return this->Head;
        }

	DLNode<T>* getTail(){
        return this->Tail;
        }

	bool isEmpty(){
        return (!Head && !Tail);
        }

	void insertHead(T val){
		if(isEmpty())		{
			Head = new DLNode<T>(val);
			Tail = Head;
			return;
		}

		DLNode<T>* toinsert = new DLNode<T>(val);
		toinsert->Next = Head;
		Head->Prev = toinsert;
		Head = toinsert;
		return;
	}

	void insertTail(T val){
		if(isEmpty()){
			insertHead(val);
			return;
		}

		DLNode<T>* toinsert = new DLNode<T>(val);
		Tail->Next = toinsert;
		toinsert->Prev = Tail;
		Tail = toinsert;
		return;
	}

    	void insertInOrder(T val, char c){

		do{
			if(c == 'a'){
				insertInOrderAscending(val);
				return;
			}
			else if(c == 'd'){
				insertInOrderDescending(val);
				return;
			}   else    {
				cerr << "\nChose between 'a' or 'd' ! " << endl;
				cin >> c;
			}

		}while(c != 'a' && c != 'd');
	}

	void insertInOrderAscending(T val){
		if(isEmpty() || val <= Head->val){
			insertHead(val);
			return;
		}

		if(val >= Tail->val){
			insertTail(val);
			return;
		}

		DLNode<T>* cur = Head;

		while(cur->Next && val >= cur->val){
			if(val < cur->Next->val){
				break;
                }

			cur = cur->Next;
		}

		DLNode<T>* toinsert = new DLNode<T>(val);

		toinsert->Next = cur->Next;
		toinsert->Prev = cur;

		cur->Next->Prev = toinsert;
		cur->Next = toinsert;
		return;
	}

	void insertInOrderDescending(T val){
		if(isEmpty() || val >= Head->val){
			insertHead(val);
			return;
		}

		if(val <= Tail->val){
			insertTail(val);
			return;
		}

		DLNode<T>* cur = Head;

		while(cur->Next && val <= cur->val){
			if(val > cur->Next->val){
				break;
                }

			cur = cur->Next;
		}

		DLNode<T>* toinsert = new DLNode<T>(val);
		
		toinsert->Next = cur->Next;
		toinsert->Prev = cur;

		cur->Next->Prev = toinsert;
		cur->Next = toinsert;
		return;
	}

    void removeHead(){
		if(isEmpty()){
			cerr << "Empty List! Operation isn't avaible! " << endl;
			return;
		}

		DLNode<T>* ptr = Head;
		Head = Head->Next;
		ptr->Next->Prev = nullptr;
		delete ptr;

		return;
	}

	void removeTail(){
		if(isEmpty()){
			cerr << "Empty List! Operation isn't avaible! " << endl;
			return;
		}

		DLNode<T>* ptr = Tail;
		Tail->Prev->Next = nullptr;
		Tail= Tail->Prev;
		delete ptr;

		return;
	}

	DLNode<T>* search(T val){
		if(isEmpty()){
			throw out_of_range("...list is empty...");
            }

		if(Head->val == val){
			return Head;
            }

		DLNode<T>* cur = Head;

		while(cur->Next && cur->val != val){
			cur = cur->Next;
            }
		
		if(cur->val != val){
			cerr << "Element with key " << val << " not found!" << endl;
			return nullptr;
		}

		return cur;
	}

	void removeElement(T val){
		if(isEmpty()){
			cerr << "Empty List! Operation isn't avaible! " << endl;
			return;
		}
		
		DLNode<T>* toremove = search(val);

		if(!toremove){
			return;
            }

		if(toremove->val == Head->val){
			removeHead();
			return;
		}

		if(toremove->val == Tail->val){
			removeTail();
			return;
		}

		DLNode<T>* cur = Head;

		while(cur->Next && cur->val != toremove->val){
			cur = cur->Next;
            }

		cur->Prev->Next = cur->Next;
		cur->Next->Prev = cur->Prev;
		delete cur;
	}

	friend ostream& operator<< (ostream& os,  DLList<T>& obj){
		if(obj.isEmpty()){
			return os << "\nEmpty List !" << endl;
		}
		os << "\nHead: " << *obj.Head << "\tTail: " << *obj.Tail << endl;
		os << "\nDouble_linked_list: " << endl;

		DLNode<T>* ptr = obj.Head;
		os << "\nHead --> ";
		while(ptr){
			if(ptr != obj.Tail){
				os << *ptr << " <--> ";
				}else{
				os << *ptr << " --> ";
			}
			ptr = ptr->getNext();
		}

		return os << "NIL" << endl << "\nEnd List\n" << endl; 
	}

};

#endif