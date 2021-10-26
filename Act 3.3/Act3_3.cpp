/*
Programa que implementa las funcion de un arbol avl

Autor: Ruy Guzmán Camacho A01639912
Entrega: 25/10/2021
*/

#include <iostream>
#include <queue> 
#include <algorithm>  
#include <time.h>

using namespace std;

template <class T> class Node {
    public:
        T data; 
        int key;
        Node* left;
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

template <class T> class AVLTree {
    public:
        Node<T> *root; 
    
        AVLTree<T>(){
            this->root = NULL; 
        } 

        ~AVLTree(){
        }

        //O(log n)
        void insert(Node<T>*&current_node,T data, int key){
            if(current_node == NULL){
                Node<T> *new_node = new Node<T>(data,key);
                current_node = new_node;

            }else if(current_node->key > key){
                insert(current_node->left,data,key);
            }else{
                insert(current_node->right,data,key);
            }

            //AVL properties
            rotation(current_node);
        }

        //AVL properties for insert function
        void rotation(Node<T> *&current_node){
            int balance = balanceF(current_node);

            if(balance == 2 && balanceF(current_node->left) == 1){
                current_node = LLrotate(current_node);
            }else if(balance == 2 && balanceF(current_node->left) == -1){
                current_node = LRrotate(current_node);
            }else if(balance == -2 && balanceF(current_node->right) == -1){
                current_node = RRrotate(current_node);
            }else if(balance == -2 && balanceF(current_node->right) == 1){
                current_node = RLrotate(current_node);
            }      
        }

        //AVL properties for delete function
        void rotationDelete(Node<T> *&current_node){
            int balance = balanceF(current_node);
            //case 1A
            if(balance == 2 && balanceF(current_node->left) == 1){
                current_node = LLrotate(current_node);
            }else if(balance == 2 && balanceF(current_node->left) == -1){
                //case 1B
                current_node = LRrotate(current_node);
            }else if(balance == 2 && balanceF(current_node->left) == 0){
                //case 1C
                current_node = LLrotate(current_node);
            }else if(balance == -2 && balanceF(current_node->right) == -1){
                //case 2A
                current_node = RRrotate(current_node);
            }else if(balance == -2 && balanceF(current_node->right) == 1){
                //case 2B
                current_node = RLrotate(current_node);
            }else if(balance == -2 && balanceF(current_node->right) == 0){
                //case 2C
                current_node = RRrotate(current_node);
            }
        }

        //O(log n)
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

        //get height of subtree
        int height(Node<T> *node){
            if(!node) return 0;
            int leftH = height(node->left);
            int rightH = height(node->right);
            //height of the node is the max between left subtree's and right subtree's height +1
            return max(leftH, rightH)+1;
        }

        //calculate balance factor
        int balanceF(Node<T> *node){
            if(!node) return 0;
            return height(node->left) - height(node->right);
        }

        //left-left rotation
        Node<T> *LLrotate(Node<T> *n1){
            //left node
            Node<T> *n2 = n1->left;
            
            //separates n1 and n2 since n2->right is NUll
            n1->left = n2->right;
            //sets n1 as n2's right
            n2->right = n1;

            return n2;
        }

        //right-right rotation
        Node<T> *RRrotate(Node<T> *n1){
            //right node
            Node<T> *n2 = n1->right;
            //separates n1 and n2 since n2->left is NUll
            n1->right = n2->left;
            //sets n1 as n2's left
            n2->left = n1;

            return n2;
        }

        //right-left rotation
        Node<T> *RLrotate(Node<T> *n1){
            //right node
            Node<T> *n2 = n1->right;
            //right-left node
            Node<T> *n3 = n2->left;

            //separates n2 and n3 since n3->right is NUll
            n2->left = n3->right;
            //sets n3 as n1's right
            n1->right = n3->left;
            //sets n2 as n3's left
            n3->right = n2;
            //sets n1 as n3's right, n3 becomes new root
            n3->left = n1;

            return n3;
        }

        //left-right rotation
        Node<T> *LRrotate(Node<T> *n1){
            //left node
            Node<T> *n2 = n1->left;
            //left-right node
            Node<T> *n3 = n2->right;
            
            //separates n2 and n3 since n3->left is NUll
            n2->right = n3->left;
            //sets n3 as n1's left
            n1->left = n3->right;
            //sets n3's left as n2
            n3->left = n2;
            //sets n3's right as n2, n3 becomes new root
            n3->right = n1;

            return n3;
        }
        
        //shows tree horizontaly
        void showTree(Node<T> *tree, int count){
            if (tree == NULL){
                return;
            }else{
                showTree(tree->right, count +1);
                for(int i =0;i < count; i++){
                    cout<<"       ";
                }
                cout<<tree->key<<endl;
                showTree(tree->left, count +1);
            }
        }

        //auxiliary function for deleteNode
        Node<T>* minimum_element(Node<T>* current_node){
            //gets most left item
            if(!current_node->left){
                return current_node;
            }
            return minimum_element(current_node->left);
        }

        //O(log n)
        Node<T>* deleteNode(Node<T> *current_node,int key_delete){

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
            //AVL properties
            rotationDelete(current_node);
            return current_node;    
        }
};

int main(){
    int key = 0;
    char op = 's';
    int count = 10;
    AVLTree<int> a;
    vector<int>numeros(9,0);
    srand(time(0));

    generate(numeros.begin(),numeros.end(),[]() {
            return (rand() % 100)+1;
    });

    for(int i = 0; i < 9; i++){
        a.insert(a.root,i+1,numeros[i]);
    }

    cout<<"\nArbol generado aleatoriamente\n"<<endl;
    a.showTree(a.root,0);
    cout<<"\n\n";

    while(op == 's'){
        cout<<"Desea insertar un nodo? (s/n): ";
        cin>>op;
        if(op == 's'){
            cout<<"Ingrese la llave del nodo a insertar: ";
            cin>>key;
            count ++;
            a.insert(a.root,count,key);

            cout<<"Nuevo arbol\n"<<endl;
            a.showTree(a.root,0);
        }

        cout<<"Desea borrar un nodo? (s/n): ";
        cin>>op;
        if(op == 's'){
            cout<<"Ingrese la llave del nodo a borrar: ";
            cin>>key;
            a.root = a.deleteNode(a.root,key);
            cout<<"Arbol despues de borrar el nodo: \n"<<endl;
            a.showTree(a.root,0);
        }
        cout<<"Desea buscar un nodo? (s/n): ";
        cin>>op;
        if(op == 's'){
            cout<<"Ingrese la llave del nodo a buscar: ";
            cin>>key;
            Node<int> *search_node = a.search(a.root,key);
            if(search_node){
                cout<<"El nodo con la llave "<<search_node->key<< " existe y contiene el dato: "<<search_node->data<<endl;
            }else{
                cout<<"No existe un nodo con esa llave"<<endl;
            }
        }

        cout<<"Desea continuar? (s/n): ";
        cin>>op;
    }
    return 0;

}