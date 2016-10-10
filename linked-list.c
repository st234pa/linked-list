#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next; };

void print_list( struct node *head ) {
  struct node* temp = head;
  while (temp->next) {
    printf("%d -> ", temp->i);
    temp = temp->next;
  }
  printf("%d\n", temp->i);
}

struct node* insert_front( struct node* head, int d ) {
  struct node* newNode = (struct node *)malloc(sizeof(struct node));
  newNode->i = d;
  newNode->next = head;
  return newNode;
}

struct node* free_list( struct node *head ) {
  if (head->next) 
    free_list(head->next);
  free(head);
  return head;
}

int main() {

  struct node* list = (struct node *)malloc(sizeof(struct node));
  list->i = 5;
  list->next = 0;
  
  int x = 4;
  while (x) {
    list = insert_front(list,x);
    x--;
  }
  print_list(list);
  free_list(list);
  return 0;
  
}
