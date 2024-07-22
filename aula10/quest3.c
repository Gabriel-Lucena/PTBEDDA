#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista duplamente encadeada
typedef struct Node
{
  int data;
  struct Node *prev;
  struct Node *next;
} Node;

// Função que busca um valor na lista duplamente encadeada
Node *search(Node *head, int value)
{
  Node *current = head; // Inicializa o ponteiro current com a cabeça da lista
  while (current != NULL)
  { // Percorre a lista até o final
    if (current->data == value)
    {
      return current; // Retorna o nó se o valor for encontrado
    }
    current = current->next; // Avança para o próximo nó
  }
  return NULL; // Retorna NULL se o valor não for encontrado
}

// Função auxiliar para criar um novo nó
Node *createNode(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

int main()
{
  // Criando uma lista duplamente encadeada de exemplo: 1 <-> 2 <-> 3 <-> 4
  Node *head = createNode(1);
  head->next = createNode(2);
  head->next->prev = head;
  head->next->next = createNode(3);
  head->next->next->prev = head->next;
  head->next->next->next = createNode(4);
  head->next->next->next->prev = head->next->next;

  // Buscando um valor na lista
  int valueToSearch = 3;
  Node *result = search(head, valueToSearch);

  if (result != NULL)
  {
    printf("Valor %d encontrado na lista.\n", valueToSearch);
  }
  else
  {
    printf("Valor %d não encontrado na lista.\n", valueToSearch);
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
