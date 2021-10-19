#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "songs.h"


// Inserts node at front of linked list
// 
// Author: Dylan Hu
struct song * insert_front(struct song *s, char *t, char *a) {
    struct song *new_song = make_song(t, a);

    new_song->next = s;

    return new_song;
}


// Inserts nodes alphabetically
struct song * insert_node(struct song *s, char *t, char *a) {
    return 0;
}


// Prints entire list
// 
// Author: Dylan Hu
void print_list(struct song *s) {
    while (s) {
        print_song(s);
        s = s->next;
    }
}


// Finds node given artist + song name
//
// Author: Dylan Hu
struct song * find_song(struct song *s, char *t, char *a) {
    while (s && strcmp(s->title, t) && strcmp(s->artist, a)) {
        s = s->next;
    }

    return s;
}


// Finds first song of an artist given artist's name
//
// Author: Dylan Hu
struct song * find_artists_song(struct song *s, char *t, char*a) {
    while (s && strcmp(s->artist, a)) {
        s = s->next;
    }

    return s;
}


// Returns random node
struct song * random_song(struct song *front) {
    return 0;
}


// Removes node and returns beginning of linked list
struct song * remove_song(struct song *front, char *t, char *a) {
    return 0;
}


// Frees list
//
// Author: Dylan Hu (stolen from u Andrew lol)
struct song * free_list(struct song *s) {
    struct song *temp;

    while (s) {
        temp = s->next;
        free(s);
        s = temp;
    }

    return temp;
}


// Prints individual song
//
// Author: Andrew Juang
void print_song(struct song *s) {
    printf("Artist: %s\t Song: %s\t\n", s->artist, s->title);
}


// Creates node
//
// Author: Andrew Juang
struct song * make_song(char *t, char *a) {
    struct song *s = malloc(sizeof(struct song));

    strcpy(s->title, t);
    strcpy(s->artist, a);

    s->next = NULL;

    return s;
}
