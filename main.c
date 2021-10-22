#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "songs.h"
#include "library.h"

void linked_list_test();
void library_test();


int main() {
    //linked_list_test();
    library_test();

    return 0;
}


// Tests for the linked list part
void linked_list_test() {
    // insert_front tests
    printf("====================================\n\n");
    printf("Testing insert_front:\n");
    struct song *songs = make_song("street spirit (fade out)", "radiohead");
    songs = insert_front(songs, "paranoid android", "radiohead");
    songs = insert_front(songs, "time", "pink floyd");
    songs = insert_front(songs, "yellow ledbetter", "pearl jam");
    songs = insert_front(songs, "even flow", "pearl jam");
    songs = insert_front(songs, "alive", "pearl jam");
    songs = insert_front(songs, "thunderstruck", "ac/dc");
    print_list(songs);

    // insert_node tests
    printf("====================================\n\n");
    printf("Testing insert_node:\n");
    struct song *songs2 = 0;
    songs2 = insert_node(songs2, "even flow", "pearl jam");
    songs2 = insert_node(songs2, "street spirit (fade out)", "radiohead");
    songs2 = insert_node(songs2, "thunderstruck", "ac/dc");
    songs2 = insert_node(songs2, "time", "pink floyd");
    songs2 = insert_node(songs2, "yellow ledbetter", "pearl jam");
    songs2 = insert_node(songs2, "alive", "pearl jam");
    songs2 = insert_node(songs2, "paranoid android", "radiohead");
    print_list(songs2);

    // print_list tests
    printf("====================================\n\n");
    printf("Testing print_list:\n");
    print_list(songs);

    // print_song tests
    printf("====================================\n\n");
    printf("Testing print_song:\n");
    print_song(songs);

    // find_song tests
    printf("====================================\n\n");
    printf("Testing find_song:\n");
    printf("looking for [pearl jam: even flow]\n");
    struct song *search = find_song(songs, "even flow", "pearl jam");
    if (search) {
        printf("node found! %s: %s\n", search->artist, search->title);
    } else {
        printf("node not found\n");
    }

    printf("looking for [pearl jam: daughter]\n");
    search = find_song(songs, "daughter", "pearl jam");
    if (search) {
        printf("node found! %s: %s\n", search->artist, search->title);
    } else {
        printf("node not found\n");
    }

    // find_artists_song tests
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

    // song_cmp tests
    printf("====================================\n\n");
    printf("Testing songcmp (helper function):\n");

    printf("Comparing [pearl jam: even flow] to [pearl jam: even flow]\n");
    struct song *ef_pj = find_song(songs, "even flow", "pearl jam");
    printf("%d\n", song_cmp(ef_pj, ef_pj));

    printf("Comparing [pearl jam: even flow] to [pearl jam: alive]\n");
    struct song *a_pj = find_song(songs, "alive", "pearl jam");
    printf("%d\n", song_cmp(ef_pj, a_pj));

    printf("Comparing [pearl jam: alive] to [pearl jam: even flow]\n");
    printf("%d\n", song_cmp(a_pj, ef_pj));

    printf("Comparing [pearl jam: even flow] to [pink floyd: time]\n");
    struct song *t_pf = find_song(songs, "time", "pink floyd");
    printf("%d\n", song_cmp(ef_pj, t_pf));

    // random_song tests
    printf("====================================\n\n");
    printf("Testing random_song:\n");
    printf("List of Songs:\n");
    print_list(songs);
    printf("\nRandom Song:\n");
    print_song(random_song(songs));

    // remove_song tests
    printf("====================================\n\n");
    printf("Testing remove_song:\n");
    printf("List of Songs:\n");
    print_list(songs);
    printf("\n");
    printf("List With Removed Song:\n");
    songs = remove_song(songs,"yellow ledbetter", "pearl jam");
    print_list(songs);

}


// Tests for the library
void library_test() {

    // conv_artist_to_index test
    printf("====================================\n\n");
    printf("Testing conv_artist_to_index:\n")
    struct song *songs = make_song("street spirit (fade out)", "zadiohead");
    struct library **lib = make_library();
    conv_artist_to_index(songs->artist);
}
