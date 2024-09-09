import java.util.List;
import java.util.LinkedList;

public class BinarySearchTree {
    private Node root;

    public BinarySearchTree() {
        this.root = null;
    }

    // Método de inserção
    public void insert(int data) {
        root = insertRec(root, data);
    }

    private Node insertRec(Node root, int data) {
        if (root == null) {
            root = new Node(data);
            return root;
        }

        if (data < root.data) {
            root.left = insertRec(root.left, data);
        } else if (data > root.data) {
            root.right = insertRec(root.right, data);
        }

        return root;
    }

    // Percurso em ordem (inOrderTraversal)
    public void inOrderTraversal() {
        inOrderRec(root);
        System.out.println();
    }

    private void inOrderRec(Node root) {
        if (root != null) {
            inOrderRec(root.left);
            System.out.print(root.data + " ");
            inOrderRec(root.right);
        }
    }

    // Método auxiliar usando List (LinkedList ou ArrayList)
    public LinkedList<Integer> collectNodesInOrder() {
        LinkedList<Integer> nodeList = new LinkedList<>();
        collectInOrderRec(root, nodeList);
        return nodeList;
    }

    private void collectInOrderRec(Node root, List<Integer> nodeList) {
        if (root != null) {
            collectInOrderRec(root.left, nodeList);
            nodeList.add(root.data);
            collectInOrderRec(root.right, nodeList);
        }
    }
}
