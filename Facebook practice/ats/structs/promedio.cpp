#include <iostream>
using namespace std;

struct promedio{
    float c1;
    float c2;
    float c3;
};

struct alumno{
    char nombre[20];
    char sexo[10];
    int edad;
    struct promedio prom;
}alumno1;

int main(){

    cout<<"Nombre: ";
    cin.getline(alumno1.nombre,20,'\n');
    cout<<"Sexo: ";
    cin.getline(alumno1.sexo,10,'\n');  
    cout<<"Edad: ";
    cin>>alumno1.edad;
    fflush(stdin);  

    cout<<"\nNotas: "<<endl;
    cout<<"Nota 1: ";
    cin>>alumno1.prom.c1;
    cout<<"Nota 2: ";
    cin>>alumno1.prom.c2;
    cout<<"N3ta 3: ";
    cin>>alumno1.prom.c3;

    float promedio = 0.0;
    promedio = (alumno1.prom.c1 +  alumno1.prom.c2 + alumno1.prom.c3)/3;
    cout<<"Promedio: "<<promedio<<endl;
    return 0;
}