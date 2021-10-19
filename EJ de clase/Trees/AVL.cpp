#include <iostream>
#include <queue> 
#include <algorithm>  

using namespace std;

template <class T> class Node {
    public:
        T data; // The object information
        int key;
        Node* left; // Pointer to the next node element
        Node* right;
        
        Node(T new_data, int key, Node<T>* left, Node<T>* right){
            this->data = new_data;
            this->key = key;
            this->left = left;
            this->right = right;
        }
        
        Node(T new_data, int key){
          	this->data = new_data;
			this->key = key;
            this->left = NULL;
			this->right = NULL;
        }
};

template <class T> class BinarySearchTree {
    public:
        Node<T> *root; 
    
        BinarySearchTree<T>(){
            this->root = NULL; 
        } 

        ~BinarySearchTree(){
        }

        void insert(Node<T>*&current_node,T data, int key){
            if(current_node == NULL){
                Node<T> *new_node = new Node<T>(data,key);
                current_node = new_node;

            }else if(current_node->key > key){
                insert(current_node->left,data,key);
            }else{
                insert(current_node->right,data,key);
            }

            int balance = balanceF(current_node);

            if(balance > 1 && key < current_node->left->key){
                current_node = rightRotate(current_node);
            }
            if(balance < -1 && key > current_node->right->key){
                current_node = leftRotate(current_node);
            }
            if(balance > 1 && key > current_node->left->key){
                current_node->left = leftRotate(current_node->left);
                current_node =rightRotate(current_node);
            }
            if(balance < -1 && key < current_node->right->key){
                current_node->right = leftRotate(current_node->right);
                current_node = leftRotate(current_node);
            }
            
        }

        void inOrder(Node<T> *node){
          	if(node){
				this->inOrder(node->left); 
				cout << node->key << " "; 
				this->inOrder(node->right);
         	}
        }

        Node<T>* search(Node<T> *Node,int key){
            if(Node == NULL){
                return NULL;
            }else if(Node->key == key){
                return Node;
            }else if (Node->key > key){
                //if searched key is less than Node goes left recursively
                return search(Node->left,key);
            }else{
                //if searched key is more than Node goes right recursively
                return search(Node->right,key);
            }
        }

        int height(Node<T> *node){
            if(!node) return 0;
            int leftH = height(node->left);
            int rightH = height(node->right);

            return max(leftH, rightH)+1;
        }

        int balanceF(Node<T> *node){
            if(!node) return 0;
            return height(node->left) - height(node->right);
        }

        Node<T> *leftRotate(Node<T> *n1){
            Node<T> *n2 = n1->right;
            Node<T> *temp = n2->left;

            n2->left = n1;
            n1->right = temp;

            return n2;
        }

        Node<T> *rightRotate(Node<T> *n1){
            Node<T> *n2 = n1->left;
            Node<T> *temp = n2->right;

            n2->right = n1;
            n1->left = temp;

            return n2;
        }
    void showTree(Node<T> *tree, int count){
        if (tree == NULL){
            return;
        }else{
            showTree(tree->right, count +1);
            for(int i =0;i < count; i++){
                cout<<"   ";
            }
            cout<<tree->key<<endl;
            showTree(tree->left, count +1);
        }
    }
};


int main() {
    BinarySearchTree<int> a;
    a.insert(a.root,0,10);
    a.insert(a.root,0,12);
    a.insert(a.root,0,5);
    a.insert(a.root,0,7);
    a.insert(a.root,0,11);
    a.insert(a.root,0,20);
    a.insert(a.root,0,3);
    a.insert(a.root,0,1);
    a.insert(a.root,0,8);

   

    a.inOrder(a.root);
    cout<<"\n";
    cout<<a.balanceF(a.root)<<endl;
    a.showTree(a.root,0);

    cout<<"\n";
    return 0;
}