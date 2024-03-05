#include <stdio.h>

struct Pessoa{
   char nome[50];
   int idade;
};


struct Pessoa receberDados() {

   struct Pessoa p;

   printf("Digite o nome da pessoa: ");
   scanf("%s", p.nome);


   printf("Digite a idade da pessoa: ");
   scanf("%d", &p.idade);

   return p;
}

void mostrarDados(struct Pessoa p) {
   printf("Nome: %s - Idade: %d\n", p.nome, p.idade);
}

int main(void) {

   struct Pessoa pes = receberDados();
   mostrarDados(pes);

   struct Pessoa grupo[5];
   grupo[0] = receberDados();

   for (int i = 0; i < 5; i++)
   {
      grupo[i] = receberDados();
   }
   
   for (int i = 0; i < 5; i++)
   {
      mostrarDados(grupo[i]);
   }

   return 0;
}
