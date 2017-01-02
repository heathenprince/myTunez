#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "tunage.h"

int main() {

  node *table[26];
  int i;
  for(i = 0; i < 26; i++) {
    table[i] = NULL;
  }

  printf("TESTING ADD AND PRINT:\n");
  insert(table, "New york cares", "Interpol");
  insert(table, "The Distance", "CAKE");
  insert(table, "Look At Me", "Buddy Holly");
  insert(table, "Mailman, Bring Me No More Blues", "Buddy Holly");
  insert(table, "You're So Square", "Buddy Holly");
  insert(table, "Yesterday", "The Beatles");
  insert(table, "Black Bird", "The Beatles");
  insert(table, "Let it be", "The Beatles");
  printList(table);
  printf("\nTESTING SEARCH AND PRINT\n");
  printf("Searching for 'Buddy Holly': ");
  search_artist(table, "Buddy Holly");
  print_artist(table,"Buddy Holly");
  printf("\nSearching for 'Simon and Garfunkel': ");
  search_artist(table, "Simon and Garfukel");
  print_artist(table,"Simon and Garfunkel");
  printf("\nSearching for 'Let it be': ");
  search_song(table, "Let it be");
  printf("\nSearching for 'Whole Lotta Love': ");
  search_song(table, "Whole Lotta Love");

  //=====TESTING SHUFFLE=====
  shuffle(table);

  printf("\nTESTING DELETE of 'Black Bird':\n");
  delete_song(table,"Black Bird");
  print_list(table);
  delete_list(table);
  return 0;
}
