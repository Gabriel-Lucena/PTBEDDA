#include <stdio.h>

void intercalar(int vetor[], int esquerda, int meio, int direita)
{
  int i, j, k;
  int n1 = meio - esquerda + 1;
  int n2 = direita - meio;

  // Cria arrays temporários
  int L[n1], R[n2];

  // Copia dados para arrays temporários L[] e R[]
  for (i = 0; i < n1; i++)
    L[i] = vetor[esquerda + i];
  for (j = 0; j < n2; j++)
    R[j] = vetor[meio + 1 + j];

  // Intercala os arrays temporários de volta no vetor[esquerda..direita]
  i = 0;        // Índice inicial do primeiro subarray
  j = 0;        // Índice inicial do segundo subarray
  k = esquerda; // Índice inicial do subarray intercalado
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      vetor[k] = L[i];
      i++;
    }
    else
    {
      vetor[k] = R[j];
      j++;
    }
    k++;
  }

  // Copia os elementos restantes de L[], se houver
  while (i < n1)
  {
    vetor[k] = L[i];
    i++;
    k++;
  }

  // Copia os elementos restantes de R[], se houver
  while (j < n2)
  {
    vetor[k] = R[j];
    j++;
    k++;
  }
}

void ordenacaoIntercalacao(int vetor[], int esquerda, int direita)
{
  if (esquerda < direita)
  {
    int meio = esquerda + (direita - esquerda) / 2;

    // Ordena a primeira e a segunda metade
    ordenacaoIntercalacao(vetor, esquerda, meio);
    ordenacaoIntercalacao(vetor, meio + 1, direita);

    intercalar(vetor, esquerda, meio, direita);
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
  int vetor[] = {12, 11, 13, 5, 6, 7};
  int n = sizeof(vetor) / sizeof(vetor[0]);
  ordenacaoIntercalacao(vetor, 0, n - 1);
  printf("Vetor ordenado: \n");
  imprimirVetor(vetor, n);
  return 0;
}
