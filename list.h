typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

song_node * insert_front(song_node *n, char title[], char ar[]);
song_node * insert_order(song_node *n, char title[], char ar[]);
void print_list(song_node * n);
song_node * find_song(song_node *n, char title[]);
song_node * artist_first_song(song_node *n, char ar[]);
song_node * rand_node(song_node *n);
song_node * remove_node(song_node *n, char title[], char ar[]);
song_node * free_list(song_node * n);