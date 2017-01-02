#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list.h"
#include "tunage.h"

void insert( node* table[], char title[], char artist[] ) {
  char letter = artist[0]; // first letter of artist name
  node* list = whichList( table, letter );
  table[(int)tolower(letter) - 97] = insert_order( list, title, artist ); //insert_order returns first node in list
}

void print_letter( node* table[], char c ) {
  print_list( whichList( table, c ) );
}

void print_artist( node* table[], char artist[] ) {
  node* list = search_artist( table, artist ); //returns first node where artist appears
  while( !strcmp(list->artist,artist) ) { //while artists match
    printf( "Song: %s -- Artist: %s\n" , list->title, list->artist );
    list = list->next;
  }
}

void print_library( node* table[] ) {
  int i;
  for( i = 0; i < 26; i++ ) {
    printf( "%c:=========\n",toupper(i + 97) );
    print_list(table[i]);
  }
}

void shuffle( node* table[] ) {
  srand(time(NULL));
  int i = rand() % 26;
  int ctr;
  for( ctr = 0; ctr < 10; ctr++ ) {
    while( !table[i] ) {
      int i = rand() % 26; //keep shuffling if empty list
    }
    node* song = find_random( table[i] );
    printf( "Song: %s -- Artist: %s\n" , song->title, song->artist );
  }
}

node* search_artist( node* table[], char artist[] ) {
  node* list = whichList( table, artist[0] );
  return find_artist( list, artist );
}

node* search_song( node* table[], char title[] ) {
  int i;
  node* found;
  for( i = 0; i < 26; i++ ) {
    found = find_song( table[i], title );
    if( found ) {
      return found;
    }
  }
}

node* delete_song( node* table[], char title[] ) {

}



//helper
node* whichList( node* table[], char c ) { //returns first node of appropriate list
  node *list = table[(int)tolower(c) - 97]; //conv from ASCII
  return list;
}
