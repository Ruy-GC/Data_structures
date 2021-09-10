/*
Programa que ordena y busca elementos de arreglos de enteros mediante 
3 algoritmos de ordenamiento y 2 algoritmos de busqueda 

Autor: Ruy Guzmán Camacho A01639912
Creación: 31/08/2021
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

//Función para imprimir vectores
void printVector(vector<int> numeros){

    for(int i = 0; i <numeros.size(); i++){
        if(i+1 < numeros.size()){
            cout<<numeros[i] <<", ";
        }else{
            cout<<numeros[i] <<"."<<endl;
        }
    }
}

//Complejidad: O(n) en el mejor de los casos O(n^2) en el caso promedio
//Entrada: Vector de enteros
//Salida: ninguna, el vector se ordena por referencia 
void ordenaIntercambio(vector<int> &numeros){

    int n = numeros.size();

    for(int i = 0; i<n-1; i++){
        int minIndex = i;
        for(int j = i+1; j<n;j++){
            if(numeros[j] < numeros[minIndex]){
                minIndex = j;
            }
        }
        int temp = numeros[minIndex];
        numeros[minIndex] = numeros[i];
        numeros[i] = temp;
    }
}

//Complejidad: O(n) en el mejor de los casos O(n^2) en el caso promedio
//Entrada: Vector de enteros
//Salida: ninguna, el vector se ordena por referencia 
void ordenaBurbuja(vector<int> &numeros){

    int n = numeros.size();

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1 ;j++){
            if(numeros[j] > numeros[j+1]){
                int temp = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = temp;
            }
        }
    }
}

//funcion para juntar dos subarrays 
void merge(vector <int> &numeros, int l, int m, int r){

    int n1 = m-l+1;
    int n2 = r-m;
    vector<int> L;
    vector<int> R;
    int i = 0, j = 0;

    for(i = 0; i<n1;i++){
        L.push_back(numeros[l+i]);
    }
    for(j = 0; j<n2;j++){
        R.push_back(numeros[m + j +1]);
    } 

    i = 0; 
    j = 0;
    int k = l;

    while(i < n1 && j <n2){
        if(L[i]<= R[j]){
            numeros[k] = L[i];
            i++;
        }else{
            numeros[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        numeros[k] = L[i];
        i++;
        k++;
    }

    while(j<n2){
        numeros[k] = R[j];
        j++;
        k++;
    }

}

//Complejidad: O(n log n)
//Entrada: Vector de enteros ,indice izquierdo e indice derecho
//Salida: ninguna, el vector se ordena por referencia 
void ordenaMerge(vector<int> &numeros , int l, int r){

    int m = (l+r)/2;

    if(l < r){
        ordenaMerge(numeros,l,m);
        ordenaMerge(numeros,m+1,r);
        merge(numeros,l,m,r);
    }
}

//Complejidad: O(1) en el mejor de los casos, O(n) en el peor
//Entrada: Vector de enteros, valor a buscar
//Salida: indice del elemento en el arreglo, -1 si no existe
int busqSecuencial(vector<int> numeros, int k){

    for(int i = 0; i < numeros.size();i++){
        if (numeros[i] == k){
            return i;
        }
    }

    return -1;
}

//Complejidad: O(1) en el mejor de los caos, O(log n) en el peor
//Entrada: Vector de enteros ordenados, valor a buscar
//Salida: indice del elemento en el arreglo, -1 si no existec
int busqBinaria(vector<int> numeros,int k){

    int l = 0;
    int r = numeros.size()-1;

    while (l <= r){
        int m = (l+r)/2;
        if (k == numeros[m]){
            return m;
        }else if( k < numeros[m]){
            r = m-1;
        }else{
            l = m+1;
        }
    }

    return -1;
}

int main(){

    int n = 0;
    int busqueda = 0;

    do{
        cout<<"Ingrese el tamaño del arreglo a generar: ";
        cin>>n;

        if(cin.fail()){
            cin.clear();
            fflush(stdin);
        }
    }while(n <= 0);

    vector<int>numeros(n,0);
    srand(time(0));

    for(int i = 0; i <4; i++){

        generate(numeros.begin(),numeros.end(),[]() {
            int aux = (rand() % 10)+1;
            return (rand() % 1000)+1+aux;
        });

        cout<<"Caso de prueba "<< i+1<<endl;
        cout<<"Sin ordenar: ";
        printVector(numeros);

        int j = 0;
        while(j < 5){

            //asigna el valor de numeros a un vector temporal
            //esto se realiza para mandar un vector desordenado a las funciones
            vector <int> temp = numeros;
            switch (j){
                case 0:

                    cout<<"Ordena Intercambio: ";
                    ordenaIntercambio(temp);
                    printVector(temp);
                    break;

                case 1:

                    cout<<"Ordena Burbuja: ";
                    ordenaBurbuja(temp);
                    printVector(temp);
                    break;

                case 2:

                    cout<<"Ordena Merge: ";
                    ordenaMerge(temp,0,temp.size()-1);
                    printVector(temp);
                    break;

                case 3:

                    cout<<"\nObjetivo de busqueda secuencial: ";
                    cin>>busqueda;
                    //se realiza la busqueda en el vector sin ordenar
                    cout<<"Indice en vector desordenado: "<<busqSecuencial(numeros,busqueda)<<endl;
                    break;

                case 4:

                    cout<<"\nObjetivo de busqueda binaria: ";
                    cin>>busqueda;
                    //se ordena el vector
                    ordenaMerge(temp,0,temp.size()-1);
                    //se envia el vector ordenado a la busqueda binaria
                    cout<<"Indice en vector ordenado: "<<busqBinaria(temp,busqueda)<<endl;
                    break;
            }
            j++;
        }
        cout<<endl;
    }

    return 0;
}