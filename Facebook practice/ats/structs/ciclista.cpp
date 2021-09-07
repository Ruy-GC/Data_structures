#include <iostream>
using namespace std;

struct Etapa{
    int horas;
    int minutos;
    int segundos;

}Etapas[100];

int main(){
    int N, horasT = 0,minutosT = 0, segundosT = 0;

    cout<<"Etapas: ";
    cin>>N;

    for(int i = 0; i < N; i++){
        cout<<"\nEtapa: "<<i+1<<endl;
        cout<<"Horas: ";
        cin>>Etapas[i].horas;
        horasT += Etapas[i].horas;
        cout<<"Minutos: ";
        cin>>Etapas[i].minutos;
        minutosT += Etapas[i].minutos;
        cout<<"Segundos: ";
        cin>>Etapas[i].segundos;
        segundosT += Etapas[i].segundos;

        if(minutosT >= 60){
            minutosT -= 60;
            horasT ++;
        }

        if(segundosT >= 60){
            segundosT -= 60;
            minutosT ++;
        }
    }

    cout<<"\nTotal: "<<endl;
    cout<<"Horas: "<<horasT<<endl;
    cout<<"Minutos: "<<minutosT<<endl;
    cout<<"Segundos: "<<segundosT<<endl;

    return 0;
}
