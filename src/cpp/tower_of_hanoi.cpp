
#include <iostream>
#include <string>

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

        void print(std::string str){
            std::cout << "[" + str + "]  ";
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

        T remove(Node<T>* node){
            if(node->prev==NULL) return removeFirst();  // head node
            if(node->next==NULL) return removeLast();   // tail node
            
            T data = node->data;
            // connect prev and next node 
            node->next->prev = node->prev;
            node->prev->next = node->next;

            // Do memory clean
            delete node;
            node = node->prev = node->next = NULL;
            size--;
            return data;
        }

        T removeAt(int index){
            if(index < 0 || index >= size) throw "Index out of bound!";
            Node<T>* trav;
            if(index < size/2){     // search from the front of the list
                trav = head;
                for(int i=0; i!=index; i++){
                    trav = trav->next;
                }
            }else{                  // search from the back of the list 
                trav = tail;
                for(int i=(size-1); i!=index; i--){
                    trav = trav->prev;
                }
            }
            return remove(trav);
        }

        bool remove(T elem){
            Node<T>* trav = head;
            while (trav != NULL){
                if(trav->data == elem){
                    remove(trav);
                    return true;
                } 
                trav = trav->next;
            }
            return false;
        }

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

DoublyLinkedList<int> list1;
DoublyLinkedList<int> list2;
DoublyLinkedList<int> list3;

void shift_from(int start, int end){
    // std::cout << start << " -> " << end << std::endl;

    DoublyLinkedList<int>* list_start;
    DoublyLinkedList<int>* list_end;
    switch (start)
    {
    case 1: list_start=&list1; break;
    case 2: list_start=&list2; break;
    case 3: list_start=&list3; break;
    default:
        break;
    }
    switch (end)
    {
    case 1: list_end=&list1; break;
    case 2: list_end=&list2; break;
    case 3: list_end=&list3; break;
    default:
        break;
    }

    list_end->add(list_start->removeLast());
}

void hanoi(int n, int start, int end){
    if(n==1){
        shift_from(start, end);
    }else{
        int other = 6 - (start + end);
        hanoi(n-1, start, other);
        shift_from(start, end);
        hanoi(n-1, other, end);
    }
}

int main(int argc, char** argv){
    std::cout << "Towers of hanoi Problem" << std::endl;
    
    int n=10;
    for(int i=1; i<n+1; i++){
        list1.addFirst(i);
    }

    std::cout << "Before solving: \n";
    list1.print("List1");
    list2.print("List2");
    list3.print("List3");

    hanoi(n, 1, 3);

    std::cout << "After solving: \n";
    list1.print("List1");
    list2.print("List2");
    list3.print("List3");
}