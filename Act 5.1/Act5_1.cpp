#include <iostream>
#include <list>
#include <type_traits>
#include <string>
#include <vector>
#include <utility>
#include <math.h>
using namespace std;

template <class T> class Hash {
    private:
        int buckets;
        int qbuckets;
        bool fail;
        vector<list<pair<int,T>>> chainHashTable;
        vector<pair<int,T>> quadHashTable;

        //O(1) calcula la llave para el valor
        int hashFunction(int key){
            return key % buckets;
        }

        //Mejor: O(1) si no hay colisión
        //Promedio: O(log n) en caso de colisión,  n siendo los espacios de la tabla
        //Peor: O(n) 
        void quadratic(int key, T item){
            int H = hashFunction(key);
            for(int j = 0; j<qbuckets;j++){
                int index = (H + (j*j)) % qbuckets;
                if(quadHashTable[index].first == -1 || quadHashTable[index].first == key){
                    quadHashTable[index] = make_pair(key,item);
                    fail = false;
                    break;
                }
                fail = true;
            }
            if(fail) resizeQuad();  
        }

        //Mejor: O(1) si no hay colisión
        //Promedio: O(L) en caso de colisión, donde L es la longitud de la lista ligada en el espacio de la tabla
        void chain(int key, T item){
            pair<int,T> new_element (key,item);
            int index = hashFunction(key);
            auto &list = chainHashTable[index];
            
            for(auto &itr: list){
                if(itr.first == key){
                    itr.second = item;
                    return;
                }
            }
            chainHashTable[index].push_back(new_element);
        }

        //función auxiliar de la prueba cuadrática, amplía la tabla hash
        void resizeQuad(){
            this->qbuckets *= 2;
            quadHashTable.clear();
             for(int i = 0; i < qbuckets; i++){
                pair<int,T> new_item (-1,NULL);
                quadHashTable.push_back(new_item);
            }
        }

    public:
        //cosntructor
        Hash(int buckets){
            this->buckets = buckets;
            this->qbuckets = buckets;
            this->fail = true;
            for(int i = 0; i < buckets; i++){
                list<pair<int,T>> temp;
                chainHashTable.push_back(temp);
                pair<int,T> new_item (-1,NULL);
                quadHashTable.push_back(new_item);
            }
        }
        
        //O(n) siendo n la cantidad de  items a agregar
        //función de prueba por encadenamiento para el usuario 
        void chain(vector<pair<int,T>> items){
            for(int i = 0; i < items.size();i++){
                this->chain(items[i].first,items[i].second);
            }
        }

        //Mejor: O(n) siendo n la cantidad de  items a agregar
        //Peor: O(n^2) siendo n la cantidad de  items a agregar si se tiene que redimensionar la tabla
        //función de prueba cuadratica para el usuario 
        void quadratic(vector<pair<int,T>> items){
            int i = 0;
            while (i < items.size()){
                this->quadratic(items[i].first,items[i].second);
                if(fail){
                    i = 0;
                }else{
                    i++;
                }
            }
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

        //imprime la tabla hash con manejo de colisiones por prueba cuadrática
        void printQuad(){
            cout<<"(key,data)"<<endl;
            for(int i = 0; i < qbuckets; i++){
                cout<<"("<<quadHashTable[i].first<<","<<quadHashTable[i].second<<") ";
            }
            cout<<"\n";
        }

};

int main(){
    Hash<int> Test (4);
    vector<pair<int,int>> items;
    items.push_back(make_pair(10,25));
    items.push_back(make_pair(15,26));
    items.push_back(make_pair(5,27));
    items.push_back(make_pair(13,1));
    items.push_back(make_pair(18,2));
    items.push_back(make_pair(8,3));

    Test.chain(items);
    Test.quadratic(items);
    
    Test.printChain();
    Test.printQuad();
}