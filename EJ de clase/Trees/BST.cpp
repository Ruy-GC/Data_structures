#include <iostream>
#include <queue> 
#include <algorithm>  

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
        void preOrder(Node<T> *node){
          	if(node){
                cout << node->get_key() << " "; 
				this->preOrder(node->get_left()); 
				this->preOrder(node->get_right());
         	}
        }

        void inOrder(Node<T> *node){
          	if(node){
				this->inOrder(node->get_left()); 
				cout << node->get_key() << " "; 
				this->inOrder(node->get_right());
         	}
        }

        void postOrder(Node<T> *node){
            if(node){
                this->postOrder(node->get_left()); 
				this->postOrder(node->get_right());
                cout << node->get_key() << " "; 
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
                cout<<temp->get_key()<<" ";
                q.pop();
                q.push(temp->get_left());
                q.push(temp->get_right());
            }
        }

        int height(Node<T> *node){
            if(!node) return 0;
            int leftH = height(node->get_left());
            int rightH = height(node->get_right());

            return max(leftH, rightH)+1;
        }

        Node<T>* get_root(){
            return this->root;
        }  
};


int main() {
    BinarySearchTree<int> a;
    a.add(0,10);
    a.add(0,12);
    a.add(0,5);
    a.add(0,7);
    a.add(0,11);
    a.add(0,20);
    a.add(0,3);

    cout<<a.height(a.get_root())<<endl;
    a.inOrder(a.get_root());
    cout<<endl;
    a.preOrder(a.get_root());
    cout<<endl;
    a.postOrder(a.get_root()); 
    cout<<endl;
    a.byLevel(); 
    

}