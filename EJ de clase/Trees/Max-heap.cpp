#include <vector>
#include <cmath>
#include <iostream>
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

template <class T> class MaxHeapTree {
    private:
        vector<Node<T>*> tree;
        
    public:
        MaxHeapTree(){

        }

        void push(T data, int key){
            Node<T> *new_node = new Node<T>(data,key);
            tree.push_back(new_node);

            int i = tree.size()-1;

            while (i != 0 && tree[parent(i)]->key < tree[i]->key){
                swap( tree ,i, parent(i));
                i = parent(i);
            }
        }
        
        void printTree(){
            for(int i = 0; i < tree.size(); i++){
              cout<<tree[i]->key<<" ";
            }
            cout<<endl;
        }

        void swap(vector<Node<T>*>&tree,int i1,int i2){
            Node<T> *temp = tree[i1];
            tree[i1] = tree[i2];
            tree[i2] = temp;
        }
        
        bool empty(){
          return tree.size() == 0;
        }

        int size(){
          return tree.size();
        }

        Node<T> * top(){
          return tree[0];
        }

        int parent(int i) { return (i-1)/2; }
        
        // to get index of left child of node at index i
        int left(int i) { return (2*i + 1); }
  
        // to get index of right child of node at index i
        int right(int i) { return (2*i + 2); }
};

int main() {
    MaxHeapTree<int> tree;
    tree.push(2,30);
    tree.push(2,50); 
    tree.push(2,10); 
    tree.push(2,20);         
    tree.push(2,25);         
    tree.push(2,11);         
    tree.push(2,12);      
    tree.printTree();
}