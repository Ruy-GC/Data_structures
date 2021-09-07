#include <iostream>
using namespace std;

struct Node{
    int value;
    struct Node *r;
    struct Node *z;
};

Node *createNode(int n){
    Node *new_node = new Node();
    new_node->value = n;
    new_node->z = NULL;
    new_node->r = NULL;
    return new_node;
}

void add(Node *&tree, int n){
    if(tree == NULL){
        Node *new_node = createNode(n);
        tree = new_node;
    }else{
        int root_v = tree->value;
        if(root_v > n){
            add(tree->z,n);
        }else{
            add(tree->r,n);
        }
    }
}

void showTree(Node *tree, int count){
    if (tree == NULL){
        return;
    }else{
        showTree(tree->r, count +1);
        for(int i =0;i < count; i++){
            cout<<"   ";
        }
        cout<<tree->value<<endl;
        showTree(tree->z, count +1);
    }


}

bool search(Node *tree,int n){
    if(tree == NULL){
        return false;
    }else if(tree->value == n){
        return true;
    }else if (tree->value > n){
        return search(tree->z,n);
    }else{
        return search(tree->r,n);
    }
}


int menu(){
    system("cls");
    int op = 0;
    cout<<"opciones:"<<endl;
    cout<<"1. Agregar nodo"<<endl;
    cout<<"2. Ver arbol"<<endl;
    cout<<"3. Buscar elemento"<<endl;
    cout<<"0. salir"<<endl;
    cin>>op;
    return op;
}

Node *tree =  NULL;

int main(){
    int n = 0;

    while(n != -1){
        int op = menu();

        switch (op){
        case 1:
            cout<<"Ingrese un valor: ";
            cin>>n;
            add(tree,n);
            cout<<endl;
            system("pause");
            break;
        
        case 2:
            showTree(tree,0);
            cout<<endl;
            system("pause");
            break;
        case 3:
            cout<<"Ingrese un valor: ";
            cin>>n;
            if(search(tree,n)){
                cout<<"Elemento "<<n<<" encontrado"<<endl;
            }else{
                cout<<"Elemento no encontrado"<<endl;
            }
            cout<<endl;
            system("pause");
            break;
        case 0:
            n = -1;
            break;
        }
    }

    return 0;
}