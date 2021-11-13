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

    public:
        Graph(){

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

        /*void updateEdgeList(Node<T>*from, Node<T>* to, vector<pair<Node<T>*,Node<T>*>> &edgeList){
            int iFrom = findNode(from);
            int iTo = findNode(to);  
            edgeList.push_back(make_pair(nodes[iFrom],nodes[iTo])); 
        }*/

        void loadGraph(int n, int m,list<Node<int> *> &adyacencia){
            for(int i = 0; i < n; i++){
                Node<T> *new_node = new Node<T>(i+1);
                nodes.push_back(new_node);
            }



            /*vector<pair<string,string>> pairs = readfile();
            
            for(auto &pair : pairs){

                if(edgeList.size() < m){
                    if(nodes.size() < n){
                        Node<T> *new_node1 = new Node<T>(get<0>(pair));
                        Node<T> *new_node2 = new Node<T>(get<1>(pair));
                        updateMatriz(new_node1,new_node2);

                        int iFrom = findNode(new_node1);
                        int iTo = findNode(new_node2);  
                        edgeList.push_back(make_pair(nodes[iFrom],nodes[iTo])); 
                    }
                }
                
            }*/
            cout<<"\n";
        }

        bool isTree(int n, int m,list<Node<int> *> &edgeList){
            vector<Node<T>*> visitados;
            /*visitados.push_back(get<0>(edgeList[0]));
            visitados.push_back(get<1>(edgeList[0]));

            for(int i = 2; i < edgeList.size();i++){
                if(find(visitados.begin(), visitados.end(), get<1>(edgeList[i])) != visitados.end() ){
                    return false;
                }else{
                    visitados.push_back(get<1>(edgeList[i]));
                }
            }*/
            return true;
        }

        /*vector<pair<string, string>> readfile(){
            string filename("input.txt");
            string line;
            string data[2];
            vector<pair<string,string>> pairs;

            ifstream file(filename);

            if(!file.is_open()){
                cout<<"Archivo no encontrado"<<endl;
            }else{
                while(getline(file, line,',')){
                    data[0] = line;
                    getline(file,line);
                    data[1] = line;
                    pairs.push_back(make_pair(data[0],data[1]));
                }
            }
            return pairs;
        }*/
};

int cantidadArcos(vector<int> adyacencia[],int V){
    int m = 0;
    
    for(int v = 0; v < V; ++v){
        for (auto x : adyacencia[v]){
            m++;
        }
    }
    return m;
}


int main(){
    Graph<int> Test;
    //vector<pair<Node<string> *, Node<string> *>> edgeList;
    static const int n = 3;
    vector<int> adyacencia[n];
    adyacencia[0].push_back(1);
    adyacencia[1].push_back(2);
    adyacencia[1].push_back(0);

    for (int v = 0; v < n; ++v){
        cout << v ;
        for (auto x : adyacencia[v])
           cout << "-> " << x;
        printf("\n");
    }

    cout<<"nodos: "<<n<<endl;
    cout<<"arcos: "<<cantidadArcos(adyacencia,3)<<endl;
    //Test.loadGraph(4, 3,adyacencia);
    /*Test.printMatrix();

    for(auto &pair : edgeList){
        cout<<"("<<get<0>(pair)->data<<","<<get<1>(pair)->data<<")";
    }*/

    /*if(Test.isTree(10,10,adyacencia)){
        cout<<"\nEs un arbol"<<endl;
    }else{
        cout<<"\nNo es un arbol"<<endl;
    }*/
    return 0;
}