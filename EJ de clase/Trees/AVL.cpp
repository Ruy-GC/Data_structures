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

            rotation(current_node);
            
        }

        void rotation(Node<T> *&current_node){
            int balance = balanceF(current_node);
            
            if (balance > 1 &&balanceF(current_node->left) >= 0)
                current_node = rightRotate(current_node);
            // Left Right Case
            if (balance > 1 && balanceF(current_node->left) < 0){
                current_node->left = leftRotate(current_node->left);
                current_node = rightRotate(current_node);
            }  
            // Right Right Case
            if (balance < -1 &&balanceF(current_node->right) <= 0)
                current_node = leftRotate(current_node);
            // Right Left Case
            if (balance < -1 && balanceF(current_node->right) > 0){
                current_node->right = rightRotate(current_node->right);
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

            Node<T>* minimum_element(Node<T>* current_node){
            //gets most left item
            if(!current_node->left){
                return current_node;
            }
            return minimum_element(current_node->left);
        }

        Node<T>* deleteNode(Node<T> *&current_node,int key_delete){

            if(!current_node) return NULL;
            // First search for the element to delete
            else if(key_delete < current_node->key){
                current_node->left = this->deleteNode(current_node->left, key_delete);
            }
            else if(key_delete > current_node->key){
                current_node->right = this->deleteNode(current_node->right, key_delete);
            }
            else{
                if(!current_node->left &&!current_node->right){
                    // If the node is a leaf we just delete it
                    delete current_node;
                    current_node = NULL;
                }
                else if(!current_node->left){
                    // If the node doesn't have left node, 
                    // then just replace the current node with the right root
                    Node<T> * right_node = current_node->right;
                    delete current_node;
                    current_node = right_node;
                }
                else if(!current_node->right){
                    // If the node doesn't have right node, 
                    // then just replace the current node with the left root
                    Node<T> * left_node = current_node->left;
                    delete current_node;
                    current_node = left_node;   
                }
                else{
                    // If the node to delete has both nodes
                    // We search the minimum element in the right side
                    Node<T>* successor  = this->minimum_element(current_node->right);
                    // Replace the data with the minimum element (also the key)
                    Node<T>* new_node_minimum = new Node<T>(
                        successor ->data, successor->key, 
                        current_node->left, current_node->right);

                    if(current_node == this->root){
                        this->root = new_node_minimum;
                    }

                    // Delete the current node
                    delete current_node;

                    // Now we recursively delete the minimum element in the right subtree
                    current_node = new_node_minimum;
                    current_node->right = this->deleteNode(current_node->right, successor->key);
                }
            }
            rotation(current_node);
            return current_node;    
        }
};


int main() {
    BinarySearchTree<int> a;
    a.insert(a.root,0,4);
    a.insert(a.root,0,5);
    a.insert(a.root,0,6);
    a.insert(a.root,0,7);
    a.insert(a.root,0,8);
    a.insert(a.root,0,9);

   

    a.inOrder(a.root);
    cout<<"\n";
    cout<<a.balanceF(a.root)<<endl;
    a.showTree(a.root,0);
    /*a.deleteNode(a.root,11);
    a.deleteNode(a.root,4);
    a.deleteNode(a.root,17);

    cout<<"\n\n";
    a.showTree(a.root,0);*/

    return 0;
}