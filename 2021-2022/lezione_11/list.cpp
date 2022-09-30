#include <iostream>
#include <cstdlib>

using namespace std;

template<typename T>
class Node{
    private:
        T val;
        Node<T>* next;

        template <typename U>
        friend class List;
    
    public:
        Node(T val){
            this->val = val;
            this->next = nullptr;
        }

        Node<T>* getNext() const{
            return this->next;
        }

        friend ostream& operator<<(ostream& os, const Node<T>& obj){
            os << "val = " << obj.val << ", Next = " << obj.next;
            return os;
        }    
};

template<typename T>
class List{
    private:
        Node<T>* head;
        int Size;

    public:
        List(){
            this->head = nullptr;
            this->Size = 0;
        }

        
        bool isEmpty(){
            return Size == 0;
        }

        void insertHead(T val){
            if(isEmpty()){
                head = new Node<T>(val);
                this->Size++;
                return;
            }
        }

        friend ostream& operator<<(ostream& os, const List<T>& obj){
            os << "Head List = " << &obj.head << endl;
            Node<T>* ptr = obj.head;
            while(ptr != nullptr){
                os << "\t" << *ptr << endl;
                ptr = ptr->getNext();
            }
            return os;            
        }

        void insert(T val){
            if(isEmpty()){
                insertHead(val);
                return;
            }
            Node<T>* tmp = new Node<T>(val);
            tmp->next = head;
            this->head = tmp;
            Size++;
            return;
        }

        int getSize(){
            return this->Size;
        }

};

int main(){
    
    List<int> lista;
    int V[25];
    for(int i=0; i<25; i++){
        V[i] = rand()% 15;
    }
    for(int i=0; i<25; i++){
        lista.insert(V[i]);
    }

    cout << "Size = " << lista.getSize() << endl;
    cout << lista << endl;
}