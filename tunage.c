#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
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
  while( list && !strcmp(list->artist,artist) ) { //while artists match
    printf( "Song: %s -- Artist: %s\n" , list->name, list->artist );
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
  int ctr = 0;
  int i;
  node* song;
  while( ctr < 10 ){
    i = rand() % 26;
    if( table[i] ) {
      song = find_random( table[i] );
      printf( "Song: %s -- Artist: %s\n" , song->name, song->artist );
      ctr++;
    }
  }
  /*


    song = find_random( table[i] );
    printf("%d\n",i);
    //printf( "Song: %s -- Artist: %s\n" , song->name, song->artist );
  }*/
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
  return NULL;
}

node* delete_song( node* table[], char title[] ) {
  int i;
  node* first;
  for( i = 0; i < 26; i++ ) {
    if( find_song( table[i] , title ) ) {
      first = table[i];
      break;
    }
  }
  node* kill = remove_item( first, title );
  return kill;
}

void delete_list( node* table[] ) {
  int i;
  for ( i = 0; i < 26; i++ ) {
    free_list(table[i]);
  }
  table = NULL;
}

//helper
node* whichList( node* table[], char c ) { //returns first node of appropriate list
  node *list = table[(int)tolower(c) - 97]; //conv from ASCII
  return list;
}
