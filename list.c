#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list.h"

song_node * insert_front(song_node *n, char title[], char ar[]){
  song_node *new = (song_node *)malloc(sizeof(song_node));
  new->next = n;
  strcpy(new->name,title);
  strcpy(new->artist,ar);
  return new;
}
//======================================================================================
song_node * insert_order(song_node *n, char title[], char ar[]){
  if (!n || strcmp(ar, n->artist) < 0) //if artist is diff and song is smaller
    return insert_front(n,title,ar);
  if (strcmp(ar, n->artist) == 0 && strcmp(n, n->name) < 0) //same artist, song is smaller
    return insert_front(n,title,ar);
  n->next = insert_order(n->next,title,ar); //redo, current node moves up one
  return n;
}
//======================================================================================
void print_list(song_node *n) {
  while(n) {
    printf("%s-%s ", n->artist, n->name);
    n = n->next;
  }
  printf("\n");
}
//======================================================================================
song_node * find_song(song_node *n, char title[]){
  while (n) {
    if (!strcmp(n->name, title)) {
      return n;
    }
    n = n->next;
  }
  return 0;
}
//======================================================================================
song_node * artist_first_song(song_node *n, char ar[]){
  while (n) {
    if (!strcmp(n->artist, ar)) {
      return n;
    }
    n = n->next;
  }
  return 0;
}
/*
//======================================================================================
song_node * rand_node(song_node *n){
  int r = rand() % length(n);
  while (r) {
  	r--;
    n = n->next;
  }
  return n;
}
*/
//======================================================================================
song_node * remove_node(song_node *n, char title[], char ar[]){
	song_node *cur = n;
 	song_node *prev = 0;
  	song_node *sn = find_song(n, title);
  	if (!sn) //if node doesnt exist
    	return n;
    if (cur == sn) { //first test
    	n = n->next;
    	free(cur);
    	return n;
  	}
  	while(cur != sn && cur->next) {
    	prev = cur;
    	cur = cur->next;
  	}
  	prev->next = cur->next; //remove sn
  	free(cur);
  	return n;
}
//======================================================================================
song_node * free_list(song_node * n){
  song_node *f = n;
  while (n) {
    n = n->next;
    printf("freeing node: %s %s %s \n", f->artist, "-", f->name );
    free(f);
    f = n;    
  }
  return n;
}
//======================================================================================
/*
int main() {

  song_node *head;
  song_node *n1 = (song_node *)malloc(sizeof(song_node));
  song_node *n2 = (song_node *)malloc(sizeof(song_node));
  song_node *n3 = (song_node *)malloc(sizeof(song_node));
  head = n1;

  n1 -> next = n2;
  n2 -> next = n3;
  n3 -> next = NULL;

  strcpy(n1->artist,"x");
  strcpy(n2->artist,"y");
  strcpy(n3->artist,"z");

  strcpy(n1->name,"ayy");
  strcpy(n2->name,"bbb");
  strcpy(n3->name,"ddd");
  
  printf("\n");
  printf("Adding song: artist = %s, song = %s \n",n1->artist,n1->name);
  printf("Adding song: artist = %s, song = %s \n",n2->artist,n2->name);
  printf("Adding song: artist = %s, song = %s \n",n3->artist,n3->name);
  printf("\n");

  printf("PRINTING LIST: ");
  print_list(head);
  printf("\n");

  head = insert_front(head, "hi","w");
  printf("Adding song (using insert_front): artist = h, song = hi \n");
  printf("PRINTING LIST: ");
  print_list(head);
  printf("\n");

  head = insert_order(head, "ccc","y");
  printf("Adding song (using insert_order): artist = y, song = ccc \n");
  print_list(head);
  printf("\n");

  printf("Finding song ccc: ");
  song_node *chosenSong = find_song(head,"ccc");
  print_list(chosenSong); //c-bae , etc. (proves that it found the song)
  printf("Finding song aaa: ");
  chosenSong = find_song(head,"aaa");
  print_list(chosenSong); // nothing prints out bc it does not exist  
  
  printf("Finding artist y: ");
  song_node *chosenArtist = artist_first_song(head,"y");
  print_list(chosenArtist); //c-bae , etc. (proves that it found the song)
  printf("Finding artist kk: ");
  chosenArtist = artist_first_song(head,"kk");
  print_list(chosenArtist); // nothing prints out bc it does not exist
  
  printf("Removing song ddd by z... \n");
  head = remove_node(head,"ddd","z");
  printf("PRINTING LIST: ");
  print_list(head);
  printf("\n");

  printf("Freeing the list... \n");
  head = free_list(head);
  printf("PRINTING LIST: ");
  print_list(head);
  printf("\n");
  printf("End of testing for list.c \n");
  printf("\n");

  return 0;
}


OUTPUT OF RUNNING AND TESTING CODE ==================================================

Adding song: artist = x, song = ayy 
Adding song: artist = y, song = bbb 
Adding song: artist = z, song = ddd 

PRINTING LIST: x-ayy y-bbb z-ddd 

Adding song (using insert_front): artist = h, song = hi 
PRINTING LIST: w-hi x-ayy y-bbb z-ddd 

Adding song (using insert_order): artist = y, song = ccc 
w-hi x-ayy y-bbb y-ccc z-ddd 

Finding song ccc: y-ccc z-ddd 
Finding song aaa: Requested song was not found. 

Finding artist y: y-bbb y-ccc z-ddd 
Finding artist kk: Requested artist was not found. 

Removing song ddd by z... 
PRINTING LIST: w-hi x-ayy y-bbb y-ccc 

Freeing the list... 
freeing node: w - hi 
freeing node: x - ayy 
freeing node: y - bbb 
freeing node: y - ccc 
PRINTING LIST: 

End of testing for list.c 
*/ 





