#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "songs.h"

// Inserts node at front of linked list
struct song * insert_front(struct song *s, char *t, char *a) {
    return 0;
}

// Inserts nodes alphabetically
struct song * insert_node(struct song *s, char *t, char *a) {
    return 0;
}

// Prints entire list
void print_list(struct song *s) {
    return;
}

// Finds node given artist + song name
struct song * find_node(struct song *s, char *t, char *a) {
    return 0;
}

// Finds first song of an artist given artist's name
struct song * artists_song(struct song *s, char *t, char*a) {
    return 0;
}

// Returns random node
struct song * random_node(struct song *front) {
    return 0;
}

// Removes node and returns beginning of linked list
struct song * remove_student(struct song *front, char *t, char *a) {
    return 0;
}

// Frees list
struct song * free_list(struct song *s) {
    return 0;
}

// Prints individual song
void print_node(struct song *s) {
    printf("Artist: %s\t Song: %s\t\n", s->artist, s->title);
}

// Creates node
struct song * make_node(char *t, char *a) {
    struct song *s = malloc(sizeof(struct song));

    strcpy(s->title, t);
    strcpy(s->artist, a);
    s->next = NULL;

    return s;
}
