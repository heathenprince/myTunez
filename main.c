#include <stdio.h> 
#include <stdlib.h>
#include "playlist.h"

int main(){
  printf("\n");
  add_song("cool song","a");
  add_song("bad song","a");
  add_song("okay song","ay");
  add_song("hellohello","p");
  add_song("byebye","p");
  printf("\n");

  
  find_playlist_song("okay song");
  find_playlist_song("yayz");
  printf("\n");
  

  find_playlist_artist("a");
  find_playlist_artist("p");
  find_playlist_artist("jj");
  printf("\n");

  print_entries("a");
  print_entries("p");
  printf("\n");

  printf("Songs by a: \n");
  print_artist("a");
  printf("Songs by p: \n");
  print_artist("p");
  printf("Songs by ay: \n");
  print_artist("ay");

  print_playlist();
  //shuffle();
  printf("\n");
  return 0;
}

/*
//OUTPUTS =============================================================================

Inserting a-cool song into playlist[0]
a-cool song 
Inserting a-bad song into playlist[0]
a-cool song a-bad song 
Inserting ay-okay song into playlist[0]
a-cool song a-bad song ay-okay song 
Inserting p-hellohello into playlist[15]
p-hellohello 
Inserting p-byebye into playlist[15]
p-hellohello p-byebye 

Finding okay song in playlist
Found ay-okay song 
Finding yayz in playlist
Could not find requested song. 

Finding a in playlist
Found a-cool song 
Finding p in playlist
Found p-hellohello 
Finding jj in playlist
Could not find requested artist. 

a Artists: 
a-cool song a-bad song ay-okay song 
p Artists: 
p-hellohello p-byebye 

Songs by a: 
a-cool song 
a-bad song 

Songs by p: 
p-hellohello 
p-byebye 

Songs by ay: 
ay-okay song 

A Artists:
a-cool song a-bad song ay-okay song 
B Artists:

C Artists:

D Artists:

E Artists:

F Artists:

G Artists:

H Artists:

I Artists:

J Artists:

K Artists:

L Artists:

M Artists:

N Artists:

O Artists:

P Artists:
p-hellohello p-byebye 
Q Artists:

R Artists:

S Artists:

T Artists:

U Artists:

V Artists:

W Artists:

X Artists:

Y Artists:

Z Artists:




*/