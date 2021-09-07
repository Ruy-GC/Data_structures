#include <iostream>
using namespace std;

struct persona{
    char nombre[20];
    int edad;
}persona1;



int main(){
    cout<<"Nombre: ";
    cin.getline(persona1.nombre,20,'\n');
    cout<<"Edad: ";
    cin>>persona1.edad;

    cout<<"Nombre 1 "<<persona1.nombre<<endl;
    cout<<"Edad 1 "<<persona1.edad<<endl;

    


    return 0;
}