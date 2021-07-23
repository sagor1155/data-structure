#include <iostream>


template <class T>
class DoublyLinkedList{
    private:
        // Node class
        template <class NT>
        class Node{
            public:
                NT data;
                Node<NT>* prev;
                Node<NT>* next;

                Node(NT elem, Node<NT>* prev, Node<NT>* next){
                    this->data = elem;
                    this->prev = prev;
                    this->next = next;            
                }
        };
        
        int size;
        Node<T>* head;
        Node<T>* tail;

    public:
        ~DoublyLinkedList(){
            delete head;
            delete tail;
        }

        DoublyLinkedList() : size(0), head(nullptr), tail(nullptr) { }

        void print(){
            std::cout << "[LIST]  ";
            Node<T>* trav = head;
            while(trav != NULL){
                std::cout << trav->data << "  "; 
                trav = trav->next;
            }
            std::cout << " " << std::endl;
        }

        int getSize(){
            return size;
        }

        bool isEmpty(){
            return getSize()==0;
        }

        // clear linked list 
        void clear(){
            Node<T>* trav = head;
            while(trav != NULL){
                Node<T>* next = trav->next;
                trav->data = 0;
                trav->prev = NULL;
                trav->next = NULL;
                trav = next;
            }
            trav = head = tail = NULL;
            size = 0;
        }

        // add node to the tail
        void add(T elem){
            addLast(elem);
        }

        // add element at the beginning of the linked list 
        void addFirst(T elem){
            if(isEmpty()){
                head = tail = new Node<T>(elem, NULL, NULL);
            }else{
                head->prev = new Node<T>(elem, NULL, head);
                head = head->prev;
            }
            size++;
        }

        // add element at the end of the linked list 
        void addLast(T elem){
            if(isEmpty()){
                head = tail = new Node<T>(elem, NULL, NULL);
            }else{
                tail->next = new Node<T>(elem, tail, NULL);
                tail = tail->next;
            }
            size++;
        }

        T peekFirst(){
            if(isEmpty())   throw "Empty List!";
            return head->data;
        }

        T peekLast(){
            if(isEmpty())   throw "Empty List!";
            return tail->data;
        }

        T removeFirst(){
            if(isEmpty())   throw "Empty List!";
            T data = head->data;
            head = head->next;
            size--;      
            if(isEmpty()){
                tail = NULL;
            }else{  // Do memory clean 
                delete head->prev;
                head->prev = NULL;
            }      
            return data;
        }

        T removeLast(){
            if(isEmpty())   throw "Empty List!";
            T data = tail->data;
            tail = tail->prev;
            size--;      
            if(isEmpty()){
                head = NULL;
            }else{  // Do memory clean 
                delete tail->next;
                tail->next = NULL;
            } 
            return data;
        }
};


int main(int argc, char** argv){
    std::cout << "Doubly linked list implementation" << std::endl;

    try {
        DoublyLinkedList<int> list;
        for(int i=1; i<11; i++){
            list.addFirst(i);
        }
        list.print();
        list.removeLast();
        list.print();
        list.removeLast();
        list.print();
        list.removeLast();
        list.print();

    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }

    return 0;
}