#include <iostream>
#define maxSize 1000

using namespace std;

template <typename T>
class DLNode{

    private:

    T val;
    DLNode<T>* next;
    DLNode<T>* prev;

template <typename U>
friend class DLList;

    public:
    	
	DLNode(T val) {
        this->val = val;
        this->next = nullptr;
        this-> prev = nullptr;
    }
	
	DLNode<T>* getNext() const { 
        return this->next;
        }
	DLNode<T>* getPrev() const { 
        return this->prev;
        }
	
	
	friend std::ostream& operator<<(std::ostream& out, const DLNode<T> &node) {
		out << "dlnode@" << &node << " val=" << node.val << " - next=" << node.next << " - prev=" << node.prev;
		return out;
	}
};

template <typename T>
class DLList {

	protected:
		DLNode<T> *head;
		DLNode<T> *tail;
	
	public:
	
	DLList() {
		head = nullptr;
		tail = nullptr;
	}

	bool isEmpty() {
		return (head == nullptr) && (tail == nullptr);
	}
	
	void insertHead(T val) {
		if(this->isEmpty()) {
			this->head = new DLNode<T>(val);
			this->tail = head;
			return;
		}
		
		DLNode<T> *toInsert = new DLNode<T>(val);
		toInsert->next = head;
		head->prev = toInsert;
		head = toInsert;
		return;
	}
	
	void insertTail(T val) {
		if(this->isEmpty()) {
			this->insertHead(val);
			return;
		}
		
		DLNode<T> *toInsert = new DLNode<T>(val);
		toInsert->prev = tail;
		tail->next = toInsert;
		tail = toInsert;
	}
	
	void removeHead() {
		if(this->isEmpty()) {
			std::cout << "Empty list" << std::endl;
			return;
		}
		
		if(head == tail) {
			DLNode<T> *ptr = head;
			head = nullptr;
			tail = nullptr;
			return;			
		}
		
		DLNode<T> *ptr = head;
		ptr->next->prev = nullptr;
		head = ptr->next; //head->next
		
		delete ptr;
	}
	
	void removeTail() {
		if(this->isEmpty()) {
			std::cout << "Empty list" << std::endl;
			return;
		}
		
		if(head == tail) {
			DLNode<T> *ptr = head;
			head = nullptr;
			tail = nullptr;
			delete ptr;			
		}
		
		DLNode<T> *ptr = tail;
		ptr->prev->next = nullptr;
		tail = ptr->prev; //tail->prev
		
		delete ptr;
	}

	friend ostream& operator<<(ostream& os, const DLList<T>& obj) {
		os << "DLlist Started at " << obj.head << endl;
		while(head->ptr){
			os << 
		}
		return os;
	}
};

// ---- IMPLEMENTAZIONE CODA ----- 
template<class T>
class Queue : protected DLList<T> {
	protected:
		int size = 0;

	public:

		Queue() : DLList<T>() {}

		void enqueue(T val) {
			DLList<T>::insertTail(val);
		}

		DLNode<T> dequeue() {
		
			if(isEmpty())
				return 0;
			
			DLNode<T> ptr = *(DLList<T>::head);
			DLList<T>::removeHead();
			size--;
			return ptr;
		}

		bool isEmpty() {
			return size == 0;
		}

		friend std::ostream& operator<<(ostream& out, Queue<T>& queue) {
		out << "Queue starting at " << &(queue.head);
		DLNode<T> *ptr = queue.head;
		while(ptr) {
			out << *ptr << std::endl;
			ptr = ptr->getNext();
		}
		return out;
	}
};

int main(){
    DLList<int> Lista1;

    Lista1.insertHead(10);
    Lista1.insertHead(-40);
    Lista1.insertHead(2);
    Lista1.insertHead(65);

	cout << Lista1 << endl;

	Queue<int> q;
	q.enqueue(10);
	q.enqueue(8);
	q.enqueue(50);
	q.enqueue(18);

	cout << q << endl;

	q.dequeue();
	q.dequeue();

	cout << q << endl;

	return 0;
}