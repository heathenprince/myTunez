#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"


void print_list(song_node *n ) {
  while(n) {
    printf("%s-%s ", n->artist, n->name );
    n = n->next;
  }
  printf("\n");
}


song_node * insert_front(song_node *n, char title[], char ar[]){

  song_node *new = (song_node *)malloc(sizeof(song_node));

  new->next = n;
  strcpy(new->name,title);
  strcpy(new->artist,ar);

  return new;
}


song_node * insert_order(song_node *n, char title[], char ar[]){
  
  song_node *new = (song_node *)malloc(sizeof(song_node));

  strcpy(new->name,title); //new's name
  strcpy(new->artist,ar); //new's artist
  //new->next = n; 

  //head is empty
  song_node *head = (song_node *)malloc(sizeof(song_node));
  song_node *first = (song_node *)malloc(sizeof(song_node));
  song_node *curr = (song_node *)malloc(sizeof(song_node));
  song_node *ncurr = (song_node *)malloc(sizeof(song_node));

  first = n;
  head = n;
  curr = n; //1 (curr = current)
  ncurr = n->next; //2 (ncurr = next current)

  while (curr && ncurr){
    if (strcmp(title, curr->name) > 0){
      head = new;
      head->next = curr;
      return head; 
    }
    
    //compare w 2
    if (strcmp(title, ncurr->name) > 0){
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
    if (strcmp(title, curr->name) > 0){ //insert after where u left off (ncurr)
      head = new;
      head->next = curr;
      return head; 
    }
    else{
      curr->next = new;
      return new;
    }
  }

return first;
}

/*
song_node * free_list(song_node * n){

  song_node *f = n;
  while ( n ) {
    n = n->next;
    printf("freeing node: %d\n", f->data );
    free(f);
    f = n;    
  }
  return n;
}
*/


//================================================================
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

  song_node *head;
  song_node *n1 = (song_node *)malloc(sizeof(song_node));
  song_node *n2 = (song_node *)malloc(sizeof(song_node));
  song_node *n3 = (song_node *)malloc(sizeof(song_node));
  head = n1;

  n1 -> next = n2;
  n2 -> next = n3;
  n3 -> next = NULL;

  strcpy(n1->artist,"h");
  strcpy(n2->artist,"h");
  strcpy(n3->artist,"h");

  strcpy(n1->name,"ayy");
  strcpy(n2->name,"bae");
  strcpy(n3->name,"day");
  
  print_list(head);

  /*
  song_node *n4 = (song_node *)malloc(sizeof(song_node));
  strcpy(n4->artist,"h");
  strcpy(n4->name,"aaaa");
  */

  head = insert_front(head, "aaaa","h");
  print_list(head);
  head = insert_order(head, "ccc","h");
  print_list(head);


  return 0;
}







