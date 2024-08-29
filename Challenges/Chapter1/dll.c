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
    // printf("%p - ", tmp->prev);
    // printf("%p - ", tmp->next);
    // printf("\n");
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
  if (!position)
  {
    insertion->next = head;
    head->prev = insertion;
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

node_t *deleteNode(int position, node_t *head)
{
  // removing head node
  if (position == 1)
    return head->next;

  node_t *tmp = head->next;
  int counter = 2;

  while (counter < position)
  {
    counter++;
    if (tmp->next == NULL)
      break;
    tmp = tmp->next;
  }

  if (tmp->next != NULL)
  {
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
  }
  else if (counter == position)
    tmp->prev->next = NULL;

  return head;
}

int main()
{
  node_t *head;
  node_t *n1 = newNode(9);

  head = n1;
  node_t *tmp = head;
  for (int i = 0; i < 5; i++)
  {
    node_t *nNode = newNode(i + 10);
    tmp->next = nNode;
    nNode->prev = tmp;
    tmp = tmp->next;

    // printf("%d - ", tmp->value);
  }

  // add a node at head
  head = addNode(8, 0, head);
  printList(head);
  // add a node at the end
  head = addNode(15, 7, head);
  printList(head);
  // deleting the head node
  head = deleteNode(1, head);
  printList(head);
  // deleting a middle node
  head = deleteNode(5, head);
  printList(head);
  // deleting the last node
  head = deleteNode(7, head);
  printList(head);

  return 0;
}