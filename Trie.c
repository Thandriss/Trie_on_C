#include <stdio.h>
#include <stdlib.h>
typedef struct Trie {
    int value;
    int counter;
    struct Trie *next; // следующее дерево
    struct Trie *list;// список детей-деревьев
}Trie;

Trie *findPlace(Trie *pTrie, const int *pInt) {
    if (pTrie->list != NULL) {
        for (int i = 0; i < pTrie->counter; i++) {
            if((const int *) pTrie->list[i].value == pInt) {
                return &pTrie->list[i];
            } else {
                Trie *newTrie = findPlace(&pTrie->list[i], (const int *) *pInt);
                if ((const int *) newTrie->value == pInt) {
                    return newTrie;
                }
            }
        }
        return pTrie;
    } else {
        return pTrie;
    }
}
void add(Trie *pt, const int *pv, const int *pc) {
    pt = findPlace(pt, pv);
    Trie *child = malloc(sizeof(Trie));
    child->value = (int) pc;
    child->next = NULL;
    child->list = malloc(sizeof(Trie));
    if ((void *) pt->value == NULL) {//корень
        Trie *tt = malloc(sizeof(Trie));
        tt->value = (int) pv;
        tt->next = NULL;
        tt->list = malloc(sizeof(Trie));
        pt -> counter++;
        pt -> list[pt->counter - 1] = *child;//добавит child
    } else if (pt->list != NULL && (void *) pt->value != NULL) {//проработать, не добавит child
        pt -> counter++;
        pt -> list = realloc(pt->list, pt->counter * sizeof(Trie));
        pt -> list[pt->counter - 1] = *child;//добавит child
    }
}

void createTrie(char *inputFile, char *outputFile) {
    FILE *fp;
    Trie trie;
    trie.list = NULL;
    trie.next = NULL;
    trie.value = (int) NULL;
    int val, child;
    if ((fp = fopen(inputFile, "r")) == NULL) {
        printf("Failed to open %s\n",inputFile);
        exit(1);
    }
    while (fscanf(fp, "%d-%d\n", &val, &child) == 2) {
        add(&trie, &val, &child);
    }
}
