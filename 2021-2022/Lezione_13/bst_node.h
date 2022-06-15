#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream>

using namespace std;

template<typename T>
class BSTNode{
	protected:
		BSTNode<T>* left;
		BSTNode<T>* right;
		BSTNode<T>* parent;
		T key;
		bool verbose = false;
		template<typename U>
		friend class BST;

	public:
		BSTNode(T key) : key(key){
			this->left = nullptr;
			this->right = nullptr;
			this->parent = nullptr;
		}

		void setParent(BSTNode<T>* parent){
			this->parent = parent;
		}

		void setLeft(BSTNode<T>* left){
			this->left = left;
		}

		void setKey(T key){
			this->key = key;
		}

		void setVerbose(T verb){
			this->verbose = verb;
		}

		void setRight(BSTNode<T>* right){
			this->right = right;
		}

		BSTNode<T>* getLeft(){
			return this->left;
		}

		BSTNode<T>* getRight(){
			return this->right;
		}

		BSTNode<T>* getParent(){
			return this->parent;
		}


		BSTNode<T>* getKey(){
			return this->key;
		}

		friend ostream& operator<<(ostream& os, BSTNode<T>& obj){
			if(obj.verbose){
				os <<  "BSTNode@ = " << &obj <<  ", key = " << obj.key  << ", left = " << obj.left << ", right = " << obj.right << ", parent = " << obj.parent ;
				return os;
			} 
			os << " key = " << obj.key;
			return os;

		}

	protected:
		
};
#endif
