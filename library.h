#ifndef LIBRARY_H
#define LIBRARY_H

//
// Function Headers
//

// Creating and adding
struct song ** make_library();
struct song ** add_song(struct song **library, struct song *new_song);

// Searching
struct song * find_song_in_library(struct song **library, char *title, char *artist);
struct song * find_artist_in_library(struct song **library, char *artist);

// Printing
void print_letter(struct song **library, char letter);
void print_artist(struct song **library, char *artist);
void print_library(struct song **library);
void shuffle_library(struct song **library, int num_songs);

// Removing
struct song ** delete_song(struct song **library, char *title, char *artist);
struct song ** clear_library(struct song **library);

#endif
