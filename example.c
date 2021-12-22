#include "list.h"
#include <stdio.h>
#include <stdbool.h>

int main() {
  
  struct node *head = list();

  int a = 0;
  int b = 1;
  int c = 2;
  int d = 3;
  float e = 43.123;
  double fd = 543.234332234;
  char re = 'a';

  append(&head, &a);
  append(&head, &b);
  append(&head, &d);
  append(&head, &c);
  append(&head, &e);
  append(&head, &re);
  append(&head, &fd);

  printf("Original List: "); 
  printList(&head);

  sort(&head);

  printf("List after sorting the data: ");
  printList(&head);

  reverse(&head);
  printf("nList after reversing the data: ");
  printList(&head);

  pop(&head);
  printf("nList after poping : ");
  printList(&head);

  pop(&head);
  printf("nList after del : ");
  printList(&head);

  return 0;
}
