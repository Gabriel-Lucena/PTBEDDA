#include <stdio.h>

// Função para trocar dois elementos
void trocar(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

// Seleção
// O algoritmo de seleção (Selection Sort) funciona selecionando repetidamente o menor
// (ou maior, dependendo da ordem desejada) elemento do array e colocando-o
// na posição correta.
void selectionSort(int vetor[], int n)
{
  int i, j, min_idx;
  for (i = 0; i < n - 1; i++)
  {
    min_idx = i;
    for (j = i + 1; j < n; j++)
      if (vetor[j] < vetor[min_idx])
        min_idx = j;
    trocar(&vetor[min_idx], &vetor[i]);
  }
}

// Bolha
// O algoritmo de bolha (Bubble Sort) funciona repetidamente passando pela lista a ser ordenada,
// comparando cada par adjacente de itens e trocando-os se estiverem na ordem errada.

void bubbleSort(int vetor[], int n)
{
  int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++)
      if (vetor[j] > vetor[j + 1])
        trocar(&vetor[j], &vetor[j + 1]);
}

// Intercalação
// O algoritmo de intercalação divide a lista em sublistas menores até que cada sublista
// contenha apenas um elemento e depois mescla as sublistas de maneira ordenada.
void merge(int vetor[], int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1], R[n2];
  for (i = 0; i < n1; i++)
    L[i] = vetor[l + i];
  for (j = 0; j < n2; j++)
    R[j] = vetor[m + 1 + j];
  i = 0;
  j = 0;
  k = l;
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
  while (i < n1)
  {
    vetor[k] = L[i];
    i++;
    k++;
  }
  while (j < n2)
  {
    vetor[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int vetor[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;
    mergeSort(vetor, l, m);
    mergeSort(vetor, m + 1, r);
    merge(vetor, l, m, r);
  }
}

// Quick Sort
// O algoritmo Quick Sort seleciona um pivô e divide a lista de modo que todos os elementos
// menores que o pivô fiquem à esquerda e os maiores fiquem à direita, repetindo o processo
// recursivamente para as sublistas.
int particionar(int vetor[], int baixo, int alto)
{
  int pivo = vetor[alto];
  int i = (baixo - 1);
  for (int j = baixo; j <= alto - 1; j++)
  {
    if (vetor[j] < pivo)
    {
      i++;
      trocar(&vetor[i], &vetor[j]);
    }
  }
  trocar(&vetor[i + 1], &vetor[alto]);
  return (i + 1);
}

void quickSort(int vetor[], int baixo, int alto)
{
  if (baixo < alto)
  {
    int pi = particionar(vetor, baixo, alto);
    quickSort(vetor, baixo, pi - 1);
    quickSort(vetor, pi + 1, alto);
  }
}

// HEAP SORT
// O Heap Sort é um algoritmo que usa uma estrutura de dados chamada heap.
// Ele transforma o array em um heap, depois remove repetidamente o maior elemento do heap e
// o coloca no final do array.
void heapify(int vetor[], int n, int i)
{
  int maior = i;
  int esquerda = 2 * i + 1;
  int direita = 2 * i + 2;
  if (esquerda < n && vetor[esquerda] > vetor[maior])
    maior = esquerda;
  if (direita < n && vetor[direita] > vetor[maior])
    maior = direita;
  if (maior != i)
  {
    trocar(&vetor[i], &vetor[maior]);
    heapify(vetor, n, maior);
  }
}

void heapSort(int vetor[], int n)
{
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(vetor, n, i);
  for (int i = n - 1; i > 0; i--)
  {
    trocar(&vetor[0], &vetor[i]);
    heapify(vetor, i, 0);
  }
}

// Função para imprimir o vetor
void imprimirVetor(int vetor[], int tamanho)
{
  for (int i = 0; i < tamanho; i++)
    printf("%d ", vetor[i]);
  printf("\n");
}

int main()
{
  int vetor1[] = {64, 25, 12, 22, 11};
  int vetor2[] = {64, 25, 12, 22, 11};
  int vetor3[] = {64, 25, 12, 22, 11};
  int vetor4[] = {64, 25, 12, 22, 11};
  int vetor5[] = {64, 25, 12, 22, 11};
  int n = sizeof(vetor1) / sizeof(vetor1[0]);

  printf("Vetor fornecido: \n");
  imprimirVetor(vetor1, n);

  selectionSort(vetor1, n);
  printf("\nVetor ordenado por Selection Sort: \n");
  imprimirVetor(vetor1, n);

  bubbleSort(vetor2, n);
  printf("\nVetor ordenado por Bubble Sort: \n");
  imprimirVetor(vetor2, n);

  mergeSort(vetor3, 0, n - 1);
  printf("\nVetor ordenado por Merge Sort: \n");
  imprimirVetor(vetor3, n);

  quickSort(vetor4, 0, n - 1);
  printf("\nVetor ordenado por Quick Sort: \n");
  imprimirVetor(vetor4, n);

  heapSort(vetor5, n);
  printf("\nVetor ordenado por Heap Sort: \n");
  imprimirVetor(vetor5, n);

  return 0;
}
