#include <iostream>
#define MAXSIZE 1000


using namespace std;

template <typename T>
class StaticQueue{
    private:
        T* arr;
        int size = 0;
        int MaxSize;

// indici di testa e coda
        int head = -1, tail = -1;

    public:
        StaticQueue(int maxSize = MAXSIZE) : MaxSize(maxSize){
            this->arr = new T[maxSize];
        }

        bool isEmpty(){
            return head == tail;
        }

        bool isFull(){
            return ((head - (tail+1)) % MaxSize) == 0;
        }

        void enqueue(T val){
            if(isFull()){
				cerr << "\nFull queue" << endl;
				return;
			}
            if(isEmpty()){
                head = 0;
            }

			tail = (++tail % MaxSize); 					//incremento l'indice della coda e lo faccio ricadere in uno dei possibili indici
			arr[tail] = val; 							//Inserisco il nuovo elemento in coda agli altri
			size++; 									//Ciò provoca un aumento della dimensione
			return;
        }

        T dequeue(){
			if(isEmpty()){                              
				cerr << "\n Empty Queue " << endl;
                return 0;
            }

            T tmp = arr[head];  						//conservo il valore della testa
			head = (++head) % MaxSize; 					//Prima incremento e poi faccio il modulo con la dimensione
			size--; 									//Decremento la dimensione effettiva
			return tmp;
        }

        friend ostream& operator<<(ostream& os, StaticQueue<T>& obj){
            if(obj.isEmpty()){                              
				os << "\n Empty Queue " << endl;
                return os;
            }
            os << "\nMax Size = " << obj.MaxSize << ", Size = " << obj.size << endl;
            for(int i = obj.head, count = 0; count < obj.size; count++){
                os << "\nqueue[" << i << "] = " << obj.arr[i];
                i = (i+1) % obj.MaxSize; 
            }
            return os;
        }
};

int main(){

    StaticQueue<int> Queue(5);

    Queue.enqueue(1);
    Queue.enqueue(2);    
    Queue.enqueue(3);
    Queue.enqueue(4);
    Queue.enqueue(5);

    cout << Queue << endl;

    Queue.dequeue();
    Queue.dequeue();

    cout << Queue << endl;

    Queue.enqueue(6);
    Queue.enqueue(7);

    cout << Queue << endl;

}