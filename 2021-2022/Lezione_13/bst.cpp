#include <iostream>

using namespace std;

template<typename T>
class BSTNode{
    private:
        BSTNode<T>* Parent;
        BSTNode<T>* Left;
        BSTNode<T>* Right;
        T Key;
        template<typename U>
        friend class BST;


    public:
        BSTNode(T key) {
            this->Key = key;
            this->Parent = nullptr;
            this->Right = nullptr;
            this->Left = nullptr;
        }

        void setParent(BSTNode<T>* parent){
            this->Parent = parent;
        }

        void setRight(BSTNode<T>* right){
            this->Right = right;
        }

        void setLeft(BSTNode<T>* left){
            this->Left = left;
        }

        void setKey(T key){
            this->Key = key;
        }

        BSTNode<T>* getParent(){
            return this->Parent;
        }
        
        BSTNode<T>* getRight(){
            return this->Right;
        }

        BSTNode<T>* getLeft(){
            return this->Left;
        }

        T getKey(){
            return this->Key;
        }

        virtual ostream& put(ostream& os){
            os << "\n Node = " << obj << ",Parent = " << Parent << ", Right = " << Right << ", Left = " << Left << endl;
            return os;
        }
};

template<typename T>
ostream& operator<<(ostream& os, BSTNode<T>& obj){
    return obj.put(os);
}

template<typename T>
class BST{
    private:
        BST<T>* Root;
    public:
        BST(){
            this->Root == nullptr;
        }

        bool isEmpty(){
            return root == nullptr;
        }

        BST<T>* Root(){
            return this->Root;
        }

        void insert(T key){
            if(this->isEmpty()){
                this->Root = new BSTNode<T>(key);
                return;
            }
            insert(root, key);
        }

        void insert(BSTNode<T>* ptr, T key){
            if(ptr->Left == nullptr && key<=ptr->key){
                ptr->Left == new BSTNode<T>(key);
                ptr->Left->setParent(ptr);
                return;
            }
            if(ptr->Right == nullptr && key>=ptr->key){
                ptr->Right == new BSTNode<T>(key);
                ptr->Right->setParent(ptr);
                return;
            } else if (key <= ptr->Key){
                insert(ptr->Left, key);
            } else {
                insert(ptr->Right, key);
            }
            
        }

};

int main(){

    BST<int> bst;

    bst.insert(10);
    bst.insert(8);
    bst.insert(5);
    bst.insert(11);
    bst.insert(53);
    bst.insert(1);
    bst.insert(26);
    bst.insert(35);
    bst.insert(44);

}