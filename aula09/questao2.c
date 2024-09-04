#include <stdio.h>
#include <string.h>

// Algoritmo Quick Sort adaptado para Strings

// Função para trocar duas strings
void trocar(char *a, char *b)
{
  char temp[100];
  strcpy(temp, a);
  strcpy(a, b);
  strcpy(b, temp);
}

// Funções para Quick Sort
int particionar(char vetor[][100], int baixo, int alto)
{
  char pivo[100];
  strcpy(pivo, vetor[alto]);
  int i = (baixo - 1);

  for (int j = baixo; j <= alto - 1; j++)
  {
    if (strcmp(vetor[j], pivo) < 0)
    {
      i++;
      trocar(vetor[i], vetor[j]);
    }
  }
  trocar(vetor[i + 1], vetor[alto]);
  return (i + 1);
}

void ordenacaoRapida(char vetor[][100], int baixo, int alto)
{
  if (baixo < alto)
  {
    int pi = particionar(vetor, baixo, alto);
    ordenacaoRapida(vetor, baixo, pi - 1);
    ordenacaoRapida(vetor, pi + 1, alto);
  }
}

// Algoritmo Bubble Sort adaptado para Strings

// Função para Bubble Sort
void ordenacaoBolha(char vetor[][100], int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (strcmp(vetor[j], vetor[j + 1]) > 0)
      {
        trocar(vetor[j], vetor[j + 1]);
      }
    }
  }
}

// Função para imprimir o vetor
void imprimirVetor(char vetor[][100], int tamanho)
{
  for (int i = 0; i < tamanho; i++)
    printf("%s\n", vetor[i]);
}

int main()
{
  // Vetor de nomes dos alunos
  char vetor1[][100] = {"Carlos", "Ana", "Bruno", "Daniel", "Elisa"};
  char vetor2[][100] = {"Carlos", "Ana", "Bruno", "Daniel", "Elisa"};
  int n = sizeof(vetor1) / sizeof(vetor1[0]);

  // Imprimindo os nomes fornecidos
  printf("Nomes fornecidos: \n");
  imprimirVetor(vetor1, n);

  // Ordenando e imprimindo os nomes com Quick Sort
  ordenacaoRapida(vetor1, 0, n - 1);
  printf("\nNomes ordenados por Quick Sort: \n");
  imprimirVetor(vetor1, n);

  // Ordenando e imprimindo os nomes com Bubble Sort
  ordenacaoBolha(vetor2, n);
  printf("\nNomes ordenados por Bubble Sort: \n");
  imprimirVetor(vetor2, n);

  return 0;
}
