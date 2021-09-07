#include <iostream>
#include <stdlib.h>
using namespace std;

//las pilas se rigen por el metodo filo first in last out, solo puedo secar el ultimo elemento
//y solo se agregan al final

struct Node{
    int value;
    Node *next;
};

void addPile(Node *&pile ,int n){
    Node *new_node = new Node();
    new_node->value = n; //asigna valor al nuevo nodo
    new_node->next = pile;// apunta el puntero next del nuevo nodo a la pila
    pile = new_node;//pila ahora es igual a nuevo nodo

    cout<<"Element "<<n<<" added"<<endl;
}

void deletePile(Node *&pile ,int &n){
    Node *aux = pile;
    n = aux->value; //save value to delete
    pile = aux->next; // pile is now the next node
    delete aux; //delete aux node;
}


int main(){

    Node *pile = NULL;
    int n;

    cout<<"Escriba un numero: ";
    cin>>n;
    addPile(pile,n);

    cout<<"Escriba otro numero: ";
    cin>>n;
    addPile(pile,n);

    cout<<"\nSacar elemento de la pila: "<<endl;
    while(pile != NULL){
        deletePile(pile,n);
        if(pile != NULL){
            cout<<n<<", ";
        }else{
            cout<<n<<".";
        }
    }

    return 0;
}
