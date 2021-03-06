/*
Programa que implementa una hash table con manejo de colisiones por encadenamiento 
y por prueba cuadrática

Autor: Ruy Guzmán Camacho A01639912
Entrega: 22/11/2021
*/

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <utility>
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

        //O(1) si no hay colisión
        //O(log n) en caso de colisión,  n siendo los espacios de la tabla
        //O(n) en caso de que no se pueda insertar el elemento en la tabla o que tenga iterar n(tamaño de la tabla) veces para ubicarlo
        void quadratic(int key, T item){
            int H = hashFunction(key);
            for(int j = 0; j<qbuckets;j++){
                //prueba cuadrática i representa los intentos de ubicar el elemento
                int index = (H + (j*j)) % qbuckets;

                //si el espacio está vacio o la llave es igual a la ingresada
                if(quadHashTable[index].first == -1 || quadHashTable[index].first == key){
                    quadHashTable[index] = make_pair(key,item);
                    //se logró ubicar el dato, no requiere redimensionamiento
                    fail = false;
                    break;
                }
                //si no se logró ubicar el item se hace verdadero para poder redimensionar la tabla
                fail = true;
            }
        }

        //O(1) si no hay colisión
        //O(L) en caso de colisión, donde L es la longitud de la lista ligada en indice obtenido por el hashing
        void chain(int key, T item){
            pair<int,T> new_element (key,item);
            int index = hashFunction(key);
            
            //obtiene la lista en el indice generado por la función hash
            auto &list = chainHashTable[index];
            
            //si la llave ya existe dentro de la tabla ctualiza el valor
            for(auto &itr: list){
                if(itr.first == key){
                    itr.second = item;
                    return;
                }
            }

            //añade el item a la lista liogada en el indice
            chainHashTable[index].push_back(new_element);
        }

        //función auxiliar de la prueba cuadrática, amplía la tabla hash y devuelve los valores que ya estaban dentor para su reubicación
        vector<pair<int,T>> resizeQuad(){
            vector<pair<int,T>> items;
            //obtiene los datos ya ingresados en la tabla para reubicarlos
            for(int i = 0; i< qbuckets; i++){
                if(quadHashTable[i].first != -1 ){
                    items.push_back(quadHashTable[i]);
                }
            }

            //aumenta el tamaño 2x + 1 donde x es el tamaño actual
            this->qbuckets = (qbuckets * 2) + 1;

            //limpia y redimensiona la tabla
            quadHashTable.clear();
            for(int i = 0; i < qbuckets; i++){
                pair<int,T> new_item (-1,NULL);
                quadHashTable.push_back(new_item);
            }

            //devuelve los datos lamcenados
            return items;
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

        //O(n) siendo n la cantidad de  items a agregar
        //En caso de que se tenga redimensional la tabla n se vuelve (Nuevos items + items en la tabla)
        void quadratic(vector<pair<int,T>> items){
            int i = 0;
            while (i < items.size()){
                this->quadratic(items[i].first,items[i].second);
                if(fail){
                    vector<pair<int,T>> new_items;
                    /*obtiene los datos de la tabla y redimensiona
                    obtener estos datos es necesario para reubicarlos dentro de la tabla
                    esto debe hacerse debido a que puede insertar elementos a una tabla que
                    no esté vacia*/
                    vector<pair<int,T>> prev_items = resizeQuad();
                    new_items.reserve(items.size() + prev_items.size());

                    //los añade junto a los que van a ingresar
                    new_items.insert(new_items.end(),prev_items.begin(),prev_items.end());
                    new_items.insert(new_items.end(),items.begin(),items.end());
                    items = new_items;
                    //reinicia la inserción a la tabla
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
    for(int i = 0; i < 4; i++){
        int buckets = 0;
        int key = 0;
        int item = 1;
        cout<<"Ingrese la antidad de espacios de la hash Table:";
        cin>>buckets;

        Hash<int> Table(buckets);
        vector<pair<int,int>> items;
        cout<<"\nIngrese las llaves a agregar en la tabla (-1 para terminar)\n";

        while (key != -1){
            cout<<"Llave "<<item<<": ";
            cin>>key;
            if(key != -1){
                items.push_back(make_pair(key,item));
            }
            item++;
        }

        cout<<"\nTabla generada con manejo de colisiones por encadenamiento: \n";
        Table.chain(items);
        Table.printChain();

        cout<<"\nTabla generada con manejo de colisiones por prueba cuadratica: \n";
        cout<<"*Si se ingresaron más elememtos que espacios en la tabla habrá un redimensionamiento*\n";
        Table.quadratic(items);
        Table.printQuad();
        cout<<"\n";
        system("pause");
    }
    return 0;
}