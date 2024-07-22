#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista simplesmente encadeada
typedef struct Node
{
  int data;
  struct Node *next;
} Node;

// Função para criar um novo nó
Node *createNode(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// (a) Inserir no início
void insertAtBeginning(Node **head, int data)
{
  Node *newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
}

// (b) Inserir no final
void insertAtEnd(Node **head, int data)
{
  Node *newNode = createNode(data);
  if (*head == NULL)
  {
    *head = newNode;
    return;
  }
  Node *current = *head;
  while (current->next != NULL)
  {
    current = current->next;
  }
  current->next = newNode;
}

// (c) Remover no início
void removeAtBeginning(Node **head)
{
  if (*head == NULL)
  {
    return;
  }
  Node *temp = *head;
  *head = (*head)->next;
  free(temp);
}

// (d) Remover no final
void removeAtEnd(Node **head)
{
  if (*head == NULL)
  {
    return;
  }
  if ((*head)->next == NULL)
  {
    free(*head);
    *head = NULL;
    return;
  }
  Node *current = *head;
  while (current->next->next != NULL)
  {
    current = current->next;
  }
  free(current->next);
  current->next = NULL;
}

// (e) Contar a quantidade de elementos da lista
int countElements(Node *head)
{
  int count = 0;
  Node *current = head;
  while (current != NULL)
  {
    count++;
    current = current->next;
  }
  return count;
}

// (f) Buscar um elemento da lista
Node *searchElement(Node *head, int data)
{
  Node *current = head;
  while (current != NULL)
  {
    if (current->data == data)
    {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

// (g) Exibir todos os elementos da lista
void displayList(Node *head)
{
  Node *current = head;
  while (current != NULL)
  {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

// Função para exibir o menu e obter a escolha do usuário
int displayMenu()
{
  int choice;
  printf("\nMenu:\n");
  printf("1. Inserir no início\n");
  printf("2. Inserir no final\n");
  printf("3. Remover no início\n");
  printf("4. Remover no final\n");
  printf("5. Contar elementos\n");
  printf("6. Buscar elemento\n");
  printf("7. Exibir lista\n");
  printf("8. Sair\n");
  printf("Escolha uma opção: ");
  scanf("%d", &choice);
  return choice;
}

int main()
{
  Node *head = NULL;
  int choice, data, value;

  while ((choice = displayMenu()) != 8)
  {
    switch (choice)
    {
    case 1:
      printf("Insira o valor para inserir no início: ");
      scanf("%d", &data);
      insertAtBeginning(&head, data);
      break;
    case 2:
      printf("Insira o valor para inserir no final: ");
      scanf("%d", &data);
      insertAtEnd(&head, data);
      break;
    case 3:
      removeAtBeginning(&head);
      printf("Elemento removido do início.\n");
      break;
    case 4:
      removeAtEnd(&head);
      printf("Elemento removido do final.\n");
      break;
    case 5:
      printf("Quantidade de elementos na lista: %d\n", countElements(head));
      break;
    case 6:
      printf("Insira o valor para buscar: ");
      scanf("%d", &value);
      if (searchElement(head, value) != NULL)
      {
        printf("Elemento %d encontrado na lista.\n", value);
      }
      else
      {
        printf("Elemento %d não encontrado na lista.\n", value);
      }
      break;
    case 7:
      printf("Elementos da lista: ");
      displayList(head);
      break;
    default:
      printf("Opção inválida! Tente novamente.\n");
    }
  }

  // Liberando a memória alocada
  while (head != NULL)
  {
    removeAtBeginning(&head);
  }

  printf("Programa encerrado.\n");
  return 0;
}
