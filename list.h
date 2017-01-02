typedef struct node {
  char name[256];
  char artist[256];
  struct node* next;
} node;

node* insert_front( node* next , char title[] , char artist[] );
node* insert_order( node* first , char title[] , char artist[] ); //alphabetically
void print_list( node* first );
node* find_song( char song[] );
node* find_artist( char artist[] );
node* find_random( node* first );
node* remove( int i ); //remove ith node
void free();

//helper
int list_length( node* first );
