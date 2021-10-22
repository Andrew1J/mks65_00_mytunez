#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "songs.h"


// Inserts node at front of linked list
struct song * insert_front(struct song *s, char *t, char *a) {
    struct song *new_song = make_song(t, a);

    new_song->next = s;

    return new_song;
}


// Inserts nodes alphabetically
struct song * insert_node(struct song *s, char *t, char *a) {
    struct song *beg = s;
    struct song *new_song = make_song(t,a);

    // Case when linkedlist is empty or node is less than first element of list
    if(!s || song_cmp(new_song,s)<=0) {
        s = insert_front(s,t,a);
        return s;
    }

    // Case when linkedlist size > 2
    while(s->next) {
        if(song_cmp(new_song,s->next) > 0) {
            s = s->next;
        } else {
            new_song->next = s->next;
            s->next = new_song;
            return beg;
        }
    }

    // Case when linked list size is 1 or node belongs at end of linkedlist
    if(song_cmp(new_song,s)>0){
        s->next = new_song;
    } else {
        s = insert_front(s,t,a);
        return s;
    }

    // Return iterator to beginning of linkedlist
    return beg;
}


// Prints entire list
void print_list(struct song *s) {
    while (s) {
        print_song(s);
        s = s->next;
    }
}


// Finds node given artist + song name
struct song * find_song(struct song *s, char *t, char *a) {
    while (s && (strcmp(s->title, t) || strcmp(s->artist, a))) {
        s = s->next;
    }
    return s;
}


// Finds first song of an artist given artist's name
struct song * find_artists_song(struct song *s, char *a) {
    while (s && strcmp(s->artist, a)) {
        s = s->next;
    }

    return s;
}


// Returns random node
struct song * random_song(struct song *front) {
    int len_list = 0, rand_ind, ind;
    struct song * rand_song = front;
    while (front) {
        front = front->next;
        len_list++;
    }
    srand(time(NULL));
    rand_ind = rand()%len_list;
    for(ind=0;ind<rand_ind;ind++) {
        rand_song = rand_song->next;
    }
    return rand_song;
}


// Removes node and returns beginning of linked list
struct song * remove_song(struct song *front, char *t, char *a) {
    struct song *temp, *beg=front;

    if (strcmp(front->title,t)==0 && strcmp(front->artist,a)==0) beg = front->next;

    while (front != NULL && (strcmp(front->title,t)!=0 || strcmp(front->artist,a)!=0)) {
        temp = front;
        front = front->next;
    }

    if (front != NULL){
        temp->next = front->next;
        free(front);
    }

    return beg;
}


// Frees list
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
void print_song(struct song *s) {
    printf("Artist: %s\t Song: %s\t\n", s->artist, s->title);
}


// Creates node
struct song * make_song(char *t, char *a) {
    struct song *s = malloc(sizeof(struct song));

    strcpy(s->title, t);
    strcpy(s->artist, a);

    s->next = NULL;

    return s;
}


// Compares two songs by artist first,
// then if they have the same artist it
// compares by title
int song_cmp(struct song *a, struct song *b) {
    int artist_diff = strcmp(a->artist, b->artist);
    if (artist_diff) return artist_diff;
    return strcmp(a->title, b->title);
}
