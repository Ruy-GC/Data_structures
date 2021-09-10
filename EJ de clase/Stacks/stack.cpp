#include <iostream>

using namespace std;

template <class T> class Node {
    private:
        T data; // The object information
        Node* down; //element below
    public:
        Node(T new_data,Node* down_node){
            this->data = new_data;
            this->down = down_node;
        }

        Node(T new_data){
            this->data = new_data;
            this->down = NULL;
        }

        void set_data(T new_data){
            this->data = new_data;
        }

        T get_data(){
            return this->data;
        }

        void set_down(Node *down_node){
            this->down = down_node;
        }

        Node* get_down(){
            return this->down;
        }
   
};

template <class T> class CustomStack{
    Node<T> *head;
    int n;

    public:
        CustomStack(){
            head = NULL;
            n = 0;
        }

        ~CustomStack(){

        }

        void push(T data){
            Node<T>* node = new Node<T>(data,this->head);
            this->head = node;
            n++;
        }

        T pop(){
            T data;
            if(this->head){
                Node<T>* node = this->head;
                data = this->top();
                this->head = this->head->get_down();
                delete node;
                n--;
            }

            return data;
        }

        bool isEmpty(){
            return this->head;
        }

        void print_list(){
            Node<T>* current_node = this->head;
            
            cout<<"Pila: ";
            while (current_node != NULL){
                cout <<current_node->get_data()<< "-> ";
                current_node = current_node->get_down();
            }
            cout << endl;
        }

        T top(){
            T data;
            if(this->head){
                data = this->head->get_data();
            }
            return data;
        }

};


int main(){
    
    CustomStack<int> test;

    test.push(1);
    test.push(2);
    test.push(3);
    test.push(4);
    test.push(5);
    test.push(6);
    test.push(7);


    test.print_list();
    cout<<"Top: "<<test.top()<<endl;
    cout<<"Deleted: "<<test.pop()<<endl;

    if(test.isEmpty()){
        cout<<"hay datos en la pila"<<endl;
    }else{
        cout<<"la pila está vacia"<<endl;
    }

    test.print_list();
    cout<<"Top: "<<test.top()<<endl;

    return 0;
}