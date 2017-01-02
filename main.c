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
  insert(table, "Jesus of Suburbia", "Green Day");
  insert(table, "Get Away", "Yuck");
  insert(table, "Brooklyn Baby", "Lana Del Rey");
  insert(table, "The World is Yours", "Nas");
  insert(table, "Realiti", "Grimes");
  insert(table, "Angeles", "Elliott Smith");
  insert(table, "Three Seed", "Silversun Pickups");
  insert(table, "Common Reactor", "Silversun Pickups");
  insert(table, "Lazy Eye", "Silversun Pickups");
  insert(table, "Kissing Families", "Silversun Pickups");
  insert(table, "Lost in My Bedroom", "Sky Ferreira");
  insert(table, "Celebrity Skin", "Hole");
  insert(table, "Violet", "Hole");
  insert(table, "Asking For It", "Hole");
  insert(table, "Swimming Pool", "The Front Bottoms");
  insert(table, "Sheena is a Punk Rocker", "The Ramones");
  insert(table, "Wave Goodbye", "Ty Segall Band");
  insert(table, "Last Resort", "Papa Roach"); //cut my life into peaches, they are a tasty snack

  printList(table);
  printf("\nTESTING SEARCH AND PRINT\n");
  printf("Searching for 'Silversun Pickups': ");
  search_artist(table, "Silversun Pickups");
  print_artist(table,"Silversun Pickups");
  printf("\nSearching for 'Hole': ");
  search_artist(table, "Hole");
  print_artist(table,"Hole");
  printf("\nSearching for 'Swimming Pool': ");
  search_song(table, "Swimming Pool");
  printf("\nSearching for 'Realiti': ");
  search_song(table, "Realiti");

  //=====TESTING SHUFFLE=====
  shuffle(table);

  printf("\nTESTING DELETE of 'Angeles':\n");
  delete_song(table,"Angeles");
  print_list(table);
  delete_list(table);
  return 0;
}
