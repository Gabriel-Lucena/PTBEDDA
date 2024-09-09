public class Main {
    public static void main(String[] args) {
        BinarySearchTree<Integer> bst = new BinarySearchTree<>();

        try {
            // Inserção de elementos
            bst.insert(50);
            bst.insert(30);
            bst.insert(20);
            bst.insert(40);
            bst.insert(70);
            bst.insert(60);
            bst.insert(80);

            // Percursos
            System.out.print("Percurso em ordem: ");
            bst.inOrderTraversal();

            System.out.print("Percurso pré-ordem: ");
            bst.preOrderTraversal();

            System.out.print("Percurso pós-ordem: ");
            bst.postOrderTraversal();

            // Busca por elementos
            System.out.println("Buscar 40: " + bst.search(40)); // true
            System.out.println("Buscar 90: " + bst.search(90)); // false

            // Remover elementos
            bst.delete(20);
            System.out.print("Em ordem após remover 20: ");
            bst.inOrderTraversal();

            bst.delete(30);
            System.out.print("Em ordem após remover 30: ");
            bst.inOrderTraversal();

            bst.delete(50);
            System.out.print("Em ordem após remover 50: ");
            bst.inOrderTraversal();

            // Coletar nós em ordem usando Collections
            System.out.println("Nós em ordem: " + bst.getNodesInOrder());

        } catch (RuntimeException e) {
            System.out.println("Erro: " + e.getMessage());
        }
    }
}
