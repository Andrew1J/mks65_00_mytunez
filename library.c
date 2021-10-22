#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "songs.h"
#include "library.h"

struct song ** make_library(struct song **library) {
    library = calloc(27,sizeof(struct song *));
    return library;
}

struct song ** add_song(struct song **library, char *title, char *artist) {
    int ind = conv_artist_to_index(artist);
    library[ind] = insert_node(library[ind],title,artist);
    return library;
}

/*struct song * find_song_in_library(struct song **library, char *title, char *artist) {
    return;
}

struct song * find_artist_in_library(struct song **library, char *artist) {
    return;
}

void print_letter(struct song **library, char letter) {
    return;
}

void print_artist(struct song **library, char *artist) {
    return;
}*/

void print_library(struct song **library) {
    int i;
    for(i=0;i<27;i++){
        printf("Section %c of the library: \n",i+97);
        while(library[i]){
            print_song(library[i]);
            library[i] = library[i]->next;
        }
        printf("\n");  
    }
}

/*void shuffle_library(struct song **library, int num_songs) {
    return;
}

struct song ** delete_song(struct song **library, char *title, char *artist) {
    return;
}

struct song ** clear_library(struct song **library) {
    return;
}*/

int conv_artist_to_index(char *artist) {
    return ((int)tolower(artist[0])) - 97;
}
