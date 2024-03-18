#include <stdio.h>

struct Hora
{
  int hora;
  int minuto;
  int segundo;
};

int main(void)
{
  int integer;
  int *integer_ponteiro;

  double real;
  double *real_ponteiro;

  char character;
  char *character_ponteiro;

  struct Hora hora;
  struct Hora *hora_ponteiro;

  double **real_ponteiro2;

  integer = 1;
  integer_ponteiro = &integer;

  real = 1;
  real_ponteiro = &real;

  character = 'a';
  character_ponteiro = &character;

  hora.hora = 1;
  hora.minuto = 1;
  hora.segundo = 1;
  hora_ponteiro = &hora;

  real_ponteiro = &real;
  real_ponteiro2 = &real_ponteiro;

  printf("Testando o ponteiro de int: \n");

  printf("Endereço da variável pela variável: %p\n", &integer);
  printf("Conteúdo da variável pelo ponteiro: %d\n\n", *integer_ponteiro);

  printf("Testando o ponteiro de double: \n");

  printf("Endereço da variável pela variável: %p\n", &real);
  printf("Conteúdo da variável pelo ponteiro: %lf\n\n", *real_ponteiro);

  printf("Testando o ponteiro de char: \n");

  printf("Endereço da variável pela variável: %p\n", &character);
  printf("Conteúdo da variável pelo ponteiro: %c\n\n", *character_ponteiro);

  printf("Testando o ponteiro de struct Hora: \n");

  printf("Endereço da variável pela variável: %p\n", &hora);
  printf("Endereço da variável pelo ponteiro: %p\n\n", *hora_ponteiro);

  printf("Testando o ponteiro de double *: \n");

  printf("Endereço do primeiro double: %p\n", &real);
  printf("Conteúdo do ponteiro do primeiro double: %p\n", *real_ponteiro2);

  return 0;
}
