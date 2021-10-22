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

struct song * find_song_in_library(struct song **library, char *title, char *artist) {
    int ind = conv_artist_to_index(artist);
    return find_song(library[ind], title, artist);
}

struct song * find_artist_in_library(struct song **library, char *artist) {
    int ind = conv_artist_to_index(artist);
    return find_artists_song(library[ind], artist);
}

void print_letter(struct song **library, char letter) {
    struct song * temp = library[letter - 97];
    printf("[ ");
    while(temp){
        printf("{%s, %s} | ", temp->artist, temp->title);
        temp = temp->next;
    }
    printf("]\n");
}

void print_artist(struct song **library, char *artist) {
    return;
}

void print_library(struct song **library) {
    int i;
    for(i=0;i<26;i++){
        printf("%c: ",i+97);
        char l = i+97;
        print_letter(library,l);
    }
}

// void shuffle_library(struct song **library, int num_songs) {
//     return;
// }

struct song ** delete_song(struct song **library, char *title, char *artist) {
    int ind = conv_artist_to_index(artist);
    library[ind] = remove_song(library[ind], title, artist);
    return library;
}

struct song ** clear_library(struct song **library) {
    int i;
    for(i=0;i<26;i++){
        library[i] = free_list(library[i]);
    }
    return library;
}

int conv_artist_to_index(char *artist) {
    return ((int)tolower(artist[0])) - 97;
}
