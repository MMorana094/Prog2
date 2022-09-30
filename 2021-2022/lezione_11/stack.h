#ifndef STACK_H
#define STACK_H

#include "List.h"

template <typename T>
class Stack : public List<T>{
    private:
        int size = 0;

    public:
        Stack() : List<T>(){

        }
        Node<T>* top() {
            return List<T>::getHead();
        }

        void push(T val){
            List<T>::insertHead(val);
            this->size++;
        }

        Node<T>* pop(){
            if(List<T>::isEmpty()){
                return nullptr;
            }
            Node<T>* ptr = top();
            List<T>::removeHead();
            this->size--;
            return ptr;
        }

        friend ostream& operator<< (ostream& os, Stack<T>& obj){		
		if(obj.isEmpty()){
			os << "\nEmpty Stack!" << endl;
			return os;
		}
		
		os << "\nStack_dynamic: " << endl;
		os << "\nSize : " << obj.size << endl;
		os << "\nTop-->\t" << *obj.top() << endl;
		
		while(obj.pop()){
			if(obj.top()){
			os << *obj.top() << " " ;
            }
		}
		
		return os << "\nEnd stack" << endl;
	}
};

#endif