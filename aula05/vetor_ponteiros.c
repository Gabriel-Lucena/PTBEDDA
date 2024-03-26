#include <stdio.h>
#include <stdlib.h>

int main()
{
  int M = 5;
  int **A;
  A = (int **)calloc(M, sizeof(int *));

  for (int i = 0; i < M; i++)
  {
    printf("Endereço de A[%d]: %p\n", i, (void *)&A[i]);
  }

  for (int i = 0; i < M; i++)
  {
    free(A[i]);
  }
  free(A);

  return 0;
}