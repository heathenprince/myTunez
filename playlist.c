#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"


int setIndex(char c) {
  if (c >= 65 && c <= 90) //A-Z
    return c - 65;
  else if (c >= 97 && c <= 122) //a-z
    return c - 97;
}
//======================================================================================
char getChar(int i) {
  return i+65;
}
//======================================================================================
void add_song(char title[],char ar[]){
	int i = setIndex(*ar);
	printf("Inserting %s-%s into playlist[%d]\n", ar, title, i);
	playlist[i] = insert_order(playlist[i], title, ar);
	print_list(playlist[i]);
}
//======================================================================================
song_node *find_playlist_song(char title[]){
	printf("Finding %s in playlist\n", title);
    int i;
    for (i = 0; i < 26; i++) {
        song_node *song = find_song(playlist[i],title);
        if (song) {
        	printf("Found %s-%s \n", song->artist, song->name);
            return song;
        }
    }
    printf("Could not find requested song. \n");
    return 0;
}
//======================================================================================
song_node *find_playlist_artist(char ar[]){
	
	//printf("Finding %s in playlist\n", ar);
    int i = setIndex(*ar);
    song_node *song = artist_first_song(playlist[i],ar);
    if (song) {
    	//printf("Found %s-%s \n", song->artist, song->name);
    	return song;
    }
    printf("Could not find requested artist. \n");
    return 0;
}
//======================================================================================
void print_entries(char ar[]){
	int i = setIndex(*ar);
	printf("%c Artists: \n", *ar);
	print_list(playlist[i]);
}
//======================================================================================
void print_artist(char ar[]){
	//int i = setIndex(*ar);
	//printf("Songs by %s: \n", ar);
  song_node *song = find_playlist_artist(ar);

  while (song && strcmp(ar, song->artist) == 0) {
    printf("%s-%s \n", song->artist, song->name);
    song = song->next;
  }
  printf("\n");
}
//======================================================================================
void print_playlist(){
  int i;
  for (i = 0; i < 26; i++) {
    printf("%c Artists:\n", getChar(i));
    print_list(playlist[i]);
  }

}
/*
//======================================================================================
void shuffle(){
    int i;
    for (i = 0; i < 26; i++) {
        if (playlist[i]) {
            song_node *song = rand_node(playlist[i]);
            if (song) {
                printf("%s-%s \n", song->artist,song->name);
            }
        }
    }
}
*/
//======================================================================================
void delete_song(char title[], char ar[]){
	int i = setIndex(*ar);
	playlist[i] = remove_node(playlist[i],title,ar);
}
//======================================================================================
void delete_playlist(){
	int i = 0;
  	for (; i < 26; i++)
    	playlist[i] = free_list(playlist[i]);
}
