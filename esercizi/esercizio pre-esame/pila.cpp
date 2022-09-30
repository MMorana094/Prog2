#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class Node{
    private :
        T val;
        Node<T>* next;

        template<typename U>
        friend class List;

    public :
        Node(T val){
            this->next = nullptr;
            this->val = val;
        }

        Node<T>* getNext(){
            return this->next;
        }

        friend ostream& operator <<(ostream& os, const Node<T>& obj){
            os << "Node val = " << obj.val;
            return os;
        }
};

template <typename T>
class List{
    private:
        Node<T>* head;
        int size;
    
    public:
        List(){
            this->head = nullptr;
            this->size = 0;
        }

        bool isEmpty(){
            return (head==nullptr);
        }

        Node<T>* getHead(){
            return this->head;
        }

        void insert(T val){
            if(isEmpty()){
                this->head = new Node<T>(val);
                return;
            }
            return;
        }

        void deleteHead(){
            if(isEmpty()){
                cout << "Empty List" << endl;
                return;
            }
            Node<T>* ptr = head;
            this->head = ptr->next;

            delete ptr;
            size--;

            return;            
        }

        void insertHead(T val){
            if(isEmpty()){
                insert(val);
                return;
            }

            Node<T>* ptr = new Node<T>(val);
            ptr->next = head;
            head = ptr;
            size++;

            return;
        }

        friend ostream& operator<<(ostream& os, List<T>& obj){
            os << "List Head :" << endl << *obj.head << endl;
            Node<T> *ptr = obj.head;
            while(ptr != nullptr) {
                os << "\t" << *ptr << endl;
                ptr = ptr->getNext(); //quì è meglio usare un metodo get che rendere l'ostream class friend in Node(nessuno può accedere ai campi di Node)
            }
            return os;
        }
};

template<typename T>
class pila : public List<T>{
    private:

    public:
        pila() : List<T>(){

        }

        void PUSH(T val){
            List<T>::insertHead(val);
        }

        void POP(){
            List<T>::deleteHead();
        }

        bool isEmpty(){
            return List<T>::isEmpty();
        }

        Node<T>* getHead(){
            return List<T>::getHead();
        }
};

int main(){

    int chose;
    int y = 0;
    pila<int> pila1;
    
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "eccovi nella vostra pila cosa desiderate fare?" << endl;
    cout << "1) PUSH " << endl;
    cout << "2) POP " << endl;
    cout << "3) Ottieni Primo elemento " << endl;
    cout << "4) Controllo Pila vuota " << endl;
    cout << "5) stampa Pila " << endl;
    cout << "0) chiudi programma " << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    do{
    cout << "cosa scegliete? " << endl;
    cin >> chose;
    cout << "------------------" << endl;
    switch(chose){
        case 1 :
            cout << "quale numero desiderate impilare" << endl;
            cin >> y;
            pila1.PUSH(y);
            break;
        case 2 :
            cout << "estrazione della testa della pila in corso" << endl;
            cout << "estrazione eseguita" << endl;
            break;
        case 3 : 
            cout << "il primo elemento della pila è : " << endl;
            cout << pila1.getHead() << endl;
            break;
        case 4 : 
            cout << "stiamo controllando la tua pila" << endl;
            cout << pila1.isEmpty() << endl;
            break;
        case 5 :
            cout << "stiamo stampando la tua Pila" << endl;
            cout << pila1 << endl;
            break;
        case 0 :
            exit(EXIT_SUCCESS);
        }
    } while(chose < 0 || chose > 5);
}