#include <stdio.h>
#include <stdlib.h>

#include "list.h"


void print_list( struct node *n ) {

  printf("[ ");
  
  while(n) {
    printf("%d ", n->data );
    n = n->next;
  }
  printf("]\n");
}


struct node * insert_front( struct node *n, int  d ) {

  struct node *new = (struct node *)malloc(sizeof(struct node));

  new->next = n;
  new->data = d;

  return new;
}

struct node * free_list( struct node *n ) {

  struct node *f = n;
  while ( n ) {
    n = n->next;
    printf("freeing node: %d\n", f->data );
    free(f);
    f = n;    
  }
  return n;
}
