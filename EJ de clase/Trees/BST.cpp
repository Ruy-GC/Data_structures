#include <iostream>
#include <queue> 

using namespace std;

template <class T> class Node {
    private:
        T data; // The object information
        int key;
        Node* left; // Pointer to the next node element
        Node* right;
        
    public:
        Node(){
            this->data = NULL;
            this->left = NULL;
			this->right = NULL;
			this->key = 0;
        }
        
        Node(T new_data, int key){
          	this->data = new_data;
			this->key = key;
            this->left = NULL;
			this->right = NULL;
        }
        
        void set_right(Node* right){
            this->right = right;
        }

        void set_left(Node* left){
            this->left = left;
        }

        Node* get_left(){
          	return this->left;
        }    

        Node* get_right(){
          	return this->right;
        }       
        
        void set_data(T new_data){
            this->data = new_data;
        }

        T get_data(){
            return this->data;
        }

        void set_key(int key) {
          this->key = key;
        }

        int get_key() {
          return key;
        }
};
template <class T> class BinarySearchTree {
    
    private: 
        Node<T> *root; 
    
    public:
        BinarySearchTree<T>(){
            this->root = NULL; 
        } 

        void add(T data, int key){
            Node<T> *currentNode = this->root;
            Node<T> *to_add = new Node<T>(data, key);
            if(!this->root) { 
                this->root = to_add;
                return;
            }
            while(1){
                if(key >= currentNode->get_key()){
                    if(currentNode->get_right()){
                        currentNode =currentNode->get_right();
                    } else {
                        currentNode->set_right(to_add); 
                        return;
                    }
                } else { 
                    if(currentNode->get_left()){
                        currentNode = currentNode->get_left();
                    } else {
                        currentNode->set_left(to_add); 
                        return;
                    }
                }
            }
        }
        
        void inOrder(Node<T> *node){
          	if(node){
				this->inOrder(node->get_left()); 
				cout << node->get_key() << endl; 
				this->inOrder(node->get_right());
         	}
        }
         
          
        Node<T>* get_root(){
            return this->root;
        }  
        
        void levelOrder(){
            queue<Node<T>*> cola; 
            if(!this->root) return;
            
            while(!cola.empty()){
                if
            }
        }
};


int main() {
    BinarySearchTree<int> a;
    a.add(0,6);
    a.add(0,10);
    a.add(0,5);
    a.add(0,20);
    a.add(0,3);
    a.inOrder(a.get_root()); 
    
    // a.add(0,90);
    // a.add(0,20);
}