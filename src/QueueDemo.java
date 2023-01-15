
public class QueueDemo {
  public static void main(String[] args) {
    System.out.println("---------------------");  
    System.out.println("Queue Implementation");  
    System.out.println("---------------------");
    
    Queue<Integer> queue = new Queue<Integer>();
    queue.enqueue(10).enqueue(20).enqueue(30).enqueue(40).print();
    System.out.println(queue.dequeue()); queue.print();
    System.out.println(queue.dequeue()); queue.print();
    System.out.println(queue.dequeue()); queue.print();
    System.out.println(queue.dequeue()); queue.print();
    System.out.println(queue.dequeue()); queue.print();

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

class Queue<T> {
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

    public Queue<T> print() {
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

    public Queue<T> enqueue(T data) {
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

    public T dequeue() {
        if(isEmpty() || head==null){
            System.err.println("Queue is empty!");
            return null;
        }

        // remove first
        T data = head.data;
        head = (head.next == null) ? null : head.next;
        size--;
        return data;
    }


}
