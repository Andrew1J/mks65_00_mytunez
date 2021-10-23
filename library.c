#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "songs.h"
#include "library.h"


// makes a new library
struct song ** make_library(struct song **library) {
    library = calloc(27, sizeof(struct song *));

    return library;
}


// adds a song to library
struct song ** add_song(struct song **library, char *title, char *artist) {
    int ind = conv_artist_to_index(artist);

    library[ind] = insert_node(library[ind], title, artist);
    
    return library;
}


// finds a certain song in the library
struct song * find_song_in_library(struct song **library, char *title, char *artist) {
    int ind = conv_artist_to_index(artist);

    return find_song(library[ind], title, artist);
}


// finds the first song of a certain artist
// in the library
struct song * find_artist_in_library(struct song **library, char *artist) {
    int ind = conv_artist_to_index(artist);

    return find_artists_song(library[ind], artist);
}


// prints all the songs in a certain category
// in the library
//
// TODO:
// could call print_list from songs.h
void print_letter(struct song **library, char letter) {
    struct song * temp = library[conv_char_to_index(letter)];

    printf("[ ");

    while (temp) {
        printf("{%s, %s} | ", temp->artist, temp->title);
        temp = temp->next;
    }

    printf("]\n");
}


// prints out all the songs of a certain artist
void print_artist(struct song **library, char *artist) {
    return;
}


// prints the contents of the entire library
void print_library(struct song **library) {
    int i;

    for (i = 0; i < 26; i++){
        printf("%c: ", i + 97);
        char l = i + 97;
        print_letter(library, l);
    }

    printf("Other: ");
    print_letter(library, '$');  // kinda dumb and hacky but whatever
}


// returns a series of randomly chosen songs
void shuffle_library(struct song **library, int num_songs) {
    return;
}


// deletes a song from the library
struct song ** delete_song(struct song **library, char *title, char *artist) {
    int ind = conv_artist_to_index(artist);

    library[ind] = remove_song(library[ind], title, artist);

    return library;
}


// clears the entire library
struct song ** clear_library(struct song **library) {
    int i;

    for (i = 0; i < 27; i++){
        library[i] = free_list(library[i]);
    }

    return library;
}


// Returns the index of the correct category
// for a given artist
int conv_artist_to_index(char *artist) {
    return conv_char_to_index(artist[0]);
}


// Returns the index of the correct category
// for a given character
int conv_char_to_index(char c) {
    if (isalpha(c)) {
        return ((int) tolower(c)) - 97;
    }
    else {
        return 26;
    }
}
