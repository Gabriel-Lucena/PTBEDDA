import java.util.LinkedList;

public class Main {
    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();

        // Inserção de elementos
        bst.insert(50);
        bst.insert(30);
        bst.insert(20);
        bst.insert(40);
        bst.insert(70);
        bst.insert(60);
        bst.insert(80);

        // Coletar nós em ordem e imprimir
        LinkedList<Integer> nodeList = bst.collectNodesInOrder();
        System.out.println("Nós em ordem: " + nodeList);
    }
}
