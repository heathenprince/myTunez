typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;


//and later:

//song_node *table[26];

void print_list(song_node * n);
song_node * insert_front(song_node *n, char title[], char ar[]);
song_node * insert_order(song_node *n, char title[], char ar[]);
song_node * free_list(song_node * n);
