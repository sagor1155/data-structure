package src.java.stack;

public class ReverseArray {
    public static void main(String[] args) {
        System.out.println("-----------------");
        System.out.println("Reverse Array");
        System.out.println("-----------------");
        Integer[] revArray = reverseArray(new Integer[]{1, 2, 3, 4, 5});
        for (Integer item : revArray) {
            System.out.print(item);
            System.out.print(" ");
        }
        System.out.println("");

    }   
    
    public static Integer[] reverseArray(Integer[] arr) {
        Integer[] revArray = new Integer[arr.length];
        Stack<Integer> stack = new Stack<Integer>();
        for (int i=0; i<arr.length; i++) {
            stack.push(arr[i]);
        }
        stack.print();
        for (int i=0; i<arr.length; i++) {
            revArray[i] = stack.pop();
        }
        return revArray;
    }
}
