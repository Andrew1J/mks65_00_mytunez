#ifndef SONGS_H
#define SONGS_H

#define TITLE_LEN 100
#define ARTIST_LEN 100

struct song {
    char title[TITLE_LEN];
    char artist[ARTIST_LEN];
    struct song *next;
};

struct song* library[27];

//functions
struct song * insert_front(struct song *s, char *t, char *a);

struct song * insert_node(struct song *s, char *t, char *a);

void print_list(struct song *s);

struct song * find_node(struct song *s, char *t, char *a);

struct song * artists_song(struct song *s, char *t, char*a);

struct song * random_node(struct song *front);

struct song * remove_student(struct song *front, char *t, char *a);

struct song * free_list(struct song *s);

//helper functions
void print_song(struct song *s);

struct song * make_song(char *t, char *a);

#endif
