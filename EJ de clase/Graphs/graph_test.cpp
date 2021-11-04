#include <iostream>
#include <list>
#include <vector>
#include <utility>   

using namespace std;

template <class T> class Node {
    public:
        T data; 
        list<Node<T>*> connections;

        Node(T new_data){
          	this->data = new_data;
        }
};

template <class T> class Graph{
    public:
        vector<Node<T>*> nodes;
        vector<vector<int>> matrix;
        vector<pair<Node<T>*,Node<T>*>> edgeList;

        Graph(){

        }

        void makeConnection(Node<T>*from, Node<T>*to){
            updateEdgeList(from, to);
            updateMatriz(from, to);
            updateConnection(from, to);
        }

        void printMatrix(){
            for (auto &row : matrix) {
                for(auto &col : row) {
                    cout << col << " ";
                }
                cout <<"\n"; 
            }
        }

        void printNodes(){
            for(auto &node : nodes){
                cout<<node->data<<" ";
            }
            cout<<"\n";
        }

        void printEdgeList(){
            for(auto &pair : edgeList){
                cout<<"("<<get<0>(pair)->data<<","<<get<1>(pair)->data<<")";
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

            void updateConnection(Node<T> *from, Node<T> *to) {
                from->connections.push_back(to);
            }
};

int main() {
    Node<char> *A = new Node<char>('A');
    Node<char> *B = new Node<char>('B');
    Node<char> *C = new Node<char>('C');
    Node<char> *D = new Node<char>('D');


    Graph<char> Test;

    Test.makeConnection(A,B);
    Test.makeConnection(C,B);
    Test.makeConnection(B,D);
    Test.makeConnection(B,A);
    Test.printNodes();
    Test.printMatrix();
    cout<<"\n";
    Test.printEdgeList();

} 