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

  song_node *head = n;

  song_node *new = (song_node *)malloc(sizeof(song_node));
  strcpy(new->name,title); //new's name
  strcpy(new->artist,ar); //new's artist

  //if it's ordered to be first 
  if (strcmp(title, n->name) < 0){
      new->next = n;
      return new; 
    }
  else{
    printf("%s \n", n->name);
    n = n->next;
    while (n){
      //n = n->next; //new current position
      if (strcmp(title, (n->next)->name) < 0){ //check next name if greater
	printf("%s \n", n->name);
        n-> next = new;
	printf("%s \n", n->next->name);
        new->next = n->next;
	printf("%s \n", new->next->name);
	printf("%s \n", n->name);
        return head;
      }
      n = n->next; //new current position
    }
    
    n->next = new;
    return head;


  }

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
  strcpy(n2->artist,"c");
  strcpy(n3->artist,"p");

  strcpy(n1->name,"ayy");
  strcpy(n2->name,"bae");
  strcpy(n3->name,"day");
  
  //print_list(head);

  /*
  song_node *n4 = (song_node *)malloc(sizeof(song_node));
  strcpy(n4->artist,"h");
  strcpy(n4->name,"aaaa");
  */

  //head = insert_front(head, "aaaa","h");
  //print_list(head);
  head = insert_order(head, "ccc","h");
  //print_list(head);
  


  return 0;
}







