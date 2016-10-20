#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"


void print_list( struct node *n ) {
  printf("[ ");
  while(n) {
    printf("%s-%s ", n->artist, n->name );
    n = n->next;
  }
  printf("]\n");
}


struct node * insert_front( struct node *n, char[] *title, char[] *ar ) {

  struct node *new = (struct node *)malloc(sizeof(struct node));

  new->name = title;
  new->artist = ar;
  new->next = n;

  return new;
}

struct node * insert_order( struct node *n, char[] *title, char[] *ar ) {
  
  struct node *new = (struct node *)malloc(sizeof(struct node));

  new->name = title; //new's name
  new->artist = ar; //new's artist
  //new->next = n; 

  //head is empty
  struct node *head = (struct node *)malloc(sizeof(struct node));
  head = n;
  curr = n; //1 (curr = current)
  ncurr = n->next; //2 (ncurr = next current)

  while (curr && ncurr){
    if (strcmp(title, curr->title) > 0){
      head = new;
      head->next = curr;
      return head; 
    }
    
    //compare w 2
    if (strcmp(title, ncurr->title) > 0){
      head = new;
      curr->next = head; 
      head->next = curr;
      return head; 
    }
    
    head = ncurr; //head = 0
    curr = curr->next; //curr = 1
    ncurr = curr->next; //ncurr = 2
  }

  if (curr){ //odd # of songs to compare
    if (strcmp(title, curr->title) > 0){ //insert after where u left off (ncurr)
      head = new;
      head->next = curr;
      return head; 
    }
    else{
      curr->next = new;
      return new;
    }
  }



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
