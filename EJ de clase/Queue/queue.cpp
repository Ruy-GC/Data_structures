#include <iostream>

using namespace std;

template <class T> class Node {
    private:
        T data; // The object information
        Node* next; //element below 
    public:
        Node(T new_data,Node* next_node){
            this->data = new_data;
            this->next = next_node;
        }

        Node(T new_data){
            this->data = new_data;
            this->next = NULL;
        }

        void set_data(T new_data){
            this->data = new_data;
        }
        
        T get_data(){
            return this->data;
        }

        void set_next(Node *next_node){
            this->next = next_node;
        }

        Node* get_next(){
            return this->next;
        }
   
};

template <class T> class CustomQueue{
    Node<T> *head, *rear;
    int n;

    public:
     CustomQueue(){
            head = NULL;
            rear = NULL;
            n = 0;
        }

        ~CustomQueue(){

        }

        void push(T data){
            Node<T>* node = new Node<T>(data,NULL);
            if(this->head == NULL) { 
              this->head = node; 
              this->rear = node;
            }else { 
               this->rear->set_next(node);           
               this->rear = node;
            }
            n++;
        }

        T pop(){
            T data;
            if(this->head){
                Node<T>* node = this->head;
                data=this->head->get_data();
                this->head = this->head->get_next();
                delete node;
                n--;
            }

            return data;
        }

        bool isEmpty(){
            return this->head == NULL;
        }

        void print_list(){
            Node<T>* current_node = this->head;
            
            cout<<"Queue: ";
            while (current_node != NULL){
                cout <<current_node->get_data()<< "<-";
                current_node = current_node->get_next();
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


int main() { 
  CustomQueue<int> test;
  test.push(3);
  test.push(2);
  test.push(1);

  test.print_list();
  
  cout<<test.pop()<<endl; 
  test.print_list();
  cout << test.top() << endl;
}