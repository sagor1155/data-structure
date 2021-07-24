#include <iostream>


template <class T>
class LinkedList{
    private:
        // Node class
        template <class NT>
        class Node{
            public:
                NT data;
                Node<NT>* next;

                Node(NT elem, Node<NT>* next){
                    this->data = elem;
                    this->next = next;            
                }
        };
        
        int size;
        Node<T>* head;
        Node<T>* tail;

    public:
        ~LinkedList(){
            delete head;
            delete tail;
        }

        LinkedList() : size(0), head(nullptr), tail(nullptr) { }

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
                head = tail = new Node<T>(elem, NULL);
            }else{
                Node<T>* next = head;
                head = new Node<T>(elem, NULL);
                head->next = next;
            }
            size++;
        }

        // add element at the end of the linked list 
        void addLast(T elem){
            if(isEmpty()){
                head = tail = new Node<T>(elem, NULL);
            }else{
                tail->next = new Node<T>(elem, NULL);
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
            Node<T>* prev_head = head;
            if(head->next == NULL){
                head = NULL;
            }else{
                head = head->next;
            }

            size--;      
            if(isEmpty()){
                tail = NULL;
            }else{  // Do memory clean 
                delete prev_head;
            }      
            return data;
        }

        T removeLast(){
            if(isEmpty())   throw "Empty List!";
            T data = tail->data;
            Node<T>* trav = head;
            if(trav->next == NULL){
                return removeFirst();
            }
            
            while(trav->next != NULL){
                if(trav->next->next == NULL){
                    tail = trav;
                    delete trav->next;
                    trav->next = NULL;
                    break;
                }
                trav = trav->next;
            }

            size--;      
            if(isEmpty()){
                head = NULL;
            }else{  // Do memory clean 
                delete tail->next;
                tail->next = NULL;
            } 
            return data;
        }

        // T remove(Node<T>* node){
        //     if(node->next==NULL) return removeLast();   // tail node
            
        //     T data = node->data;
        //     // connect prev and next node 
        //     node->next->prev = node->prev;
        //     node->prev->next = node->next;

        //     // Do memory clean
        //     delete node;
        //     node = node->prev = node->next = NULL;
        //     size--;
        //     return data;
        // }

        // T removeAt(int index){
        //     if(index < 0 || index >= size) throw "Index out of bound!";
        //     Node<T>* trav;
        //     if(index < size/2){     // search from the front of the list
        //         trav = head;
        //         for(int i=0; i!=index; i++){
        //             trav = trav->next;
        //         }
        //     }else{                  // search from the back of the list 
        //         trav = tail;
        //         for(int i=(size-1); i!=index; i--){
        //             trav = trav->prev;
        //         }
        //     }
        //     return remove(trav);
        // }

        // bool remove(T elem){
        //     Node<T>* trav = head;
        //     while (trav != NULL){
        //         if(trav->data == elem){
        //             remove(trav);
        //             return true;
        //         } 
        //         trav = trav->next;
        //     }
        //     return false;
        // }

        int indexOf(T elem){
            int index = 0;
            Node<T>* trav = head;
            for(trav = head; trav != NULL; trav = trav->next, index++){
                if(trav->data == elem){
                    return index;
                }
            }
            return -1;
        }

        bool conatins(T elem){
            return indexOf(elem) != -1;
        }

};


int main(int argc, char** argv){
    std::cout << "Singly linked list implementation" << std::endl;

    try {
        LinkedList<int> list;
        for(int i=1; i<11; i++){
            list.addFirst(i);
        }
        list.print();
        std::cout << "removed: " << list.removeFirst() << std::endl;
        list.print();
        std::cout << "removed: " << list.removeLast() << std::endl;
        list.print();
        std::cout << "removed: " << list.removeFirst() << std::endl;
        list.print();
        std::cout << "removed: " << list.removeLast() << std::endl;
        list.print();
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }

    return 0;
}