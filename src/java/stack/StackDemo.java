package src.java.stack;

public class StackDemo {
  public static void main(String[] args) {
    System.out.println("---------------------");  
    System.out.println("Stack Implementation");  
    System.out.println("---------------------");
    
    Stack<Integer> stack = new Stack<Integer>();
    stack.push(10).push(20).push(30).push(40).print();
    System.out.println(stack.pop()); stack.print();
    System.out.println(stack.pop()); stack.print();
    System.out.println(stack.pop()); stack.print();
    System.out.println(stack.pop()); stack.print();
    System.out.println(stack.pop()); stack.print();

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

class Stack<T> {
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

    public Stack<T> print() {
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

    public Stack<T> push(T data) {
        // add last
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

    public T pop() {
        if(isEmpty() || head==null){
            System.err.println("Stack is empty!");
            return null;
        }

        // remove last
        if (head.next == null) {
            T data = head.data;
            head = null;
            size--;
            return data;
        }

        Node<T> tempNode = head;
        T data = tail.data;
        while (tempNode.next != null) {
            if (tempNode.next.next == null) {
                tail = tempNode;
                tail.next = null;
                break;
            }
            tempNode = tempNode.next;
        }
        size--;
        return data;
    }


}
