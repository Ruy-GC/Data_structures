/*
Programa que implementa las funcion de un arbol max-heap

Autor: Ruy Guzmán Camacho A01639912
Entrega: 22/10/2021
*/
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

template <class T> class Node {
  public:
      T data;
      int key;

        Node(T new_data,int key){
            this->data = new_data;
            this->key = key;
        }

        Node(){
            data = NULL;
            key = NULL;
        }
};

template <class T> class priority_queue {
    private:
        vector<Node<T>*> tree;
        
    public:
        priority_queue(){

        }

        //O(log n)
        void push(T data, int key){
            Node<T> *new_node = new Node<T>(data,key);
            tree.push_back(new_node);

            int i = tree.size()-1;
            while (i != 0 && tree[parent(i)]->key < tree[i]->key){
                swap( tree ,i, parent(i));
                i = parent(i);
            }
        }     

        //O(log n)
        void pop(){
            if(tree.size() == 0) 
                return;
            else if(tree.size() == 1){
                tree.erase(tree.begin());
            }else{
                tree.erase(tree.begin());
                 
                int i = tree.size()-1;
                for(int x = 0; x < tree.size(); x++){
                    if(tree[parent(i)]->key < tree[i]->key){
                        swap( tree ,i, parent(i));
                    }
                    i --; 
                }
            }
        }

        void printTree(){
            for(int i = 0; i < tree.size(); i++){
              cout<<tree[i]->key<<", ";
            }
            cout<<endl;
        }

        void swap(vector<Node<T>*>&tree,int i1,int i2){
            Node<T> *temp = tree[i1];
            tree[i1] = tree[i2];
            tree[i2] = temp;
        }
        
        //O(1)
        bool empty(){
          return tree.size() == 0;
        }

        //O(1)
        int size(){
          return tree.size();
        }

        //O(1)
        Node<T> * top(){
            if(tree.empty()) return NULL;
            return tree[0];
        }

        int parent(int i) { return (i-1)/2; }
};

int main() {
    vector<int>numeros(10,0);
    for(int i = 0; i < 3; i++){
        priority_queue<int> maxh;

        generate(numeros.begin(),numeros.end(),[]() {
            return (rand() % 100)+1;
        });

        maxh.push(1,numeros[0]);
        maxh.push(2,numeros[1]); 
        maxh.push(3,numeros[2]); 
        maxh.push(4,numeros[3]);         
        maxh.push(5,numeros[4]);         
        maxh.push(6,numeros[5]);         
        maxh.push(7,numeros[6]);    
        maxh.push(8,numeros[7]);
        maxh.push(9,numeros[8]); 
        maxh.push(10,numeros[9]); 
        maxh.printTree(); 
        cout<<"Funcion Top: "<<maxh.top()->key<<endl;
        maxh.pop();
        cout<<"Arbol despues del pop"<<endl;
        maxh.printTree(); 

        if(maxh.empty()){
            cout<<"El arbol está vacio"<<endl;
        }else{
            cout<<"El arbol tiene "<< maxh.size()<< " nodos\n\n"<<endl;
        }

    }

    priority_queue<int> maxh;
    if(maxh.empty()){
            cout<<"El arbol está vacio"<<endl;
            if(!maxh.top())
            cout<<"No hay elementos para la función top\n";
    }else{
            cout<<"El arbol tiene "<< maxh.size()<< " nodos\n\n"<<endl;
            cout<<"Funcion Top: "<<maxh.top()->key <<endl;;
    }
    cout<<"\nPop a arbol vacio: ";
    maxh.printTree();
    maxh.push(1,10);

    cout<<"Pop a arbol con un solo elemento: \nArbol:";
    maxh.printTree();
    maxh.pop();
    cout<<"Arbol despues del pop: ";
    maxh.printTree();

    maxh.push(2,45);
    maxh.push(3,7);
    maxh.push(3,35);
    cout<<"Arbol despues de ingresar datos: ";
    maxh.printTree();
    cout<<"Arbol despues del pop: ";
    maxh.pop();
    maxh.printTree();

    return 0;
}