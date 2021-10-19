#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "songs.h"
#include "library.h"

void linked_list_test();
void library_test();


int main() {
    linked_list_test();
    library_test();
    
    return 0;
}


// Tests for the linked list part
void linked_list_test() {
    struct song *songs = make_song("street spirit (fade out)", "radiohead");
    songs = insert_front(songs, "paranoid android", "radiohead");
    songs = insert_front(songs, "time", "pink floyd");
    songs = insert_front(songs, "yellow ledbetter", "pearl jam");
    songs = insert_front(songs, "even flow", "pearl jam");
    songs = insert_front(songs, "even flow", "pearl jam");
    songs = insert_front(songs, "alive", "pearl jam");
    songs = insert_front(songs, "thunderstruck", "ac/dc");

    printf("LINKED LIST TESTS\n");
    printf("====================================\n\n");

    printf("Testing print_list:\n");
    print_list(songs);

    printf("====================================\n\n");
    printf("Testing print_song:\n");
    print_song(songs);

    printf("====================================\n\n");
    printf("Testing find_song:\n");
    printf("looking for [pearl jam: even flow]\n");
    struct song *search = find_song(songs, "even flow", "pearl jam");
    if (search) {
        printf("node found! %s: %s\n", search->artist, search->title);
    }
    else {
        printf("node not found\n");
    }

    printf("looking for [pearl jam: daughter]\n");
    search = find_song(songs, "daughter", "pearl jam");
    if (search) {
        printf("node found! %s: %s\n", search->artist, search->title);
    }
    else {
        printf("node not found\n");
    }

    printf("====================================\n\n");
    printf("Testing find_artists_song:\n");
    printf("looking for [pink floyd]\n");
    search = find_artists_song(songs, "pink floyd");
    if (search) {
        printf("artist found! ");
        print_list(search);
    }
    else {
        printf("artist not found\n");
    }

    printf("looking for [pearl jam]\n");
    search = find_artists_song(songs, "pearl jam");
    if (search) {
        printf("artist found! ");
        print_list(search);
    }
    else {
        printf("artist not found\n");
    }

    printf("looking for [presidents of the united states of america]\n");
    search = find_artists_song(songs, "presidents of the united states of america");
    if (search) {
        printf("artist found! ");
        print_list(search);
    }
    else {
        printf("artist not found\n");
    }

    // more tests later
}


// Tests for the library
void library_test() {
    return;
}
