#ifndef BST_H
#define BST_H

#include "bst_node.h"
#include <iostream>

using namespace std;

template<typename T>
class BST{
    private:
        BSTNode<T>* root;

    public:
        BST(){
            root = nullptr;
        }

        bool isEmpty(){                                 //controllo se l'albero è vuoto
            return root == nullptr;
        }

        BSTNode<T>* getRoot(){
            return this->root;
        }

        void insert(T key){
            if(this->isEmpty()){
                root = new BSTNode<T>(key);
                return;
            }
            insert(root, key);
        }

        void insert(BSTNode<T>* ptr, T key){
            if(ptr->left == nullptr && key<=ptr->key){
                ptr->left = new BSTNode<T>(key);
                ptr->left->setParent(ptr);
                return;
            }
            if(ptr->right == nullptr && key>=ptr->key){
                ptr->right = new BSTNode<T>(key);
                ptr->right->parent = ptr;
                return;
            } else if(key <= ptr->key){
                    insert(ptr->left, key);
                } else {
                    insert(ptr->right, key);
                }
        }

        void visit(BSTNode<T>* node){
            cout << *node << endl;
        }

        void inorder(BSTNode<T>* ptr){
            if(ptr == nullptr){
                return;
            }
            inorder(ptr->left);
            visit(ptr);
            inorder(ptr->right);
        }

        void inorder(){
            inorder(root);
        }

        BSTNode<T>* min(){
            return min(root);
        }

        BSTNode<T>* min(BSTNode<T>* from){
            if(isEmpty()){
                return nullptr;
            }
            BSTNode<T>* ptr = from;
            while(ptr->left){
                ptr = ptr->left;
            }
            return ptr;
        }

        BSTNode<T>* max(){
            return max(root);
        }

        BSTNode<T>* max(BSTNode<T>* from){
            if(isEmpty()){
                throw "Empty BST";
            }
            BSTNode<T>* ptr = from;
            while(ptr->right){
                ptr = ptr->right;
            }
            return ptr;
        }

        BSTNode<T>* successor(BSTNode<T>* x){
            if(this->isEmpty()){
                return nullptr;
            }
            if(x->right){
                return this->min(x->right);
            }

            BSTNode<T>* y = x->parent;

            while (x != nullptr && x == y->right){
                x = y;
                y = y->parent;
            }
            return y;
        }

        BSTNode<T>* search(T key){
            return search(root, key);
        }

        BSTNode<T>* search(BSTNode<T>* ptr, T key){
            if(ptr == nullptr){
                return nullptr;
            }
            if(ptr->key == key){
                return nullptr;
            }
            if(key <= ptr->key){
                return search(ptr->left, key);
            } else{
                return search(ptr->right, key);
            }
            return nullptr;
        }
/* 
        void remove(BSTNode<T>* node){
            if(this->isEmpty()){
                return;
            }

            BSTNode<T>* node = this->search(key);
            if(node == nullptr){
                return;
            }
            //caso 1 (foglia)
            if(node->left == nullptr && node->right == nullptr){
                if(node == node->parent->left){
                    node->parent->left = nullptr;
                } else if(node == node->parent->right){
                    node->parent->right = nullptr;
                }
                return node;
            }

            //caso 2 (ha 1 figlio)
            if(node->left == nullptr && node->right!=nullptr){
                node->right->parent = node->parent;
                if(node == node->parent->left){
                    node->parent->left = node->right;
                } else if(node == node->parent->right){
                    node->parent->right = node-right;
                }
                return node;
            } if(node->left != nullptr && node->right==nullptr){
                node->left->parent = node->parent;
                if(node == node->parent->left){
                    node->parent->left = node->left;
                } else if(node == node->parent->right){
                    node->parent->right = node-left;
                }
                return node;
            }
            return nullptr;
        }

        BSTNode<T>* remove(T key){
            if(this->isEmpty()){
                return nullptr;
            }

            BSTNode<T>* ToDelete = this->remove(node);
            if(ToDelete != nullptr){
                return ToDelete;
            }
         //caso 3 (ha 2 figlio)
            BSTNode<T>* next = this->successor(node);
            T swap = node->key;
            node->key = next->key;
            next->key = swap;

            ToDelete = this->remove(next);
            return ToDelete;
        }
*/
/* 
        BSTNode<T>* deleteNode(BSTNode<T>* x) {
		if(x == nullptr || root == nullptr)
			return nullptr;
		// 1. x è una foglia
		if((x->left == nullptr) && (x->right == nullptr)) {
			BSTNode<T> * y = x->getParent();
			if(x == y->left)
				y->setLeft(nullptr);
			else
				y->setRight(nullptr);
		}
		// 2. x ha solo un figlio
		else if((x->left == nullptr)|| (x->right == nullptr)) {
			//semplificare questa selezione
			if(x->left != nullptr) {
				if(x == x->parent->left)
					x->parent->setLeft(x->left);
				else
					x->parent->setRight(x->left);
			}
			else {
				if(x == x->parent->left)
					x->parent->setLeft(x->right); 
				else
					x->parent->setRight(x->right);
			}
		}
		// 3. x ha due figli
		else {
			BSTNode<T>* z = this->successor(x);
			cout << "successore: " << *z << endl;
			x->setKey(z->key);
			cout << "x = " << *x << endl;

				//attaccare il figlio destro di z come figlio sinistro del padre di z
				if(z == z->parent->left) {
					cout << "z sx" << endl; z->parent->setLeft(z->right);
                    } else {cout << "z dx" << endl; z->parent->setRight(z->right);
                        }
			delete z;
		}
        return nullptr;
    }
 */
};
#endif