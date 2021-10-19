#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "songs.h"
#include "library.h"


int main() {
    srand(time(NULL));

    struct song *linked_list = make_song("DW","Baby");
    print_song(linked_list);

    free(linked_list);
    
    return 0;
}
