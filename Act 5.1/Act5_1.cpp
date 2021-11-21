#include <iostream>
#include <list>
#include <type_traits>
#include <string>
#include <vector>
#include <utility>
#include <math.h>
using namespace std;

template <class T> class Hash {
    public:
        int buckets;
        int qbuckets;
        vector<list<pair<int,T>>> chainHashTable;
        vector<vector<pair<int,T>>> quadHashTable;

        //bool isInt;

        Hash(int buckets){
            this->buckets = buckets;
            this->qbuckets = buckets;
            for(int i = 0; i < buckets; i++){
                list<pair<int,T>> temp;
                chainHashTable.push_back(temp);
            }

            vector<pair<int,T>> new_row(buckets);
            quadHashTable.push_back(new_row);
        }

        //O(1) calcula la llave para el valor
        int hashFunction(int key){
            return key % buckets;
        }

        int quadraticFunction(int n){
            if(qbuckets != 0 && ((qbuckets & qbuckets-1)== 0)){
                return (pow(n,2)+n)/2;

            }else{
                bool primo = true;;
                for(int i = 2; i < qbuckets; i++){
                    if(qbuckets % i == 0)
                        primo = false;
                }
                if(primo) return pow(n,2);
            }
            return -1;
        }

        void quadratic(int key, T item){
            int limit = log2(qbuckets);
            bool colision = false;

            int H = hashFunction(key);
            int P = quadraticFunction(0);
            
            if(quadHashTable.size() == 1){

            }

            while(colision){
                while(P < limit){
                    P = quadraticFunction(0);
                }  
            }
        }

        //O(1)
        void chain(int key, T item){
            pair<int,T> new_element (key,item);
            int index = hashFunction(key);
            auto &list = chainHashTable[index];
            
            for(auto &itr: list){
                if(itr.first == key){
                    itr.second = item;
                    cout<<"Valor actualizado"<<endl;
                    return;
                }
            }
            chainHashTable[index].push_back(new_element);
        }

        //imprime la tabla hash con manejo de colisiones por encadenamiento
        void printChain(){
            cout<<"(key,data)"<<endl;
            for(int i = 0; i < buckets; i++){
                cout<<i<<": ";
                for(auto pair:chainHashTable[i]){
                    cout<<pair.first<<","<<pair.second<<" -> ";
                }
                cout<<"\n";
            }
        }

        void prinQuad(){
            cout<<"(key,data)"<<endl;
            for(int i = 0; i < quadHashTable.size(); i++){
                for(int j = 0; j < buckets; j++){
                    cout<<"("<<quadHashTable[i][j].first<<","<<quadHashTable[i][j].second<<") ";
                }
                cout<<"\n";
            }
        }

};

int main(){
    Hash<int> Test (5);
    Test.chain(10,25);
    Test.chain(15,26);
    Test.chain(5,27);
    Test.chain(13,1);
    Test.chain(18,2);
    Test.chain(8,23);
    
    Test.printChain();
    Test.prinQuad();
}