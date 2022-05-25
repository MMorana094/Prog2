#include <iostream>

using namespace std;

template<class T>
class Queue {
	protected:
		int length;
		int nElem = 0;
		T *queue;
		int head = -1, tail = -1;

	public:
	
		Queue(int length): length(length) {
			queue = new T[length];
		}
		
		void enqueue(T value) {
			if(this->isFull()) 
				return;
			if(this->isEmpty()) {
				head = 0;
			}

			nElem++;
			this->queue[(++tail) % length] = value;
		}
		
		T dequeue() {
			if(this->isEmpty()) {
				return 0;
			}
			
			nElem--;
			T temp = this->queue[head];
			head = ((head+1) % length);
			
			return temp;
		}

		bool isFull() {
			return ((head - (tail+1)) % length) == 0;
		}

		bool isEmpty() {
			return nElem == 0;
		}

		int size() const {
			return this->length - (((this->length - (tail - head)) -1 ) % this->length);
		}

		friend ostream& operator<<(ostream& os, const Queue& obj) {
			os << "Coda di lunghezza massima " << obj.length << " con " << obj.nElem << " inseriti size=" << obj.size() << endl;
			os << "head = " << obj.head << " tail = " << obj.tail << endl;
			for(int i=0; i < obj.length; i++) 
				os << "\t" << obj.queue[i] << ((i == obj.head) ? " <- head" : ((i == obj.tail) ? " <- tail" : "")) << endl;
			return os;
	}
		~Queue() {
			delete [] queue;
		}
};

int main(){

	int dim = 10;

    Queue<int> queue1(dim);
	const int DIM = 4;

	queue1.enqueue(50);
 	queue1.enqueue(10);
	queue1.enqueue(1);
	queue1.enqueue(11);

	cout << queue1 << endl;

	queue1.~Queue();

	cout << queue1 << endl;
}