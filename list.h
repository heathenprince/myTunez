
struct node {
  int data;
  struct node *next;
};


void print_list( struct node * );
struct node * insert_front( struct node *n, int  d );
struct node * free_list( struct node *n );
