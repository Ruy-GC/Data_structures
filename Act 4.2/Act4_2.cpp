#include <iostream>
#include <vector>
#include <utility>   
#include <fstream>
#include <utility>     
#include <algorithm>
#include <list>
using namespace std;

template <class T> class Node {
    public:
        T data;

        Node(T new_data){
          	this->data = new_data;
        }
};

template <class T> class Graph{
    private:
        vector<Node<T>*> nodes;
        vector<vector<int>> matrix;
        vector<list<T>> listaAdj;
        int n,m;
    public:
        Graph(){

        }
        
        Graph(int n, int m, vector<list<T>> &listaAdj){
            loadGraph(n,m,listaAdj);
        }

        void printMatrix(){
            for (auto &row : matrix) {
                for(auto &col : row) {
                    cout << col << " ";
                }
                cout <<"\n"; 
            }
        }

        int findNode(Node<T>* test) {
                for(int i = 0; i < nodes.size(); i++){
                    if(nodes[i]== test || nodes[i]->data == test->data){
                        return i;
                    }
                }
                return -1;
        }

        void updateMatriz(Node<T>*from, Node<T>*to){
            int iFrom = findNode(from);
            int iTo = findNode(to);
                
            if(iFrom == -1){
                nodes.push_back(from);

                vector<int> newRow = vector<int>(nodes.size(),0);
                matrix.push_back(newRow);

                for(int i = 0; i < nodes.size()-1;i++){
                    matrix[i].push_back(0);
                }
            }

            if(iTo == -1){
                if(to->data == -1) return;
                nodes.push_back(to);

                vector<int> newRow = vector<int>(nodes.size(),0);
                matrix.push_back(newRow);

                for(int i = 0; i < nodes.size()-1;i++){
                    matrix[i].push_back(0);
                }
            }

            iFrom = findNode(from);
            iTo = findNode(to);

            matrix[iFrom][iTo] = 1;
        }

        //O(n log n) siendo n los nodos totales de la lista
        void loadGraph(int n, int m,vector<vector<int>> &adyacencia){
            int x = 0;
            int arcos =0;
            for(int i = 0; i < n; i++){
                if(adyacencia[i].size() == 1){
                    Node<T> *new_node1 = new Node<T>(adyacencia[i][0]);
                    Node<T> *new_node2 = new Node<T>(-1);
                    updateMatriz(new_node1,new_node2);

                }else{
                    x = 1;
                    while(arcos < m){
                        Node<T> *new_node = new Node<T>(adyacencia[i][0]);
                        Node<T> *new_node2 = new Node<T>(adyacencia[i][x]);
                        updateMatriz(new_node, new_node2);
                        x++;
                        arcos++;
                        if(x == adyacencia[i].size()) break;
                    }
                }
            }
            cout<<"\n";
        }

        //O()
        bool isTree(int n, int m,vector<vector<int>> adyacencia){
            vector<T> visitados;
            for(int i = 1; i < adyacencia[0].size();i++){
                visitados.push_back(adyacencia[0][i]);
            }

            int j = 1;
            int arcos = 0;
            for(int i = 1; i < n; i++){
                j = 1;
                if(adyacencia[i].size() != 1){
                    while(arcos < m){
                        if(find(visitados.begin(), visitados.end(),adyacencia[i][j]) != visitados.end()){
                            return false;
                        }else{
                            visitados.push_back(adyacencia[i][j]);
                            j++;
                            arcos++;
                            if(j == adyacencia[i].size()) break;
                        }    
                    }
                }
                
                
            }
            return true;
        }
};

int cantidadArcos(vector<vector<int>> adyacencia,int V){
    int m = 0;
    
    for (int v = 0; v < V; ++v){
        m += adyacencia[v].size() -1;
    }
    return m;
}


int main(){
    Graph<int> Test;
    vector<vector<int>> adyacencia;

    adyacencia.push_back({0,1,2});
    adyacencia.push_back({1,2});
    adyacencia.push_back({2});

    for (int v = 0; v < adyacencia.size(); ++v){
        for (auto x : adyacencia[v])
           cout << x << "-> ";
        printf("\n");
    }

    cout<<"\nnodos: "<<adyacencia.size()<<endl;
    cout<<"arcos: "<<cantidadArcos(adyacencia,adyacencia.size())<<endl;

    Test.loadGraph(adyacencia.size(),cantidadArcos(adyacencia,adyacencia.size()), adyacencia);
    cout<<"Grafo Generado: "<<endl;
    Test.printMatrix();

    if(Test.isTree(adyacencia.size(),cantidadArcos(adyacencia,adyacencia.size()),adyacencia)){
        cout<<"\nEs un arbol"<<endl;
    }else{
        cout<<"\nNo es un arbol"<<endl;
    }
    return 0;
}