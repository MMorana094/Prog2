#ifndef NODE_LIST_H
#define NODE_LIST_H
#include <iostream>

using namespace std;

template<typename T>
class Node{
    private:
        T val;
        Node<T>* Next;

        template<typename U>
	    friend class List;

    public:
        Node(T val){
            this->val = val;
            this->Next = nullptr;
        }

    //getter
        T* getVal(){
            return this->val;
        }

        Node<T>* getNext(){
            return this->Next;
        }

        friend ostream& operator <<(ostream& os, const Node<T>& obj){
            os << "Node Key = " << obj.val << endl;
            return os;
        }
};


#endif