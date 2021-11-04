#include <bits/stdc++.h>

using namespace std;

template <class T> class Node {
  public:
      T data;
      vector<Node<T>*> connections;
  
      Node(T new_data){
          this->data = new_data;
      }
  
      Node(){
        this->data = NULL;
      }
};

template <class T> class Graph{
    public:
        vector<pair<Node<T>*, Node<T>*>> edgeList;
        vector<vector<int>> matrix;
        vector<Node<T>*> nodes;
        Graph(){
        
        }

        void makeConnection(Node<T>*from, Node<T>*to){
          findNode(from, to);
          updateEdgeList(from, to);
          updateMatriz(from, to);
          updateConnection(from, to);

        }

        void printMatrix() {
            for (auto &row : matrix) {
                for(auto &col : row) {
                    cout << col << " ";
                }
                cout <<"\n"; 
            }
        }

        void printNodes(){
          for(auto &node : nodes){
            cout<<node->data;
          }
          cout<<"\n";
        }

    private:
        int findNode(Node<T>* test) {
          for(int i = 0; i < nodes.size(); i++){
            if(nodes[i]== test){
              return i;
            }
          }
          return -1;
        }
        
        void updateEdgeList(Node<T>*from, Node<T>* to){  
          edgeList.push_back(make_pair(from,to)); 
        }

        void updateMatriz(Node<T>*from, Node<T>*to){
            int iFrom = findNode(from);
            int iTo = findNode(to);

            if(iFrom >= 0 && iTo >= 0) {
                // existen los dos
                    // se agrega 1 a coordenada i,j
            } else if (iFrom >= 0) {
                // existe from, pero no existe to
                    // se agrega nodo a atributo
                    nodes.push_back(to);
                    // se recorren las filas
                    for(int i=0; i<matrix.size(); i++){
                        if (i == iFrom) {
                        // si el indice de la fila es == iFrom 
                            //  pushear 1
                            matrix.at(i).push_back(1);
                        } else {
                        // en caso contrario
                            // pushear 0
                            matrix.at(i).push_back(0);
                        }
                    }
                   // agregar fila de 0s del tamaño de nodeds
                    matrix.push_back(vector<int>(nodes.size(), 0));
            } else if(iTo >=0){
                //Existe To, pero no existe From
                // se agrega nodes
                nodes.push_back(from);
                // Se recoren las filas y se pushea 0
                for(auto &it : matrix) it.push_back(0);
                // se crea nueva fila con 0's de [0,iTo) y de (iTo,size(nodes)] 
                vector<int> newRow = vector<int>(nodes.size(), 0);
                newRow[iTo] = 1;
                // 
                matrix.push_back(newRow);

            }else{
              //no existe ni from ni to 
              //agregar una fila a la matriz
              vector<int> new_row(0,nodes.size());
              matrix.push_back(new_row);
              
              //hacer push_back de 0 a todas las filas
              for(int i = 0; i < matrix.size()-1;i++){
                matrix[i].push_back(0)
              }
              
              //cambiar el valor del indice n,m a 1
              matrix[matrix.end()].push_back(1);
            }
        }

        void updateConnection(Node<T> *from, Node<T> *to) {
            from->connections.push_back(to);
        }

};


int main() {
  Node<char> *A('A');
  Node<char> *B('B');
  Node<char> *C('C');

  Graph<char> Test;

  Test.makeConnection(A,B);
  Test.printNodes();
  cout<<"\n";
  Test.printMatrix();
  Test.makeConnection(C,B);
  Test.printNodes();
  cout<<"\n";
  Test.printMatrix();

} 