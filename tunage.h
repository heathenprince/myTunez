#include "list.h"

void insert( node* table[], char title[], char artist[] );
node* search_artist( node* table[], char artist[] );
node* search_song( node* table[], char title[] );
void print_letter( node* table[], char letter );
void print_artist( node* table[], char artist[] );
void print_library( node* table[] );
void shuffle( node* table[] );
node* delete_song( node* table[], char title[] );

//helper
node* whichList( node* table[], char c );
