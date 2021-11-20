/*
Programa que implementa algoritmos complementarios de un grafo dirigido

Autor: Ruy Guzmán Camacho A01639912
Entrega: 19/11/2021
*/
#include <iostream>
#include <vector>
#include <stack>
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
        vector<bool> recursive;
        vector<bool> visited;
    public:
        Graph(){

        }
        //Imprime matriz de adyacencia
        void printMatrix(){
            for(auto &node : nodes){
                cout<<node->data<<" ";
            }
            cout <<"\n"; 
            for(int i = 0; i < nodes.size()-1; i++){
                cout<<"--";
            }
            cout<<"-\n";
            for (auto &row : matrix) {
                for(auto &col : row) {
                    cout << col << " ";
                }
                cout <<"\n"; 
            }
        }

        //O(n) en en caso promedio, n siendo numero de nodos en el grafo
        //busca un nodo de forma secuencial 
        int findNode(Node<T>* test) {
            for(int i = 0; i < nodes.size(); i++){
                if(nodes[i]== test || nodes[i]->data == test->data){
                    return i;
                }
            }
            return -1;
        }

        //O(1) si ambos nodos exissten en el grafo, O(n) si olo uno existe, O(n^2) si ninguno existe
        //Modifica la matriz de adyacencia
        void updateMatriz(Node<T>*from, Node<T>*to){
            //busca si los nodos existen en el grafo
            int iFrom = findNode(from);
            int iTo = findNode(to);
            
            //si el nodo from no existe
            if(iFrom == -1){
                //agrega el nodo al vector y modifica el tamaño de la matriz
                nodes.push_back(from);
                //añade uan fila a la matriz
                vector<int> newRow = vector<int>(nodes.size(),0);
                matrix.push_back(newRow);

                //añade un 0 a cada fila de la matriz
                for(int i = 0; i < nodes.size()-1;i++){
                    matrix[i].push_back(0);
                }
            }

            if(iTo == -1){
                //si el dato es -1 indica que se envía un nodo sin conexiones
                if(to->data == -1) return;
                //añade el nodo al vector y modifica el tamaño de la matriz
                nodes.push_back(to);
                vector<int> newRow = vector<int>(nodes.size(),0);
                matrix.push_back(newRow);

                for(int i = 0; i < nodes.size()-1;i++){
                    matrix[i].push_back(0);
                }
            }
            
            //obtiene los nuevos indices y agrega un 1 donde se hace la conexión
            iFrom = findNode(from);
            iTo = findNode(to);
            matrix[iFrom][iTo] = 1;
        }

        //O(n+m) siendo n los nodos totales de la lista y m los arcos
        void loadGraph(int n, int m,vector<vector<int>> &adyacencia){
            int x = 0;
            int arcos =0;
            for(int i = 0; i < n; i++){
                //si en el vector solo hay un elemento (no hay arcos) 
                if(adyacencia[i].size() == 1){
                    Node<T> *new_node1 = new Node<T>(adyacencia[i][0]);
                    //se establece el nodo con valor -1 opara indicar que no se hará conexión
                    Node<T> *new_node2 = new Node<T>(-1);
                    updateMatriz(new_node1,new_node2);

                //si se presentan arcos en el nodo
                }else{
                    x = 1;
                    //while para añadir as conexiones a la matriz
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

        //O(n + m) siendo n los nodos totales de la lista y m los arcos
        //Indica si el grafo es un arbol
        //Condiciones para ser un arbol: no presenta ciclos, cada par de nodos solo se conecta por exactamente un camino, no hay nodos sueltos
        bool isTree(int n, int m,vector<vector<int>> adyacencia){
                vector<T> visitados;
                //si el primer vector tiene más de un elemento todos se añaden a visitados
                if(adyacencia[0].size()!=1){
                    for(int i = 0; i < adyacencia[0].size(); i++){
                        visitados.push_back(adyacencia[0][i]);
                    }
                }

                int arcos = 0;
                //por cada nodo restante
                for (int i = 1; i < n; i++) {
                    int j = 1;
                    if(adyacencia[i].size() != 1){
                        while(arcos < m){
                            //si se encuentra en el vector de visitas retorna falso
                            if(find(visitados.begin(), visitados.end(),adyacencia[i][j]) != visitados.end()){
                                //no es un arbol
                                return false;
                            //si no se encuentra
                            }else{
                                //se añade nodo acyual a la lista de visitas
                                visitados.push_back(adyacencia[i][j]);
                                j++;
                                arcos++;
                                if(j == adyacencia[i].size()) break;
                            }    
                        }
                    }
                }

            //si existen nodos sin visitar (sueltos) no es un arbol
            if(visitados.size() != adyacencia.size()){
                for(int i = 0; i <adyacencia.size();i++){
                    if(find(visitados.begin(), visitados.end(),adyacencia[i][0]) == visitados.end() && adyacencia[i].size() ==1){
                        return false;
                    }
                }
            }
            
            //es un arbol
            return true;
        }
};

//función para obtener la cantidad de arcos de la lista de adyacencia
int cantidadArcos(vector<vector<int>> adyacencia,int V){
    int m = 0;
    for (int v = 0; v < V; ++v){
        m += adyacencia[v].size() -1;
    }
    return m;
}


int main(){
    Graph<int> Test;
    Graph<int> Test2;
    Graph<int> Test3;
    Graph<int> Test4;

    vector<vector<int>> adyacencia1;
    adyacencia1.push_back({0});
    adyacencia1.push_back({1});
    adyacencia1.push_back({2});
    adyacencia1.push_back({3,1,2,0});
    adyacencia1.push_back({4,3});
    adyacencia1.push_back({5,4});
    vector<vector<int>> adyacencia2;
    adyacencia2.push_back({0,1});
    adyacencia2.push_back({1,3,4,5});
    adyacencia2.push_back({2});
    adyacencia2.push_back({3,2});
    adyacencia2.push_back({4});
    adyacencia2.push_back({5});
    vector<vector<int>> adyacencia3;
    adyacencia3.push_back({0,2});
    adyacencia3.push_back({1,0});
    adyacencia3.push_back({2,1});
    vector<vector<int>> adyacencia4;
    adyacencia4.push_back({0,1});
    adyacencia4.push_back({1,2,3});
    adyacencia4.push_back({2,4});
    adyacencia4.push_back({3,2,4});
    adyacencia4.push_back({4});

    Test.loadGraph(adyacencia1.size(),cantidadArcos(adyacencia1,adyacencia1.size()),adyacencia1);
    cout<<"Grafo Generado: "<<endl;
    Test.printMatrix();

    if(Test.isTree(adyacencia1.size(),cantidadArcos(adyacencia1,adyacencia1.size()),adyacencia1)){
        cout<<"\nEs un arbol"<<endl;
    }else{
        cout<<"\nNo es un arbol"<<endl;
    }

    Test2.loadGraph(adyacencia2.size(),cantidadArcos(adyacencia2,adyacencia2.size()),adyacencia2);
    cout<<"Grafo Generado: "<<endl;
    Test2.printMatrix();

    if(Test2.isTree(adyacencia2.size(),cantidadArcos(adyacencia2,adyacencia2.size()),adyacencia2)){
        cout<<"\nEs un arbol"<<endl;
    }else{
        cout<<"\nNo es un arbol"<<endl;
    }

    Test3.loadGraph(adyacencia3.size(),cantidadArcos(adyacencia3,adyacencia3.size()),adyacencia3);
    cout<<"Grafo Generado: "<<endl;
    Test3.printMatrix();

    if(Test3.isTree(adyacencia3.size(),cantidadArcos(adyacencia3,adyacencia3.size()),adyacencia3)){
        cout<<"\nEs un arbol"<<endl;
    }else{
        cout<<"\nNo es un arbol"<<endl;
    }

    Test4.loadGraph(adyacencia4.size(),cantidadArcos(adyacencia4,adyacencia4.size()),adyacencia4);
    cout<<"Grafo Generado: "<<endl;
    Test4.printMatrix();

    if(Test4.isTree(adyacencia4.size(),cantidadArcos(adyacencia4,adyacencia4.size()),adyacencia4)){
        cout<<"\nEs un arbol"<<endl;
    }else{
        cout<<"\nNo es un arbol"<<endl;
    }
    return 0;
}