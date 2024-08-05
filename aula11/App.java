import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class App {
  public static void main(String[] args) {
    // Instanciando objetos Aluno
    Aluno aluno1 = new Aluno(1, "Astolfo", 20, 30);
    Aluno aluno2 = new Aluno(2, "Beatriz", 20, 30);
    Aluno aluno3 = new Aluno(3, "Catulo", 20, 30);

    // Criando pilha
    Stack<Aluno> pilhaAlunos = new Stack<>();

    // Adicionando alunos na pilha com o push
    // Adicionando Astolfo
    pilhaAlunos.push(aluno1);
    System.out.println("Adicionando o aluno Astolfo na pilha");
    // Adicionando Beatriz
    pilhaAlunos.push(aluno2);
    System.out.println("Adicionando a aluna Beatriz na pilha");
    // Adicionando Catulo
    pilhaAlunos.push(aluno3);
    System.out.println("Adicionando o aluno Catulo na pilha");

    // Removendo alunos da pilha, com o pop, e
    // mostrando o comportamento LIFO

    System.out.println("Pilha (LIFO):");
    while (!pilhaAlunos.isEmpty()) {
      Aluno aluno = pilhaAlunos.pop();
      System.out.println("Removido da pilha: " + aluno.getNome());
    }

    // Criando fila
    Queue<Aluno> filaAlunos = new LinkedList<>();

    // Adicionando alunos à fila (offer/add)
    filaAlunos.offer(aluno1);
    System.out.println("\n\nAdicionando o aluno Astolfo na fila");
    filaAlunos.offer(aluno2);
    System.out.println("Adicionando a aluna Beatriz na fila");
    filaAlunos.offer(aluno3);
    System.out.println("Adicionando o aluno Catulo na fila");

    // Removendo alunos da fila (poll) e mostrando o comportamento FIFO
    System.out.println("\nFila (FIFO):");
    while (!filaAlunos.isEmpty()) {
      Aluno aluno = filaAlunos.poll();
      System.out.println("Removido da fila: " + aluno.getNome());
    }
  }

}
