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
  insert(table, "Letterbomb", "Green Day");
  insert(table, "Get Away", "Yuck");
  insert(table, "Brooklyn Baby", "Lana Del Rey");
  insert(table, "REALiTi", "Grimes");
  insert(table, "Kill V. Maim", "Grimes");
  insert(table, "Tuscan Leather","Drake");
  insert(table, "Three Seed", "Silversun Pickups");
  insert(table, "Common Reactor", "Silversun Pickups");
  insert(table, "Lazy Eye", "Silversun Pickups");
  insert(table, "Kissing Families", "Silversun Pickups");
  insert(table, "Lost in My Bedroom", "Sky Ferreira");
  insert(table, "Celebrity Skin", "Hole");
  insert(table, "Violet", "Hole");
  insert(table, "Asking For It", "Hole");
  insert(table, "Your Graduation","Modern Baseball");
  insert(table, "Paralytic States","Against Me!");
  insert(table, "Shirtsleeves","Ed Sheeran");
  insert(table, "What's My Age Again?","Blink-182");
  insert(table, "Nobody Puts Baby In The Corner", "Fall Out Boy");
  insert(table, "History Maker", "Dean Fujioka");
  insert(table, "Street Punk", "Hunx & His Punx");
  insert(table, "Bring Me To Life","Evanescence");

  print_library(table);
  printf("\nTESTING SEARCH AND PRINT\n");
  printf("Searching for 'Silversun Pickups':\n");
  search_artist(table, "Silversun Pickups");
  print_artist(table,"Silversun Pickups");

  printf("\nSearching for 'Hole':\n");
  search_artist(table, "Hole");
  print_artist(table,"Hole");

  printf("\nSearching for 'Bring Me To Life': ");
  search_song(table, "Bring Me To Life");
  printf("\nSearching for 'REALiTi': ");
  search_song(table, "REALiTi");

  //=====TESTING SHUFFLE=====
  printf("\nTESTING SHUFFLE\n");
  shuffle(table);

  //=====TESTING DELETE=====
  printf("\nTESTING DELETE of 'Letterbomb':\n");
  delete_song(table,"Letterbomb");
  print_library(table);
  //delete_list(table); //NOT WORKING
  delete_LL(table[0]);
  print_list(table[0]);
  printf("%d\n", table[0]==NULL);
  return 0;
}
