#ifndef TRIE_ON_C_TRIE_H_H
#define TRIE_ON_C_TRIE_H_H
void createTrie(char *inputFile, char *outputFile);

typedef struct Trie {
    int value;
    int counter;
    struct Trie *list;// список детей-деревьев
}Trie;

void add(Trie *pt, int *pv, const int *pc);
#endif //TRIE_ON_C_TRIE_H_H
