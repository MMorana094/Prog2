#include <iostream>
#include <typeinfo>

using namespace std;

template <typename T>
class Node{
    private:
        T val;
        Node<T>* Next;
        Node<T>* Prev;

        template<typename U>
        friend class List; 

    public:
        Node(T val){
            this->val = val;
            Next = nullptr;
        }

        Node<T>* getNext(){
            return Next;
        }

        Node<T>* getPrev(){
            return Prev;
        }

        friend ostream& operator<<(ostream& os, Node<T>& obj){
            os << "Node = " << obj.val;
            return os;
        }

};

template <typename T>
class List{
    private:
        int size;
        Node<T>* head;

    public:
        List(){
            size = 0;
            head = nullptr;
        }

        bool isEmpty(){
            return (head==nullptr);
        }

        int getSize(){
            return size;
        }

        void insert(T val){
            if(this->isEmpty()){
                this->head = new Node<T>(val);
                size++;
                return;
            }
        }

        void insertHead(T val){
            if(isEmpty()){
                insert(val);
                return;
            }

            Node<T>* tmp = new Node<T>(val);
            tmp->Next = head;
            this->head = tmp;
            size++;
            return;
        }

        void insertTail(T val){
            if(isEmpty()){
                insert(val);
                return;
            }
            Node<T>* ptr = head;
            while(ptr->getNext()){
                ptr = ptr->getNext();
            }
            Node<T>* tmp = new Node<T>(val);
            ptr->Next = tmp;
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

        void deleteHead(){
            if(this->isEmpty()){
                cout << "empty List" << endl;
                return;
            }
            Node<T>* tmp = head;
            head = head->Next;
            delete tmp;
            size--;
            return;
        }

        void deleteTail(){
            if(this->isEmpty()){
                cout << "empty List" << endl;
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
            size--;
            return; 
        }

        void deleteval(T val){
            if(this->isEmpty()){
                cout << "Empty List" << endl;
                size--;
                return;
            }
            if(head->val == val){
                this->deleteHead();
                size--;
                return;
            }
            Node<T>* cur = head;
            Node<T>* prev = nullptr;
            while (cur->Next && cur->val != val){
               prev = cur;
               cur  = cur->Next;
            }
            if(!(cur->Next) && cur->val != val){
                prev = cur;
                cur = cur->Next;
            }
            prev->Next = cur->Next;
            delete cur;
            size--;
            return;
        }


};

int main(){
    List<int> List1;

    List1.insertHead(20);
    List1.insertHead(15);
    List1.insertHead(100);
    List1.insertHead(1);
    List1.insertHead(99);
    List1.insertHead(16);
    List1.insertHead(36);
    List1.insertHead(88);
    List1.insertHead(47);
    List1.insertHead(22);
    List1.insertHead(24);

    cout << List1 << endl;
    cout << List1.getSize() << endl;



    List1.deleteHead();

    cout << List1 << endl;
    cout << List1.getSize() << endl;

    List1.deleteTail();

    cout << List1 << endl;
    cout << List1.getSize() << endl;

    List1.deleteval(1);

    cout << List1 << endl;
    cout << List1.getSize() << endl;    

}