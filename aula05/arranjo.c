#include <stdlib.h>
#include <stdio.h>

struct Hora
{
  int hora;
  int minuto;
  int segundo;
};

int main()
{
  struct Hora *H;
  int M = 3;

  H = (struct Hora *)calloc(M, sizeof(struct Hora));

  if (H == NULL)
  {
    printf("Memory allocation failed\n");
    return 1;
  }

  (H + 1)->minuto = 23;

  int a = H[1].minuto;
  int b = (H + 1)->minuto;

  if (a == b)
  {
    printf("%d\n", H[1].minuto);
    printf("%d\n", (H + 1)->minuto);
    printf("Iguais!\n");
  }

  free(H);

  return 0;
}
