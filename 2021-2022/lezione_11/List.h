#ifndef LIST_H
#define LIST_H

#include "node_list.h"

template <typename T>
class List{
    private:
        Node<T>* head;

    public:
        List(){head = nullptr;}

        Node<T>* getHead(){
			return this->head;
		}

        bool isEmpty(){
            return (head == nullptr);
            }

        void insertHead(T val){
            if(isEmpty()){
                head = new Node<T>(val);
                return;
            }

            Node<T>* toinsert = new Node<T>(val);
            toinsert->Next = head;
            head = toinsert;
            return;
        }

        void insertTail(T val){
            if(isEmpty()){
                insertHead(val);
                return;
            }

            Node<T>* cur = head;

            while(cur->Next){
                cur = cur->Next;
                }

            Node<T>* toinsert = new Node<T>(val);
            cur->Next = toinsert;
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
			}   else	{
				cerr << "\nChose between 'a' or 'd' ! " << endl;
				cin >> c;
			}

		}while(c != 'a' && c != 'd');
	}

	void insertInOrderAscending(T val){
		if(isEmpty() || val <= head->val){
			insertHead(val);
			return;
		}

		Node<T>* cur = head;

		while(cur->Next && val >= cur->val){
			if(val < cur->Next->val){
				break;
                }

			cur = cur->Next;
		}

		if(!cur->Next){
			insertTail(val);
			return;
		}

		Node<T>* toinsert = new Node<T>(val);
		toinsert->Next = cur->Next;
		cur->Next = toinsert;
		return;
	}

	void insertInOrderDescending(T val){
		if(isEmpty() || val >= head->val){
			insertHead(val);
			return;
		}

		Node<T>* cur = head;

		while(cur->Next && val <= cur->val){
			if(val > cur->Next->val){
				break;
                }

			cur = cur->Next;
		}

		if(!cur->Next){
			insertTail(val);
			return;
		}

		Node<T>* toinsert = new Node<T>(val);
		toinsert->Next = cur->Next;
		cur->Next = toinsert;
		return;
	}

    void removeHead(){
		if(isEmpty()){
			cerr << "Empty List! Operation isn't avaible! " << endl;
			return;
		}

		Node<T>* ptr = head;
		head = head->Next;
		delete ptr;

		return;
	}

	void removeTail(){
		if(isEmpty()){
			cerr << "Empty List! Operation isn't avaible! " << endl;
			return;
		}

		Node<T>* cur = head;
		Node<T>* prev = nullptr;

		while(cur->Next){
			prev = cur;
			cur = cur->Next;
		}

		prev->Next = nullptr;
		delete cur;
		return;
	}

    Node<T>* search(T val){
		if(isEmpty()){
			throw out_of_range("...list is empty...");
            }
		if(head->val == val){
			return head;
            }

		Node<T>* cur = head;

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
			return;
            }
		
		Node<T>* toremove = search(val);

		if(!toremove){
			return;
            }

		if(toremove->val == head->val){
			removeHead();
			return;
		}

		Node<T>* cur = head;
		Node<T>* prev = nullptr;

		while(cur->Next && cur->val != toremove->val){
			prev = cur;
			cur = cur->Next;
		}

		prev->Next = cur->Next;
		delete cur;
	}

    void inverti(Node<T>* ptr){
	    Node<T>* cur = new Node<T>(*ptr);
	   	Node<T>* prev = nullptr;
	    Node<T>* succ = nullptr;

	    while(cur){
	        succ = cur->Next;
	        cur->Next = prev;
	        prev = cur;
	        cur = succ;
	    }
		head = prev;
	}

	void inverti(){
		if(isEmpty()){
			cerr << "Empty List! Operation isn't avaible! " << endl;
			return;
		}
		inverti(this->head);
	}

    bool crescente(Node<T>* ptr){
	    return(!ptr || !ptr->Next|| ((ptr->val <= ptr->Next->val && crescente(ptr->Next))));
	}

	bool crescente(){
        return crescente(head);
        }

	bool decrescente(Node<T>* ptr){
	    return(!ptr || !ptr->Next|| ((ptr->val >= ptr->Next->val && decrescente(ptr->Next))));
	}
	
	bool decrescente(){
        return decrescente(head);
        }

	friend ostream& operator<< (ostream& os, List<T>& obj){

		if(obj.isEmpty()){
			return os << "\nEmpty List !" << endl;
            }

		os << "\nHead: " << *obj.head << endl;
		os << "\nLinked_list: " << endl;

		Node<T>* ptr = obj.head;
		os << "\nHead --> ";
		while(ptr){
			os << *ptr << " --> ";
			ptr = ptr->getNext();
		}

		return os << "NIL" << endl << "\nEnd List\n" << endl; 
	}
};

#endif