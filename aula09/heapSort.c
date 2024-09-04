#include <stdio.h>

// Função para trocar dois elementos
void trocar(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

// Para criar um heap máximo
void heapify(int vetor[], int n, int i)
{
  int maior = i;            // Inicializa o maior como raiz
  int esquerda = 2 * i + 1; // filho à esquerda
  int direita = 2 * i + 2;  // filho à direita

  // Se o filho à esquerda é maior que a raiz
  if (esquerda < n && vetor[esquerda] > vetor[maior])
    maior = esquerda;

  // Se o filho à direita é maior que o maior até agora
  if (direita < n && vetor[direita] > vetor[maior])
    maior = direita;

  // Se o maior não é a raiz
  if (maior != i)
  {
    trocar(&vetor[i], &vetor[maior]);

    // Recursivamente heapify a subárvore afetada
    heapify(vetor, n, maior);
  }
}

// Função principal para fazer a ordenação por heap
void heapSort(int vetor[], int n)
{
  // Construir o heap (rearranjar o array)
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(vetor, n, i);

  // Um por um extrair um elemento do heap
  for (int i = n - 1; i >= 0; i--)
  {
    // Move a raiz atual para o final
    trocar(&vetor[0], &vetor[i]);

    // Chama heapify no heap reduzido
    heapify(vetor, i, 0);
  }
}

// Função para imprimir o array
void imprimirVetor(int vetor[], int tamanho)
{
  for (int i = 0; i < tamanho; i++)
    printf("%d ", vetor[i]);
  printf("\n");
}

int main()
{
  int vetor[] = {12, 11, 13, 5, 6, 7};
  int n = sizeof(vetor) / sizeof(vetor[0]);

  printf("Vetor fornecido: \n");
  imprimirVetor(vetor, n);

  heapSort(vetor, n);

  printf("Vetor ordenado por Heap Sort: \n");
  imprimirVetor(vetor, n);
  return 0;
}
