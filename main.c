#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "songs.h"
#include "library.h"


int main() {
    srand(time(NULL));

    struct song *songs = make_song("DW","Baby");
    print_list(songs);

    printf("\n");

    songs = insert_front(songs, "Suge", "Da Baby");
    print_list(songs);

    songs = free_list(songs);
    printf("Freed Song List: %p\n", songs);
    
    return 0;
}
