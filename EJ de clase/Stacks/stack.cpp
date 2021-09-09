#include <iostream>

using namespace std;

template <class T> class Node {
    private:
        T data; // The object information
        Node* prev; //element below
    public:
        Node(T new_data,Node* prev_node){
            this->data = new_data;
            this->prev = prev_node;
        }

        Node(T new_data){
            this->data = new_data;
            this->prev = NULL;
        }

        void set_data(T new_data){
            this->data = new_data;
        }

        T get_data(){
            return this->data;
        }

        void set_prev(Node *prev_node){
            this->prev = prev_node;
        }

        Node* get_prev(){
            return this->prev;
        }
   
};

template <class T> class CustomStack{
    Node<T> *top;

    public:
        CustomStack(){
            top = NULL;
        }

        ~CustomStack(){

        }

        void push(T data){
            if(top == NULL){
                this->top = new Node<T>(data); //Create new node of type T
            }else{
                Node<T>* temp = new Node<T>(data);
                temp->set_prev(top);
                this->top = temp;
            }
        }

        void pop(){
            if(top == NULL){
                return;
            }else{
                Node<T>* temp = top->get_prev();
                top = temp;
            }
        }

        void print_list(){
            Node<T>* current_node = this->top;
            
            while (current_node != NULL){
                cout <<current_node->get_data()<< "-> ";
                current_node = current_node->get_prev();
            }
            cout << endl;
        }

        int Top(){
            return this->top->get_data();
        }

};


int main(){
    
    CustomStack<int> test;

    test.push(1);
    test.push(2);
    test.push(3);

    test.print_list();

    test.pop();

    test.print_list();
    cout<<"Top "<<test.Top()<<endl;

    return 0;
}