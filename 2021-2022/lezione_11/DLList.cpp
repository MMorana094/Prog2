#include <iostream>

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
		int size = 0;
	
	public:
	
	DLList() {
		head = nullptr;
		tail = nullptr;
	}

	bool isEmpty() {
		return (head == nullptr) && (tail == nullptr);
	}

	int getSize(){
		return size;
	}
	
	DLNode<T>* getTail(){
		return this->tail;
	}

	void insertHead(T val) {
		if(this->isEmpty()) {
			this->head = new DLNode<T>(val);
			this->tail = head;
			size++;
			return;
		}
		size++;
		DLNode<T> *toInsert = new DLNode<T>(val);
		toInsert->next = head;
		head->prev = toInsert;
		head = toInsert;
	}
	
	void insertTail(T val) {
		if(this->isEmpty()) {
			this->insertHead(val);
			return;
		}
		size++;
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
			size--;
			DLNode<T> *ptr = head;
			head = nullptr;
			tail = nullptr;
			delete ptr;			
		}
		size--;
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
			size--;
			DLNode<T> *ptr = head;
			head = nullptr;
			tail = nullptr;
			delete ptr;			
		}
		size--;
		DLNode<T> *ptr = tail;
		ptr->prev->next = nullptr;
		tail = ptr->prev; //tail->prev
		
		delete ptr;
	}
};



int main(){
    DLList<int> Lista1;

    Lista1.insertHead(10);
    Lista1.insertHead(-40);
    Lista1.insertHead(2);
    Lista1.insertHead(65);

    Lista1.isEmpty();

}