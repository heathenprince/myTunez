typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;


//and later:

song_node *table[26];

void print_list( struct node * );
struct node * insert_front( struct node *n, int  d );
struct node * free_list( struct node *n );
