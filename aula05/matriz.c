#include <stdio.h>
#include <stdlib.h>

int main()
{
  int M, N;

  printf("Digite o número de linhas (M): ");
  scanf("%d", &M);
  printf("Digite o número de colunas (N): ");
  scanf("%d", &N);

  int **A = (int **)calloc(M, sizeof(int *));
  if (A == NULL)
  {
    printf("Erro ao alocar memória para A.\n");
    return 1;
  }

  for (int i = 0; i < M; i++)
  {
    A[i] = (int *)calloc(N, sizeof(int));
    if (A[i] == NULL)
    {
      printf("Erro ao alocar memória para A[%d].\n", i);
      return 1;
    }
  }

  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < N; j++)
    {
      printf("Digite o valor para A[%d][%d]: ", i, j);
      scanf("%d", &A[i][j]);
    }
  }

  printf("\nMatriz A:\n");
  for (int i = 0; i < M; i++)
  {
    for (int j = 0; j < N; j++)
    {
      printf("%d\t", A[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < M; i++)
  {
    free(A[i]);
  }
  free(A);

  return 0;
}
