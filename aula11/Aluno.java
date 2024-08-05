public class Aluno {

  private int matricula;
  private String nome;
  private int idade;
  private int IRA;

  // métodos get e set
  public void setMatricula(int matricula) {
    this.matricula = matricula;
  }

  public int getMatricula() {
    return this.matricula;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public String getNome() {
    return this.nome;
  }

  public void setIdade(int idade) {
    this.idade = idade;
  }

  public int getIdade() {
    return this.idade;
  }

  public void setIRA(int IRA) {
    this.IRA = IRA;
  }

  public int getIRA() {
    return this.IRA;
  }

  // construtor explícito
  public Aluno(int matricula, String nome, int idade, int IRA) {
    this.matricula = matricula;
    this.nome = nome;
    this.idade = idade;
    this.IRA = IRA;
  }
}