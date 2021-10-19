#ifndef SONGS_H
#define SONGS_H

#define TITLE_LEN 100
#define ARTIST_LEN 100

struct song {
    char title[TITLE_LEN];
    char artist[ARTIST_LEN];

    struct song *next;
};

#endif
