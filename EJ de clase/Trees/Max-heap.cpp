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
        MaxHeapTree(T new_data,int key){
            Node<T> *root = new Node<T>(new_data,key);
            tree.push_back(root);
        }

        void insert(T data, int key){
          Node<T> *new_node = new Node<T>(data,key);
          tree.push_back(new_node);

          int index = tree.size()-1;

          while(index >= 0){
            
            int parent = floor((index-1)/2);
            if (tree[index] > tree[parent]){
              cout << "son:" << index << endl;
              cout << "parent: " << parent << endl;
              swap(tree,index,parent); 
            }
            index--;
          }
          //if(index != 0){
            
          //}
        }


        void swap(vector<Node<T>*>&tree,int i1,int i2){
          Node<T> *temp = tree[i1];
          tree[i1] = tree[i2];
          tree[i2] = temp;
        }
        
        void printTree(){
          for(int i = 0; i < tree.size(); i++){
            cout<<tree[i]->key<<" ";
          }
          cout<<endl;
        }
        /*
        int parent(int i) { return (i-1)/2; }
        
        // to get index of left child of node at index i
        int left(int i) { return (2*i + 1); }
  
        // to get index of right child of node at index i
        int right(int i) { return (2*i + 2); }*/
};

int main() {
  MaxHeapTree<int> tree(1,20);
  tree.insert(1,30);
  tree.printTree();
  cout << endl;
  tree.insert(2,50); 
  tree.insert(2,10);         
  tree.printTree();
}