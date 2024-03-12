#include <stdio.h>

struct Aluno {
   int numeroMatricula;
   char nome[50];
   double nota1;
   double nota2;
   double nota3;
};

int maiorMedia (struct Aluno[]) {
// Pega o tamanho, vê a quantidade de itens
// e calcula-se a médias e suas respectivas
// comparações

}

struct Aluno receberDados() {

   struct Aluno aluno;

   printf("Digite a matrícula do aluno: \n");
   scanf("%d", &aluno.numeroMatricula);

   printf("Digite o nome do aluno: \n");
   scanf("%s", &aluno.nome);

   printf("Digite a nota 1 do aluno: \n");
   scanf("%lf", &aluno.nota1);

   printf("Digite a nota 2 do aluno: \n");
   scanf("%lf", &aluno.nota2);

   printf("Digite a nota 3 do aluno: \n");
   scanf("%lf", &aluno.nota3);

   printf("\n");

   return aluno;
}

void mostrarDados(struct Aluno aluno) {
   printf("Número de Matrícula: %d\n", aluno.numeroMatricula);
   printf("Nome: %s\n", aluno.nome);
   printf("Nota 1: %lf\n", aluno.nota1);
   printf("Nota 2: %lf\n", aluno.nota2);
   printf("Nota 3: %lf\n", aluno.nota3);

   printf("\n");
}

int main(void) {

   struct Aluno alunos[5];
   alunos[0] = receberDados();

   for (int i = 0; i < 5; i++)
   {
      alunos[i] = receberDados();
   }

   for (int i = 0; i < 5; i++)
   {
      mostrarDados(alunos[i]);
   }

   return 0;
}
