#ifndef TRIE_ON_C_TRIE_H_H
#define TRIE_ON_C_TRIE_H_H

#include <stddef.h>
#include <stdbool.h>
void createTrie(char *inputFile, char *outputFile);

typedef struct Trie {
    int value;
    int counter;
    struct Trie *list;// список детей-деревьев
}Trie;

#endif //TRIE_ON_C_TRIE_H_H
