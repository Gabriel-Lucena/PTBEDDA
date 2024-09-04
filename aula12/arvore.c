#include <stdio.h>
#include <stdlib.h>

struct Noh
{
  int dado;
  struct Noh *esquerda;
  struct Noh *direita;
};

// 1. Uma função para cada tipo de percurso : pré ordem, em ordem e pós ordem.

void preOrdem(struct Noh *raiz)
{
  if (raiz != NULL)
  {
    printf("%d ", raiz->dado);
    preOrdem(raiz->esquerda);
    preOrdem(raiz->direita);
  }
}

void emOrdem(struct Noh *raiz)
{
  if (raiz != NULL)
  {
    emOrdem(raiz->esquerda);
    printf("%d ", raiz->dado);
    emOrdem(raiz->direita);
  }
}

void posOrdem(struct Noh *raiz)
{
  if (raiz != NULL)
  {
    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    printf("%d ", raiz->dado);
  }
}

// 2. Escreva uma função que conte o número de nós de uma árvore binária.

int contarNos(struct Noh *raiz)
{
  if (raiz == NULL)
  {
    return 0;
  }
  else
  {
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
  }
}

// 3. Escreva uma função para achar o MAIOR valor em uma árvore binária não ordenada.

int encontrarMaior(struct Noh *raiz)
{
  if (raiz == NULL)
  {
    return -2147483648; // Retorna o menor valor possível para int em caso de árvore vazia.
  }

  int max_esquerda = encontrarMaior(raiz->esquerda);
  int max_direita = encontrarMaior(raiz->direita);
  int max_atual = raiz->dado;

  if (max_esquerda > max_atual)
  {
    max_atual = max_esquerda;
  }
  if (max_direita > max_atual)
  {
    max_atual = max_direita;
  }

  return max_atual;
}

// 4. Escreva uma função que conte o número de folhas de uma árvore binária.

int contarFolhas(struct Noh *raiz)
{
  if (raiz == NULL)
  {
    return 0;
  }
  if (raiz->esquerda == NULL && raiz->direita == NULL)
  {
    return 1;
  }
  return contarFolhas(raiz->esquerda) + contarFolhas(raiz->direita);
}

// Função para Criar um Novo Nó

struct Noh *novoNoh(int dado)
{
  struct Noh *novo = (struct Noh *)malloc(sizeof(struct Noh));
  novo->dado = dado;
  novo->esquerda = NULL;
  novo->direita = NULL;
  return novo;
}

int main()
{
  struct Noh *raiz = novoNoh(10);
  raiz->esquerda = novoNoh(5);
  raiz->direita = novoNoh(20);
  raiz->esquerda->esquerda = novoNoh(3);
  raiz->esquerda->direita = novoNoh(7);
  raiz->direita->direita = novoNoh(25);

  printf("Pre-Ordem: ");
  preOrdem(raiz);
  printf("\n");

  printf("Em-Ordem: ");
  emOrdem(raiz);
  printf("\n");

  printf("Pos-Ordem: ");
  posOrdem(raiz);
  printf("\n");

  printf("Número de nós: %d\n", contarNos(raiz));
  printf("Maior valor: %d\n", encontrarMaior(raiz));
  printf("Número de folhas: %d\n", contarFolhas(raiz));

  return 0;
}
