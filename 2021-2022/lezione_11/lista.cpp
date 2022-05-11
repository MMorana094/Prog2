/*
esercizii per casa (guardare gitHub)
*/
#include <iostream>

using namespace std;

template<typename T>
class Node {
    T val;
    Node<T>* next;

    template<typename U>
    friend class List; //friendship per accedere ai tipi private e protected di Node

    public:
        Node(T val) : val(val) {
            next = nullptr;
        }

        Node<T>* getNext() const {return this->next;}

        friend ostream& operator<<(ostream& os, const Node<T>& obj) { //stampa nodi
            os << "node@" << &obj.val << " val=" << obj.val << " - next=" << obj.next;
            return os;
        }
};

template<typename T>
class List {
    Node<T>* head;

    public:
        List() {head = nullptr;}

        bool isEmpty() { //controllo per la lista vuota
            return head == nullptr;
        }

        void insert(T val) {
            if(this->isEmpty()) {
                head = new Node<T>(val); //inserimento in lista vuota
            }
        }

        void insertHead(T val) { //inserimento in lista
            if(this->isEmpty()) {
                this->insert(val);
                return;
            }

            Node<T> *tmp = new Node<T>(val);
            tmp->next = head;
            this->head = tmp;
        }

        void insertTail(T val) {
            if(this->isEmpty()) {
                this->insertHead(val);
                return;
            }

            Node<T>* ptr = head;
            while(ptr->getNext() != nullptr) {
                ptr = ptr->getNext();
            }

            Node<T>* tmp = new Node<T>(val);
            ptr->next = tmp;
        }

        void InserInOrder(T val){
            if(this->isEmpty()){
                this->insertHead(val);
                return;
            }
            if(head->val >= val){
                this->insertHead(val);
            }
            Node<T> *ptr = head;
            while(ptr->getNext() && (val>=ptr->val)){
                if(val<=ptr->next->val){
                    break;
                    }
                    ptr = ptr->getNext();
            }
            if(!(ptr->next)){
                this->insertTail(val);
                return;
            }
            Node<T>* toInsert= new Node<T> (val);
            toInsert->next = ptr->next;
            ptr->next = toInsert;
        }

        void deleteTail(){
            if(this->isEmpty()){
                cout << "Empty List" << endl;
                return;
            }
            Node<T>* cur = head;
            Node<T>* prev = nullptr;
            while (cur->next->next){
                prev = cur;
                cur = cur->next;
            }
            prev->next = nullptr;
            delete cur;
            
        }

        void deleteHead(){
            if(this->isEmpty()){
                cout << "Empty List" << endl;
                return;
            }
            head->val = nullptr;            
        }

/*         void delete(){
            if(this->isEmpty()){
                cout << "Empty List" << endl;
                return;
            }
            if(head->val == val){
                deleteHead();
            }
            Node<T>* cur = head;
            Node<T>* prev = nullptr;
            while (){
               
            }
            
        }
 */
        Node<T>* getHead() {return this->head;}

        friend ostream& operator<<(ostream& os, const List<T>& obj) { //stampa lista
            os << "List head=" << obj.head << endl;
            Node<T> *ptr = obj.head; //se uso ptr->next non stamperò un elemento
            while(ptr != nullptr) {
                os << "\t" << *ptr << endl;
                ptr = ptr->getNext(); //quì è meglio usare un metodo get che rendere l'ostream class friend in Node(nessuno può accedere ai campi di Node)
            }

            return os;
        }
};

int main() {

    cout << "\n";

    List<int> lista;
    List<int> listaN;
    
    listaN.insertHead(10); //ultimo elemento
    cout << *listaN.getHead() << endl;
    listaN.insertHead(2);
    cout << *listaN.getHead() << endl;
    listaN.insertHead(9); //primo elemento
    cout << *listaN.getHead() << endl;

/* 
    lista.insertTail(33);
    lista.insertTail(99);
    lista.insertTail(43);
 */
    cout << listaN << endl;

    lista.InserInOrder(6);
    lista.InserInOrder(-20);
    lista.InserInOrder(9);
    lista.InserInOrder(4);
/* 
    for(int i=0; i<20; i++){
        lista.insertTail(rand()%100);
    }
 */    
/* 
    for(int i=0; i<20; i++){
        lista.insertHead(rand()%100);
    }
 */
    cout << lista << endl;

    lista.deleteTail();

    cout << lista << endl;

}