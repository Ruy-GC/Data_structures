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

        void insert(T data, int key){
            Node<T> *currentNode = this->root;
            Node<T> *to_add = new Node<T>(data, key);

            if(!this->root) { 
                this->root = to_add;
                return;
            }

            while(true){
                //checks if key is higher or lower than root
                if(key >= currentNode->key){
                    //if node exists, goes to next node
                    if(currentNode->right){
                        currentNode =currentNode->right;
                    } else {
                        currentNode->right = to_add; 
                        return;
                    }
                } else { 
                    if(currentNode->left){
                        currentNode = currentNode->left;
                    } else {
                        currentNode->left = to_add; 
                        return;
                    }
                }
            }
        }

        void preOrder(Node<T> *node){
          	if(node){
                cout << node->key << " "; 
				this->preOrder(node->left); 
				this->preOrder(node->right);
         	}
        }

        void inOrder(Node<T> *node){
          	if(node){
				this->inOrder(node->left); 
				cout << node->key << " "; 
				this->inOrder(node->right);
         	}
        }

        void postOrder(Node<T> *node){
            if(node){
                this->postOrder(node->left); 
				this->postOrder(node->right);
                cout << node->key << " "; 
            }else{
                return;
            }
        } 
        
        void byLevel(){
            queue<Node<T>*> q; 
            if(!this->root) return;
            q.push(root);

            while(!q.empty()){
                Node<T> *temp = q.front();
                cout<<temp->key<<" ";
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);  
                q.pop();           
            }
        }

        int height(Node<T> *node){
            if(!node) return 0;
            int leftH = height(node->left);
            int rightH = height(node->right);

            return max(leftH, rightH)+1;
        }

        Node<T>* search(Node<T> *Node,int key){
            if(Node == NULL){
                return NULL;
            }else if(Node->key == key){
                return Node;
            }else if (Node->key > key){
                return search(Node->left,key);
            }else{
                return search(Node->right,key);
            }
        }

         Node<T>* minimum_element(Node<T>* current_node){
            if(!current_node->left){
                return current_node;
            }
            return minimum_element(current_node->left);
        }

        Node<T>* deleteNode(Node<T> *current_node,int key_delete){
            if(!current_node) return NULL;

            current_node = this->search(current_node,key_delete);

            if(!current_node->left && !current_node->right){
                delete current_node;
                current_node = NULL;
            }else if(!current_node->left){
                Node<T> *right_node = current_node->right;
                delete current_node;
                current_node = right_node;
            }else if(!current_node->right){
                Node<T> *left_node = current_node->left;
                delete current_node;
                current_node = left_node;
            }else{
                Node<T> *successor = this->minimum_element(current_node->right);
                Node<T> *new_node_minimum = new Node<T>(
                    successor->data,
                    successor->key,
                    current_node->left,
                    current_node->right
                );
                if(current_node == this->root){
                    this->root = new_node_minimum;
                }

                delete current_node;

                current_node = new_node_minimum;
                current_node->right =this->deleteNode(current_node->right,successor->key);
            }
            return current_node;
        }
};


int main() {
    BinarySearchTree<int> a;
    a.insert(10,10);
    a.insert(5,12);
    a.insert(6,5);
    a.insert(8,7);
    a.insert(2,11);
    a.insert(1,20);
    a.insert(0,3);

    cout<<a.height(a.root)<<endl;
    a.inOrder(a.root);
    cout<<endl;
    a.preOrder(a.root);
    cout<<endl;
    a.postOrder(a.root); 
    cout<<endl;
    a.byLevel(); 

    //a.deleteNode(a.root,3);
    cout<<endl;
    if(!a.root){
        cout<<"pp";
    }else{
        cout<<a.root->key;
    }
    cout<<endl;

    a.inOrder(a.root);
    return 0;
}