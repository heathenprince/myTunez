#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


int main() {

  /*
  struct node *list = 0;

  print_list( list );

  int i;
  for (i=0; i < 10; i++)
    list = insert_front( list, i);

  print_list( list );

  list = free_list( list );

  print_list( list );

  */

  struct node *head;
  struct node *n1 = (struct node *)malloc(sizeof(struct node));
  struct node *n2 = (struct node *)malloc(sizeof(struct node));
  struct node *n3 = (struct node *)malloc(sizeof(struct node));
  head = n1;

  n1 -> i = "ayy";
  n2 -> i = "baee";
  n3 -> i = "dayy";

  n1 -> next = n2;
  n2 -> next = n3;
  n3 -> next = NULL;
 	
  print_list(head)



  return 0;
}
