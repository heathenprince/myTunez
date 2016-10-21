#include <stdio.h>
#include <stdlib.h>
#include "list.h"

song_node *playlist[26];

void add_song(char title[],char ar[]);
song_node *find_playlist_song(char title[]);
song_node *find_playlist_artist(char ar[]);
void print_entries(char ar[]);
void print_artist(char ar[]);
void print_playlist();
void shuffle();
void delete_song(char title[], char ar[]);
void delete_playlist();