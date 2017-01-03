#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "list.h"

//=================INSERT FUNCTIONS=================
node* insert_front( node* first, char title[], char artist[] ) {
  node* newNode;
  newNode = malloc(sizeof(node));
  newNode->next = first;
  strcpy( newNode->name, title );
  strcpy( newNode->artist, artist );
  return newNode;
}

node* insert_order( node* first, char title[], char artist[] ) { //inserts alphabetically by artist

  if( !first ) { //if empty list
    return insert_front( first, title, artist );
  }

  //=================creating the new node
  node* newNode;
  newNode = malloc(sizeof(node));
  newNode->next = NULL;
  strcpy( newNode->name, title );
  strcpy( newNode->artist, artist );


  node* temp = first;
  //================alphabetizing by artist
  while( temp->next ) { //while temp node is not last node
    if( strcmp(temp->next->artist, newNode->artist) > 0 ) {
      newNode->next = temp->next;
      temp->next = newNode;
      return first; //returns beginning of list, b/c why not
    }
    temp = temp->next;
  }
  //================if temp/current node is last node...
  if(strcmp(newNode->artist, temp->artist) < 0) {
    newNode->next = temp; //newNode --> temp
    return newNode;
  }

  temp->next = newNode; //temp --> newNode
  return first;

}

//=================PRINT FUNCTIONS=================
void print_list(node* first) {
  if( !first ) { //if NULL
    printf( "\n" );
    return;
  }
  while( first ) { //while a next node exists
    printf( "Song: %s -- Artist: %s\n" , first->name, first->artist );
    first = first->next;
  }
}

//=================SEARCH FUNCTIONS=================
node* find_song( node* first, char target[] ) { //search for a song within a single linkedlist
  while( first ) { // while current node isn't NULL
    if( !strcmp(first->name, target) ) {
      return first;
    }
    first = first->next;
  }
  return NULL;
}

node* find_artist( node* first, char target[] ) {
  while( first ) { // while current node isn't NULL
    if( !strcmp(first->artist, target) ) {
      return first;
    }
    first = first->next;
  }
  return NULL;
}

node* find_random( node* first ) {
  //srand(time(NULL)); //initialize rand num generator
  int i = rand() % list_length(first); //mod rand num by list length to get num in range [0,len)

	for (i; i; i--) {// iterate to ith element in linkedlist
    first = first->next;
  }
	return first;
}

//=================REMOVE/DELETE FUNCTIONS=================
node* remove_item( node* first, char title[] ) {
  node* ret;
  while( first->next ) {
    if( !strcmp(first->next->name,title) ) {
      node* kill = first->next;
      ret = kill;
      first->next = first->next->next;
      free(kill);
      return ret;
    }
    first = first->next;
  }
  return NULL;
}

node* free_list( node* first ) {
  node* temp = first;
  while( first ) {
    temp = first->next;
    free(first);
    first = temp;
  }
  first = NULL;
  return first;
}

//=================HELPER FUNCTIONS=================
int list_length( node* first ) {
  int len = 0;
  while( first ) {
    first = first->next;
    len++;
  }
  return len;
}
