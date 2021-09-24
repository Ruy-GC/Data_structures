#include <iostream>

using namespace std;

template <class T> class Node {
    private:
        T data; // The object information
        Node* next; //element below 
        int priority;
    public:
        Node(T new_data,Node* next_node, int priority){
            this->data = new_data;
            this->next = next_node;
            this->priority = priority;
        }

        Node(T new_data){
            this->data = new_data;
            this->next = NULL;
            this->priority = -1;
        }

        void set_data(T new_data){
            this->data = new_data;
        }

        void set_priority(int priority){
            this->priority = priority;
        }
        
        T get_priority(){
            return this->priority;
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

        void push(T data, int priority){
            Node<T>* node = new Node<T>(data,NULL,priority);
            if(this->head == NULL) { 
              this->head = node; 
              this->rear = node;
            } else { 
              Node<T>* current_node = this->head;             
              while( (current_node->get_next() != NULL) && (current_node->get_next()->get_priority() <= priority)){
                current_node = current_node->get_next();
              } 
              Node<T> *temp = current_node->get_next();
              current_node->set_next(node); 
              node->set_next(temp); 
              if(!temp){
                this->rear = node;
              }
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
        
        void get_rear(){
          cout<<this->rear->get_data()<<endl;
        }
};


int main() { 
  CustomQueue<int> test;
  test.push(3,0);
  test.push(4,1);
  test.push(2,0);
  test.push(1,1);
  test.push(8,2);
  test.push(1,1);
  test.push(5,0);

  test.print_list();
  
  cout<<test.pop()<<endl; 
  test.print_list();
  cout << test.top() << endl;
  test.print_list();

  test.get_rear();

}