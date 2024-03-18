#include <stdio.h>

struct Aluno
{
   int numeroMatricula;
   char nome[50];
   double nota1;
   double nota2;
   double nota3;
};

struct Aluno receberDados()
{
   struct Aluno aluno;

   printf("Digite a matrícula do aluno: \n");
   scanf("%d", &aluno.numeroMatricula);

   printf("Digite o nome do aluno: \n");
   scanf("%s", aluno.nome);

   printf("Digite a nota 1 do aluno: \n");
   scanf("%lf", &aluno.nota1);

   printf("Digite a nota 2 do aluno: \n");
   scanf("%lf", &aluno.nota2);

   printf("Digite a nota 3 do aluno: \n");
   scanf("%lf", &aluno.nota3);

   printf("\n");

   return aluno;
}

void mostrarDados(struct Aluno aluno)
{
   printf("Número de Matrícula: %d\n", aluno.numeroMatricula);
   printf("Nome: %s\n", aluno.nome);
   printf("Nota 1: %lf\n", aluno.nota1);
   printf("Nota 2: %lf\n", aluno.nota2);
   printf("Nota 3: %lf\n", aluno.nota3);

   printf("\n");
}

int maiorNota(struct Aluno alunos[5])
{
   int maiorNota = alunos[0].nota1;
   int indice = 0;

   for (int i = 0; i < 5; i++)
   {
      if (alunos[i].nota1 > maiorNota)
      {
         maiorNota = alunos[i].nota1;
         indice = i;
      }
   }

   return alunos[indice].numeroMatricula;
}

double media(struct Aluno aluno)
{
   return (aluno.nota1 + aluno.nota2 + aluno.nota3) / 3.0;
}

int maiorMedia(struct Aluno alunos[5])
{
   double maiorMedia = media(alunos[0]);

   int indice = 0;

   for (int i = 0; i < 5; i++)
   {
      if (media(alunos[i]) > maiorMedia)
      {
         maiorMedia = media(alunos[i]);
         indice = i;
      }
   }

   return alunos[indice].numeroMatricula;
}

int menorMedia(struct Aluno alunos[5])
{
   double menorMedia = media(alunos[0]);

   int indice = 0;

   for (int i = 0; i < 5; i++)
   {
      if (media(alunos[i]) < menorMedia)
      {
         menorMedia = media(alunos[i]);
         indice = i;
      }
   }

   return alunos[indice].numeroMatricula;
}

void resultadoFinal(struct Aluno alunos[5])
{
   printf("\n");

   for (int i = 0; i < 5; i++)
   {
      if (media(alunos[i]) >= 6)
      {
         printf("O aluno de matrícula %d e nome %s está aprovado\n", alunos[i].numeroMatricula, alunos[i].nome);
      }

      if (media(alunos[i]) < 6)
      {
         printf("O aluno de matrícula %d e nome %s está reprovado\n", alunos[i].numeroMatricula, alunos[i].nome);
      }

      printf("\n");
   }
}

int main(void)
{

   struct Aluno alunos[5];

   for (int i = 0; i < 5; i++)
   {
      alunos[i] = receberDados();
   }

   printf("O aluno com a maior nota na primeira prova foi o aluno:\n%d\n", maiorNota(alunos));
   printf("O aluno com a menor média geral foi o aluno:\n%d\n", menorMedia(alunos));
   printf("O aluno com a maior média geral foi o aluno:\n%d\n", maiorMedia(alunos));
   resultadoFinal(alunos);

   return 0;
}
