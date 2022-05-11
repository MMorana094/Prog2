/*
Scrivere una classe template che implementi la lista;
scrivere una classe template che implementi il nodo;

nomenclatura
List
-Head:Node<T>*
Node
-val : <T>
*/
#include <iostream>

using namespace std;

template<typename T>
class Node{
    private:
        T val;
        Node<T>* next;
    public:
        Node(T val){
            this->val = val;
            this->next = nullptr;
        }
        template<typename U>
        friend class List;

        friend ostream& operator<<(ostream& out, const Node<T>& node){
            out << "node@" << &node << ", val = " << node.val << ", next = " << node.next << endl;
            return out;
        }

        Node<T>* getNext() const{
            return this->next;
        }
};

template<typename T>
class List {
    private:
        Node<T>* head;
    
    public:
        List(){
        }

        bool is_empty(){
            return this->head == nullptr;
        }

        void insert(T Val){
            if(this->is_empty()){
                this->head = new Node<T>(Val);
            }
        }

        void insertTail(T val){
            if(this->is_empty()){
                this->InsertHead(val);
                return;
            }
            Node<T>* ptr = head;
            while(ptr!= nullptr){
                ptr = ptr->getNext();
            }
            Node<T>* temp = new Node<T>(val);
            ptr->next = temp;
        }

        Node<T> getHead(){
            return *List<T>::head;
        }

        friend ostream& operator<<(ostream& out, const List<T>& list){
            Node<T>* ptr = list.head;
            while(ptr!=nullptr){
            out << ", Head = " << list.head << endl;
                out << " " << ptr << endl;
                ptr = ptr->getNext();
            }
            return out;
        }

        void InsertHead(T val){
            if(this->is_empty()){
                Node<T>* temp = new Node<T>(val);
                temp->next = head;
                this->head = temp;
            }
        }
};



int main() {
    List<int> lista;

    lista.InsertHead(10);
    cout << lista.getHead() << endl;
    lista.InsertHead(4);
    cout << lista.getHead() << endl;
    lista.InsertHead(-19);
    lista.insertTail(22);

}