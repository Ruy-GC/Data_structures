// Programa que calcula la sumatoria de 1 hasta n mediante 3 metodos distintos
// Autor: Ruy Guzmán Camacho A01639912
// Creación: 13/08/2021

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

// Complejidad: O(n) ya que se itera desde 1 hasta n
// Entrada: entero positivo n
// salida: suma de 1 hasta n
int sumaIterativa(int n){

    int suma = 0;

    for (int i = 1; i < n+1; i++) {
        suma += i;
    }
    
    return suma;
}

// Complejidad: O(n) ya que entra en la función de forma recursiva n veces
// Entrada: entero positivo n
// salida: suma de 1 hasta n
int sumaRecursiva(int n){

    if (n == 1) {
        return 1;
    }

    return sumaRecursiva(n-1) + n;
}

// Complejidad: O(1) ya que solo se realiza un único calculo
// Entrada: entero positivo n
// salida: suma de 1 hasta n
int sumaDirecta(int n){

    return (n*(n+1))/2;  
}

int main(){
    
    vector<int>numeros(4,0);
    srand(time(0));
    generate(numeros.begin(),numeros.end(),[]() {
       return (rand() % 100)+1;
    });
    
    for (int i = 0; i <4; i++) {
        cout<<"Suma de 1 hasta "<<numeros[i]<<endl;
        cout<<"Metodo Iterativo: "<<sumaIterativa(numeros[i])<<endl;
        cout<<"Metodo Recursivo: " <<sumaRecursiva(numeros[i])<<endl;
        cout<<"Metodo Matematico: "<<sumaDirecta(numeros[i])<<endl<<endl;
    }
    return 0;
}