#include <stdio.h>

void ordenacaoBolha(int vetor[], int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (vetor[j] > vetor[j + 1])
      {
        // Troca vetor[j] e vetor[j+1]
        int temp = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = temp;
      }
    }
  }
}

void imprimirVetor(int vetor[], int tamanho)
{
  int i;
  for (i = 0; i < tamanho; i++)
    printf("%d ", vetor[i]);
  printf("\n");
}

int main()
{
  int vetor[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(vetor) / sizeof(vetor[0]);
  ordenacaoBolha(vetor, n);
  printf("Vetor ordenado: \n");
  imprimirVetor(vetor, n);
  return 0;
}
