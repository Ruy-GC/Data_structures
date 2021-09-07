#include <iostream>

using namespace std;

template <class T> class Node {
    private:
        T data; // The object information
        Node* prev;
        Node* next; // Pointer to the next node element

    public:
        Node(T new_data,Node* prev_node, Node* next_node){
            this->data = new_data;
            this->next = next_node;
            this->prev = prev_node;
        }

        Node(T new_data){
            this->data = new_data;
            this->next = NULL;
            this->prev = NULL;
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

        void set_prev(Node *prev_node){
            this->prev = prev_node;
        }

        Node* get_prev(){
            return this->prev;
        }
};


template <class T> class CustomLinkedList{
    Node<T> *head, *tail;

    public:
        CustomLinkedList(){
            head = NULL;
            tail = NULL;
        }

        ~CustomLinkedList(){

        }

        // Method adds data to the end of the list
        void add_end(T data){
            if(head == NULL){ //if our list is currently empty
                head = new Node<T>(data); //Create new node of type T
                tail = head;
            }
            else{ //if not empty add to the end and move the tail
                Node<T>* temp = new Node<T>(data);

                this->tail->set_next(temp);
                temp->set_prev(this->tail);

                this->tail = temp;
                tail->set_next(head);
            }
        }

        // Method adds data to the begining of the list
        void add_begin(T data){
            Node<T>* temp = new Node<T>(data,NULL,head);
            this->head->set_prev(temp);
            this->head = temp;
            this->head->set_prev(tail);
        }

        // Method adds info to the begining of the list
        void add_after_node(T value_insert, T value_target){
            Node<T>* current_node = this->head;
            // Search for the node to delete
            while(current_node && current_node->get_data() != value_target){
                current_node = current_node->get_next();
            }

            // current node is empty the node wasn't found 
            if(!current_node){
                return;
            }
            
            Node<T>* next_node = current_node->get_next();

            Node<T>* temp = new Node<T>(value_insert,current_node,next_node);

            if(!next_node){
                this->tail = temp;
            }else{
                next_node->set_prev(temp);
            }
            
            current_node->set_next(temp);
            temp->set_prev(current_node);

            if(current_node == this->tail){
                this->tail = temp;
                this->tail->set_next(head);
            }
        }


        void delete_node(T value){
            if(!this->head){
                // Empty linked list, no values to delete
                return;
            }
            
            // Check if the node to delete is the head
            if(this->head->get_data() == value){
                this->head = this->head->get_next();
                this->head->set_prev(tail);
                return;
            }

            // check if node to delete is the tail
            if(this->tail->get_data() == value){
                this->tail = this->tail->get_prev();
                this->tail->set_next(head);
                return;
            }

            Node<T>* current_node = this->head->get_next();
            // Search for the node to delete
            while ( current_node != head && current_node->get_next()->get_data() != value){
                current_node = current_node->get_next();
            }

            // current node is empty the node wasn't found 
            if(!current_node){
                return;
            }

            Node<T>* node_to_delete = current_node->get_next(); 
            Node<T>* next_node = node_to_delete->get_next();
            next_node->set_prev(current_node);
            current_node->set_next(next_node);

            delete node_to_delete;
        }

        Node<T>* search_node(T value_target){
            Node<T>* current_node = this->head;
            // Search for the node to delete
            while ( current_node && current_node->get_data() == value_target){
                current_node = current_node->get_next();
            }
            return current_node;

            return NULL;
        }

        void print_list(){
            Node<T>* current_node = this->head;
            /*while (current_node->get_prev() != this->head){
                cout <<"<-" <<current_node->get_data() << "-> ";
                
                //cout<<current_node->get_prev()<<"<-"<<current_node<<"->"<<current_node->get_next()<<endl;
                current_node = current_node->get_prev();
            }
            cout <<"<-" <<current_node->get_data() << "-> ";
            cout <<"<-" <<current_node->get_prev()->get_data() << "-> ";*/
            
            while (current_node != tail){
                cout <<"<-" <<current_node->get_data() << "-> ";
                
                //cout<<current_node->get_prev()<<"<-"<<current_node<<"->"<<current_node->get_next()<<endl;
                current_node = current_node->get_next();

            }
            cout <<"<-" <<current_node->get_data() << "-> ";
            
            cout << endl;
        }

        
};



int main(){
    CustomLinkedList<int> firstList;

    firstList.add_end(32);
    //Pause the program until input is received
    firstList.add_end(33);
    firstList.add_end(34);
    firstList.add_begin(31);
    firstList.add_end(36);

    firstList.print_list();
    firstList.delete_node(33);
    //firstList.add_after_node(10, 33);
    firstList.print_list();
    
    /*Node<int>* element = firstList.search_node(11);

    if(element)
        cout << element->get_data() << endl;*/
    return 0;
}