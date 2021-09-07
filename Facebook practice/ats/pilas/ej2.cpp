#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    char value;
    Node *next;
};

void addPile(Node *&stack ,char n){
    Node *new_node = new Node();
    new_node->value = n; //asigna valor al nuevo nodo
    new_node->next = stack;// apunta el puntero next del nuevo nodo a la pila
    stack = new_node;//pila ahora es igual a nuevo nodo

    cout<<"Element "<<n<<" added"<<endl;
}

void showPile(Node *&stack){
    Node *aux = stack->next;

    if(aux->next != NULL){
        cout<<aux->value<< ", ";
    }else{
        cout<<aux->value<< ".";
    }
    
    showPile(aux);
}

int main(){

    Node *stack = NULL;
    char n;

    while(n != '0'){
        cout<<"Ingrese un numero, para terminar ingrese 0: ";
        cin>>n;
        if(n != 0){
            addPile(stack,n);
        }
    }

    cout<<"Pile (top - bottom):"<<endl;
    showPile(stack);

    return 0;
}