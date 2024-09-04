#include <stdio.h>

void ordenacaoSelecao(int vetor[], int n)
{
  int i, j, indice_minimo;
  for (i = 0; i < n - 1; i++)
  {
    indice_minimo = i;
    for (j = i + 1; j < n; j++)
    {
      if (vetor[j] < vetor[indice_minimo])
      {
        indice_minimo = j;
      }
    }
    // Troca o menor elemento encontrado com o primeiro elemento
    int temp = vetor[indice_minimo];
    vetor[indice_minimo] = vetor[i];
    vetor[i] = temp;
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
  int vetor[] = {64, 25, 12, 22, 11};
  int n = sizeof(vetor) / sizeof(vetor[0]);
  ordenacaoSelecao(vetor, n);
  printf("Vetor ordenado: \n");
  imprimirVetor(vetor, n);
  return 0;
}
