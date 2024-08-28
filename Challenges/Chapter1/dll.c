#include <stdlib.h>
#include <stdio.h>

struct Node
{
  int value;
  struct Node *prev;
  struct Node *next;
};
typedef struct Node node_t;

void printList(node_t *head)
{
  node_t *tmp = head;
  while (tmp != NULL)
  {
    printf("%d - ", tmp->value);
    tmp = (*tmp).next;
  }
  printf("\n");
}

node_t *newNode(int value)
{
  node_t *newNode = malloc(sizeof(node_t));
  newNode->value = value;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

node_t *addNode(int value, int position, node_t *head)
{
  node_t *tmp = head;
  node_t *insertion = newNode(value);

  // to insert at head
  if (position == 0)
  {
    insertion->next = head;
    return insertion;
  }

  // to insert a node at head
  for (int i = 1; i < position && tmp->next != NULL; i++)
    tmp = tmp->next;

  if (tmp->next != NULL)
  {
    insertion->next = tmp->next;
    tmp->next->prev = insertion;
    insertion->prev = tmp;
    tmp->next = insertion;
  }

  // insert a node at the end
  else
  {
    insertion->prev = tmp;
    tmp->next = insertion;
  }
  return head;
}

int main()
{
  node_t *head;

  node_t *n1 = newNode(11);
  node_t *n2 = newNode(12);
  node_t *n3 = newNode(13);

  head = n1;
  n1->next = n2;
  n2->next = n3;
  n3->next = NULL;

  printList(head);
  head = addNode(10, 0, head);
  head = addNode(14, 4, head);
  printList(head);

  return 0;
}