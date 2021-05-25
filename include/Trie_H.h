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

void add(Trie *pt, int *pv, const int *pc);
Trie *findPlace(Trie *pTrie, int *pInt);
#endif //TRIE_ON_C_TRIE_H_H
