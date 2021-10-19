#ifndef SONGS_H
#define SONGS_H

#define TITLE_LEN 100
#define ARTIST_LEN 100

struct song {
    char title[TITLE_LEN];
    char artist[ARTIST_LEN];
    struct song *next;
};

//struct song* library[27];

//
// Function Headers
//

// Insertion
struct song * insert_front(struct song *s, char *t, char *a);
struct song * insert_node(struct song *s, char *t, char *a);

// Printing
void print_list(struct song *s);

// Finding
struct song * find_song(struct song *s, char *t, char *a);
struct song * find_artists_song(struct song *s, char *artist);
struct song * random_song(struct song *front);

// Removing
struct song * remove_song(struct song *front, char *t, char *a);
struct song * free_list(struct song *s);

// Helper Functions
void print_song(struct song *s);
struct song * make_song(char *t, char *a);
int song_cmp(struct song *a, struct song *b);

#endif
