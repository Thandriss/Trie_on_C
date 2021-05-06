#include <stdio.h>
#include <stdlib.h>
#include "Trie_H.h"
int main(int argc, char *args[]) {
    if (argc != 3) {
        printf("IllegalArgumentException. InputFileName OutputFileName");
        exit(1);
    }

    createTrie(args[1], args[2]);
    return EXIT_SUCCESS;
}