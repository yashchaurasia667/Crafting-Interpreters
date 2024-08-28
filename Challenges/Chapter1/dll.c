#include <stdlib.h>
#include <stdio.h>

struct Node{
  int value;
  struct Node *next;
  struct Node *prev
};
typedef struct Node node_t;

void printList(node_t *head) {
  node_t *tmp = head;
  while (tmp != NULL)
  {
    printf("%d - ", tmp->value);
    tmp = (*tmp).next;
  }
  printf("\n");
}

int main() {
  node_t n1, n2, n3;
  node_t *head;

  n1.value = 11;
  n2.value = 12;
  n3.value = 13;

  head = &n1;
  n1.next = &n2;
  n2.next = &n3;
  n3.next = NULL;

  printList(head);

  return 0;
}