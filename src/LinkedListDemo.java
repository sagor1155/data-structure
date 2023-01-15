
public class LinkedListDemo {
    public static void main(String[] args) {
        System.out.println("-------------------------");
        System.out.println("Linked List");
        System.out.println("-------------------------");
        SinglyLinkedList<Integer> linkedList = new SinglyLinkedList<Integer>();
        linkedList.addLast(10).addLast(20).addLast(30).print();
        linkedList.removeLast().print().removeLast().print().removeLast().print();
        linkedList.addLast(30).addLast(20).addLast(10).print();
        linkedList.addFirst(40).addFirst(50).addFirst(60).print();
        linkedList.removeFirst().print().removeFirst().print().removeFirst().print();
        System.out.println("Index of 10: " + linkedList.indexOf(10));
        System.out.println("Index of 70: " + linkedList.indexOf(70));
        System.out.println("Contains 30: " + linkedList.conatins(30));
        System.out.println("Contains 90: " + linkedList.conatins(90));
    }
}

class Node<T> {
    T data;
    Node<T> next;

    public Node(T data, Node<T> next) {
        this.data = data;
        this.next = next;
    }
}

class SinglyLinkedList<T> {
    int size = 0;
    Node<T> head;
    Node<T> tail;

    public int length() {
        return size;
    }

    public boolean isEmpty() {
        return size==0;
    }

    public void clear() {
        head = null;
        tail = null;
        size = 0;
    }

    public SinglyLinkedList<T> print() {
        System.out.printf("[%d] ", length());     
        Node<T> tempNode = head;
        if (tempNode == null) {
            System.out.print("-");    
        } else {
            while (tempNode != null) {
                System.out.print(tempNode.data);
                System.out.print(" ");
                tempNode = tempNode.next;
            }   
        }
        System.out.println("");
        return this;
    }

    public SinglyLinkedList<T> addLast(T data) {
        if (head==null) {
            head = tail = new Node<T>(data, null);            
        } else {
            Node<T> newNode = new Node<T>(data, null);
            tail.next = newNode;
            tail = newNode;
        }
        size++;
        return this;
    }

    public SinglyLinkedList<T> removeLast() {
        if (head==null) {
            return this;
        }

        if (head.next == null) {
            head = null;
            size--;
            return this;
        }

        Node<T> tempNode = head;
        while (tempNode.next != null) {
            if (tempNode.next.next == null) {
                tail = tempNode;
                tail.next = null;
                break;
            }
            tempNode = tempNode.next;
        }
        size--;
        return this;
    }

    public SinglyLinkedList<T> addFirst(T data) {
        if (head==null) {
            head = tail = new Node<T>(data, null);
        } else {
            Node<T> tempNode = head;
            head = new Node<T>(data, null);
            head.next = tempNode;
        }
        size++;
        return this;
    }

    public SinglyLinkedList<T> removeFirst() {
        if (head==null) {
            return this;
        }
        head = (head.next == null) ? null : head.next;
        size--;
        return this;
    }

    public int indexOf(T elem){
        int index = 0;
        for(Node<T> trav = head; trav != null; trav = trav.next, index++){
            if(trav.data == elem){
                return index;
            }
        }
        return -1;
    }

    public boolean conatins(T elem){
        return indexOf(elem) != -1;
    }
}


