#include "songs.h"
#include "library.h"

struct song ** make_library() {
    struct song ** library[27];
    return library;
}

struct song ** add_song(struct song **library, char *title, char *artist) {
    return;
}

struct song * find_song_in_library(struct song **library, char *title, char *artist) {
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
}

void print_library(struct song **library) {
    return;
}

void shuffle_library(struct song **library, int num_songs) {
    return;
}

struct song ** delete_song(struct song **library, char *title, char *artist) {
    return;
}

struct song ** clear_library(struct song **library) {
    return;
}

int conv_artist_to_index(char *artist) {
    return 0;
}
