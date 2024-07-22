#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista encadeada
typedef struct Node
{
  int data;
  struct Node *next;
} Node;

// Função que verifica se a lista está em ordem crescente
int isAscending(Node *head)
{
  // Se a lista estiver vazia ou contiver um único elemento, está em ordem crescente
  if (head == NULL || head->next == NULL)
  {
    return 1; // Verdadeiro
  }

  // Percorre a lista comparando os valores dos nós consecutivos
  Node *current = head;
  while (current->next != NULL)
  {
    if (current->data > current->next->data)
    {
      return 0; // Falso
    }
    current = current->next;
  }
  return 1; // Verdadeiro
}

// Função auxiliar para criar um novo nó
Node *createNode(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

int main()
{
  // Criando uma lista encadeada de exemplo: 1 -> 2 -> 3 -> 4
  Node *head = createNode(1);
  head->next = createNode(2);
  head->next->next = createNode(3);
  head->next->next->next = createNode(4);

  // Verificando se a lista está em ordem crescente
  if (isAscending(head))
  {
    printf("A lista está em ordem crescente.\n");
  }
  else
  {
    printf("A lista não está em ordem crescente.\n");
  }

  // Liberando a memória alocada
  Node *temp;
  while (head != NULL)
  {
    temp = head;
    head = head->next;
    free(temp);
  }

  return 0;
}
