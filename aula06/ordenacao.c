#include <stdio.h>

void bubbleSort(int vetor[], int tamanho)
{
  int i, j, temp;
  for (i = 0; i < tamanho - 1; i++)
  {
    for (j = 0; j < tamanho - i - 1; j++)
    {
      if (vetor[j] > vetor[j + 1])
      {
        temp = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = temp;
      }
    }
  }
}

int binarySearch(int vetor[], int tamanho, int chave)
{
  int left = 0;
  int right = tamanho - 1;

  while (left <= right)
  {
    int mid = left + (right - left) / 2;

    // Se o elemento do meio é o alvo, retorna o índice do meio
    if (vetor[mid] == chave)
    {
      return mid;
    }

    // Se o alvo está na metade esquerda, atualiza o 'right'
    if (vetor[mid] > chave)
    {
      right = mid - 1;
    }
    // Se o alvo está na metade direita, atualiza o 'left'
    else
    {
      left = mid + 1;
    }
  }

  // Se o elemento não estiver no array, retorna -1
  return -1;
}

int main(void)
{

  int vetor[] = {40, 30, 15, 5, 100, 25, 65, 145};
  int tamanho = 8;

  printf("Vetor original:\n");
  for (int i = 0; i < tamanho; i++)
  {
    printf("%d ", vetor[i]);
  }
  printf("\n");

  bubbleSort(vetor, tamanho);

  printf("Vetor ordenado:\n");
  for (int i = 0; i < tamanho; i++)
  {
    printf("%d ", vetor[i]);
  }

  printf("\n\n");

  printf("%d\n", binarySearch(vetor, 8, 30));
  printf("%d", binarySearch(vetor, 8, 100));

  return 0;
}