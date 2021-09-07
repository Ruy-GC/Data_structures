#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int value;
    Node *next;
};

void addPile(Node *&stack ,int n){
    Node *new_node = new Node();
    new_node->value = n; //asigna valor al nuevo nodo
    new_node->next = stack;// apunta el puntero next del nuevo nodo a la pila
    stack = new_node;//pila ahora es igual a nuevo nodo

    cout<<"Element "<<n<<" added"<<endl;
}

void deletePile(Node *&pile ,int &n){
    Node *aux = pile;
    n = aux->value; //save value to delete
    pile = aux->next; // pile is now the next node
    delete aux; //delete aux node;
}

int main(){
    Node *stack = NULL;
    int n = 0;

    while(n >= 0){
        cout<<"Ingrese un numero, para terminar ingrese un valor <0: ";
        cin>>n;
        if(n >= 0){
            addPile(stack,n);
        }
    }

    cout<<"Sacando elementos de la pila"<<endl;;
    while(stack != NULL){
        deletePile(stack,n);
        if(stack != NULL){
            cout<<n<<", ";
        }else{
            cout<<n<<".";
        }
    }
    



    return 0;
}