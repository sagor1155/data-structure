import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

public class BinaryHeap<T extends Comparable<T>>
{
    private List<T> items = null;
    
    private int getLeftChildIndex(int parentIndex) { return (2*parentIndex + 1); }
    private int getRightChildIndex(int parentIndex){ return (2*parentIndex + 2); }
    private int getParentIndex(int childIndex)     { return (childIndex - 1)/2; }
    
    private boolean hasLeftChild(int index)  { return getLeftChildIndex(index)<size(); }
    private boolean hasRightChild(int index) { return getRightChildIndex(index)<size(); }
    private boolean hasParent(int index)     { return getParentIndex(index)>=0; }

    private T leftChild(int index)  { return items.get(getLeftChildIndex(index)); }
    private T rightChild(int index) { return items.get(getRightChildIndex(index)); }
    private T parent(int index)     { return items.get(getParentIndex(index)); }

    private void swap(int indexOne, int indexTwo){
        T temp = items.get(indexTwo);
        items.set(indexTwo, items.get(indexOne));
        items.set(indexOne, temp);
    }

    private void removeLast(){
        items.remove(size()-1);
    }

    /**
     * @desc: bubbles down to maintain minimum heap
     * @proc: 
     *      - run loop until left child is null
     *      - compare parent with smallest child (between left & right)
     *      - if parent >= smallest child then swap and update index
     * @param: parent index
     */
    private void heapifyDown(int index){
        while (hasLeftChild(index)) { // check left child, as for binary heap data inserted at left child first
            int smallChildIndex = getLeftChildIndex(index);
            if (hasRightChild(index) && rightChild(index).compareTo(leftChild(index)) < 0) {
                smallChildIndex = getRightChildIndex(index);
            }
            if (items.get(index).compareTo(items.get(smallChildIndex)) < 0) {
                break;
            } else {
                swap(index, smallChildIndex);
                index = smallChildIndex;
            }
        }
    }

    /**
     * @desc: bubbles up to maintain minimum heap
     * @proc: 
     *      - run loop until parent is null
     *      - compare item (child) with parent
     *      - if parent >= item (child) then swap and update index
     * @param: child index
     */
    private void heapifyUp(int index){
        while (hasParent(index)) {
            if (items.get(index).compareTo(parent(index)) >= 0) {
                break;
            } else {
                swap(index, getParentIndex(index));
                index = getParentIndex(index);
            }
        }
    }

    //--------------------------------- public methods ---------------------------------

    public BinaryHeap(){
        this(1);
    }

    public BinaryHeap(int size){
        items = new ArrayList<T>(size);
    }

    public int size(){
        return items.size();
    }

    public boolean isEmpty(){
        return size()==0;
    }

    public void clear(){
        items.clear();
    }

    public void print(){
        System.out.println(items.toString());
    }

    public T peek(){
        if(size()==0) throw new IllegalArgumentException("Queue is empty!");
        return items.get(0);
    }

    /**
     * @desc: remove and return root element
     * @proc:
     *      - swap root element with last element
     *      - remove last element
     *      - heapify down
     */
    public T poll(){
        if(size()==0) throw new IllegalArgumentException("Queue is empty!");
        T data = items.get(0);
        swap(0, size()-1);
        removeLast();
        heapifyDown(0);
        return data;
    }

    /**
     * @desc: add element
     * @proc:
     *      - add element at the end
     *      - heapify up
     */
    public void add(T elem){
        items.add(elem);
        heapifyUp(size()-1);
    }

    /**
     * @desc: remove element
     * @proc:
     *      - find element index
     *      - remove
     */
    public boolean remove(T elem){
        if(size()==0) throw new IllegalArgumentException("Queue is empty!");
        for (int i = 0; i < size(); i++) {
            if (items.get(i) == elem) {
                removeAt(i);
                return true;
            }
        }
        return false;
    }

    /**
     * @desc: remove element at index
     * @proc: 
     *      - swap with last element
     *      - remove last 
     *      - compare with parent data, if val < parent then heapify up
     *      - otherwise, heapify down
     */
    public T removeAt(int index){
        T data = items.get(index);
        swap(index, size()-1);
        removeLast();
        if (hasParent(index) && data.compareTo(parent(index)) < 0) {
            heapifyUp(index);
        } else {
            heapifyDown(index);
        }
        return data;
    }

    public boolean isMinHeap(int index) {
        return true;
    }

    public static void main(String[] args) {
        System.out.println("-----------------------------");
        System.out.println("Java Custom Priority Queue");
        System.out.println("-----------------------------");
        BinaryHeap<Integer> heap = new BinaryHeap<Integer>();
        for(int i=1; i<16; i++){
            heap.add(i);
        }
        heap.print();
        heap.poll();
        heap.print();
        heap.poll();
        heap.print();
        heap.add(1);
        heap.print();
        heap.add(3);
        heap.print();
        heap.remove(5);
        heap.print();


        System.out.println("-----------------------------");
        System.out.println("Java Built-in Priority Queue");
        System.out.println("-----------------------------");
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        for(int i=1; i<16; i++){
            pq.add(i);
        }
        System.out.println(pq.toString());
        pq.poll();
        System.out.println(pq.toString());
        pq.poll();
        System.out.println(pq.toString());
        pq.add(1);
        System.out.println(pq.toString());
        pq.add(3);
        System.out.println(pq.toString());
        pq.remove(5);
        System.out.println(pq.toString());

        
    }

};
