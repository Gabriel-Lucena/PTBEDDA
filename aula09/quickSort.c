#include <stdio.h>

void trocar(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

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

void ordenacaoRapida(int vetor[], int baixo, int alto)
{
  if (baixo < alto)
  {
    int pi = particionar(vetor, baixo, alto);

    ordenacaoRapida(vetor, baixo, pi - 1);
    ordenacaoRapida(vetor, pi + 1, alto);
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
  int vetor[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(vetor) / sizeof(vetor[0]);
  ordenacaoRapida(vetor, 0, n - 1);
  printf("Vetor ordenado: \n");
  imprimirVetor(vetor, n);
  return 0;
}
