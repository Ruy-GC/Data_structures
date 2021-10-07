#include <iostream>
#include <ctime>
#include <stdlib.h>

template <class T> class Node {
    private:
        T data; // The object information
        Node* left; // Pointer to the next node element
        Node* right;
    public:
        Node(){
            this->data = NULL;
            this->left = NULL;
			      this->right = NULL;
        }
        
        Node(T new_data, Node* left, Node* right){
            this->data = new_data;
            this->left = left;
			      this->right = right;
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
  
};
 
template <class T> class Tree{
  Node<T>* root;
  
  public:
    Tree(){
      root = NULL;
    }

    void add(T data, Node<T>* aux){
      if(root == NULL){
        root->set_data(data);
        return;
      }
      
      if(!aux->get_left && !aux->get_right()){
        
        
      }
      
      if(aux->get_left() && aux->get_right()){
        if(num == 1){
          add(aux->get_left, aux);
        }else{
          add(aux->get_right());
        }
      }


      
      while (!aux->get_left()) {
      
      }
    }  

    void eliminar(Node<T>* current, T value){
      if (root->get_data() == value) {
        root->set_left(NULL);
        root->set_right(NULL);
        root = NULL;
      }
      if (current->get_left() == value) {
        current->set_left(NULL);
      }
      if (current->get_right()() == value) {
        current->set_right(NULL);
      }

      if (current->get_left()) {
        navigate(current->get_left());
      }

      if (current->get_right()()) {
        navigate(current->get_right()());
      }
    }

    void imprimir(Node<T>* current) {
      cout<<current.get_data()<<endl;

      if (current->get_left()) {
        imprimir(current->get_left());
      }

      if (current->get_right()()) {
        imprimir(current->get_right()());
      }
    }
      

    
}; 

int main() {
  
}