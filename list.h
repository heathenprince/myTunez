#ifndef LIST_H
#define LIST_H

struct song_node {
  char name[256];
  char artist[256];
  struct song_node* next;
};

typedef struct song_node node;

node* insert_front( node* next , char title[] , char artist[] );
node* insert_order( node* first , char title[] , char artist[] ); //alphabetically
void print_list( node* first );
node* find_song( node* first, char song[] );
node* find_artist( node* first, char artist[] );
node* find_random( node* first );
node* remove_item( node* first, char title[] );
void delete_LL( node* first );

//helper
int list_length( node* first );

#endif
