import java.util.ArrayList;
import java.util.List;

public class BinarySearchTree<T extends Comparable<T>> {
    private Node<T> root;

    public BinarySearchTree() {
        this.root = null;
    }

    // Método de inserção
    public void insert(T data) {
        root = insertRec(root, data);
    }

    private Node<T> insertRec(Node<T> root, T data) {
        if (root == null) {
            root = new Node<>(data);
            return root;
        }

        if (data.compareTo(root.data) < 0) {
            root.left = insertRec(root.left, data);
        } else if (data.compareTo(root.data) > 0) {
            root.right = insertRec(root.right, data);
        } else {
            // Valores duplicados não são permitidos
            throw new IllegalArgumentException("Valor duplicado: " + data);
        }

        return root;
    }

    // Método de busca
    public boolean search(T data) {
        return searchRec(root, data);
    }

    private boolean searchRec(Node<T> root, T data) {
        if (root == null) {
            return false;
        }

        if (data.compareTo(root.data) < 0) {
            return searchRec(root.left, data);
        } else if (data.compareTo(root.data) > 0) {
            return searchRec(root.right, data);
        } else {
            return true; // Valor encontrado
        }
    }

    // Método de remoção
    public void delete(T data) {
        root = deleteRec(root, data);
    }

    private Node<T> deleteRec(Node<T> root, T data) {
        if (root == null) {
            throw new RuntimeException("Elemento não encontrado: " + data);
        }

        if (data.compareTo(root.data) < 0) {
            root.left = deleteRec(root.left, data);
        } else if (data.compareTo(root.data) > 0) {
            root.right = deleteRec(root.right, data);
        } else {
            // Nó encontrado
            if (root.left == null && root.right == null) {
                // Sem filhos
                return null;
            } else if (root.left == null) {
                // Um filho (direito)
                return root.right;
            } else if (root.right == null) {
                // Um filho (esquerdo)
                return root.left;
            } else {
                // Dois filhos
                T minValue = minValue(root.right);
                root.data = minValue;
                root.right = deleteRec(root.right, minValue);
            }
        }

        return root;
    }

    private T minValue(Node<T> root) {
        T minVal = root.data;
        while (root.left != null) {
            minVal = root.left.data;
            root = root.left;
        }
        return minVal;
    }

    // Percurso em ordem (inOrderTraversal)
    public void inOrderTraversal() {
        if (root == null) {
            throw new RuntimeException("Árvore vazia");
        }
        inOrderRec(root);
        System.out.println();
    }

    private void inOrderRec(Node<T> root) {
        if (root != null) {
            inOrderRec(root.left);
            System.out.print(root.data + " ");
            inOrderRec(root.right);
        }
    }

    // Percurso pré-ordem (preOrderTraversal)
    public void preOrderTraversal() {
        if (root == null) {
            throw new RuntimeException("Árvore vazia");
        }
        preOrderRec(root);
        System.out.println();
    }

    private void preOrderRec(Node<T> root) {
        if (root != null) {
            System.out.print(root.data + " ");
            preOrderRec(root.left);
            preOrderRec(root.right);
        }
    }

    // Percurso pós-ordem (postOrderTraversal)
    public void postOrderTraversal() {
        if (root == null) {
            throw new RuntimeException("Árvore vazia");
        }
        postOrderRec(root);
        System.out.println();
    }

    private void postOrderRec(Node<T> root) {
        if (root != null) {
            postOrderRec(root.left);
            postOrderRec(root.right);
            System.out.print(root.data + " ");
        }
    }

    // Utilização de Collections: coletar nós em ordem em uma lista
    public List<T> getNodesInOrder() {
        List<T> nodeList = new ArrayList<>();
        collectInOrder(root, nodeList);
        return nodeList;
    }

    private void collectInOrder(Node<T> root, List<T> nodeList) {
        if (root != null) {
            collectInOrder(root.left, nodeList);
            nodeList.add(root.data);
            collectInOrder(root.right, nodeList);
        }
    }
}
