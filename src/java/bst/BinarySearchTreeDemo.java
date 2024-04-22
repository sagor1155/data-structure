package src.java.bst;

public class BinarySearchTreeDemo {
    public static void main(String[] args) {
        System.out.println("Binary Search Tree Demo");
        BinarySearchTree<Integer> bst = new BinarySearchTree<>();
        bst.insert(10);
        bst.insert(5);
        bst.insert(15);

        bst.insert(3);
        bst.insert(6);

        bst.insert(12);
        bst.insert(17);

        bst.remove(10);

        bst.traverse(BinarySearchTree.OrderType.PRE_ORDER);

    }
}

class BinarySearchTree<T extends Comparable<T>> {
    private Node<T> root = null;

    public enum OrderType {
        PRE_ORDER,
        IN_ORDER,
        POST_ORDER,
        LEVEL_ORDER,
    }

    private static final class Node<T> {
        T data;
        Node<T> left;
        Node<T> right;
        public Node(T data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
        public Node(T data, Node<T> left, Node<T> right) {
            this.data = data;
            this.left = left;
            this.right = right;
        }
    }

    public void insert(T data) {
        if (root==null) {
            root = new Node<>(data);
        } else {
            root = insert(data, root);
        }
    }

    private Node<T> insert(T data, Node<T> currNode) {
        if (currNode == null) {
            currNode = new Node<>(data);
        } else {
            if (data.compareTo(currNode.data) < 0) { // add to left
                currNode.left = insert(data, currNode.left);
            } else if (data.compareTo(currNode.data) > 0) { // add to right
                currNode.right = insert(data, currNode.right);
            }
        }
        return currNode;
    }

    public T remove(T data) {
        Node<T> node = root;
        root = remove(data, node);
        return data;
    }

    private Node<T> findMinNode(Node<T> node) {
        Node<T> currNode = node;
        while (currNode != null && currNode.left != null) {
            currNode = currNode.left;
        }
        return currNode;
    }

    private Node<T> remove(T data, Node<T> currNode) {
        if (currNode==null) return currNode;

        // search
        if (data.compareTo(currNode.data) < 0) {
            currNode.left = remove(data, currNode.left);
        } else if (data.compareTo(currNode.data) > 0) {
            currNode.right = remove(data, currNode.right);
        } else {
            // node to be removed - is a leaf node
            if (currNode.left==null && currNode.right==null) {
                currNode = null;
            }
            // node to be removed - has only left node
            else if (currNode.right==null) {
                currNode = currNode.left;
            }
            // node to be removed - has only right node
            else if (currNode.left==null) {
                currNode = currNode.right;
            }
            // node to be removed - has both left & right node
            else {
                // find minimum node on right subtree
                Node<T> node = findMinNode(currNode.right);
                currNode.data = node.data;
                currNode.right = remove(node.data, currNode.right);
            }
        }

        return currNode;
    }

    public void traverse(OrderType orderType) {
        switch (orderType) {
            case PRE_ORDER -> preOrder(root);
            case IN_ORDER -> inOrder(root);
            case POST_ORDER -> postOrder(root);
            case LEVEL_ORDER -> levelOrder(root);
        }
    }

    private void preOrder(Node<T> currNode) {
        if (currNode==null) return;
        System.out.println(currNode.data);
        preOrder(currNode.left);
        preOrder(currNode.right);
    }

    private void inOrder(Node<T> currNode) {
        if (currNode==null) return;
        inOrder(currNode.left);
        System.out.println(currNode.data);
        inOrder(currNode.right);
    }

    private void postOrder(Node<T> currNode) {
        if (currNode==null) return;
        postOrder(currNode.left);
        postOrder(currNode.right);
        System.out.println(currNode.data);
    }

    private void levelOrder(Node<T> currNode) {

    }

}
