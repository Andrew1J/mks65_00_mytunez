#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "songs.h"
#include "library.h"


int main() {
    srand(time(NULL));
    struct song *linked_list = make_node("DW","Baby");
    print_node(linked_list);
    free(linked_list);
    return 0;
}
