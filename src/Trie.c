#include <stdio.h>
#include <stdlib.h>
#include "../include/Trie_H.h"

void printFromTrie(Trie trie, FILE *pIobuf) {
    fprintf(pIobuf, "%d: ",trie.value);
    if (trie.counter != 0) {
        for (int i = 0; i < trie.counter; ++i) {
            if (trie.counter != 0) {
                fprintf(pIobuf, "%d", trie.list[i].value);
                if (i != trie.counter - 1) {
                    fprintf(pIobuf, ", ");
                } else {
                    fprintf(pIobuf, "\n");
                }
            }
        }
    } else {
        fprintf(pIobuf, "\n");
    }
    for (int i = 0; i < trie.counter; ++i) {
        printFromTrie(trie.list[i], pIobuf);
    }
    free(trie.list);
}

Trie *findPlace(Trie *pTrie, int *pInt) {
    if (pTrie->list != NULL) {
        for (int i = 0; i < pTrie->counter; i++) {
            if(pTrie->list != NULL && (int) pTrie->list[i].value == *pInt) {
                return &pTrie->list[i];
            } else {
                Trie *newTrie = findPlace(&pTrie->list[i], (int *) pInt);
                if ((int) newTrie->value == *pInt) {
                    return newTrie;
                }
            }
        }
        return pTrie;
    } else {
        return pTrie;
    }
}
void add(Trie *pt, int *pv, const int *pc) {
    int charRoot = pt->value;
    pt = findPlace(pt, pv);
    Trie *child = malloc(sizeof(Trie));
    child -> value = *pc;
    child -> counter = 0;
    child -> list = NULL;
    if (*pv == charRoot || pt->list == NULL) {//корень
        pt -> value = *pv;
        pt -> counter++;
        pt -> list = realloc(pt->list, pt->counter * sizeof(Trie));
        pt -> list[pt->counter - 1] = *child;//добавит child
    } else if (pt->list != NULL && *pv == pt->value) {//проработать, не добавит child
        pt -> counter++;
        pt -> list = realloc(pt->list, pt->counter * sizeof(Trie));
        pt -> list[pt->counter - 1] = *child;//добавит child
    } else {
        Trie *tt = malloc(sizeof(Trie));
        tt -> value = *pv;
        tt -> counter = 1;
        tt -> list = malloc(tt->counter * sizeof(Trie));
        tt -> list[tt->counter - 1] = *child;
        pt -> counter++;
        pt -> list = realloc(pt->list, pt->counter * sizeof(Trie));
        pt -> list[pt->counter - 1] = *tt;
    }
}

void createTrie(char *inputFile, char *outputFile) {
    FILE *fp;
    Trie trie;
    trie.list = NULL;
    trie.value = (int) NULL;
    trie.counter = 0;
    int val, child;
    if ((fp = fopen(inputFile, "r")) == NULL) {
        printf("Failed to open %s\n",inputFile);
        exit(1);
    }
    printf("Parent-child\n");
    while (fscanf(fp, "%d-%d\n", &val, &child) == 2) {
        printf("%d-%d\n", val, child);
        add(&trie, &val, &child);
    }
    if ((fp = fopen(outputFile, "w")) == NULL) {
        printf("Fail to open or create %s\n",outputFile);
        exit(1);
    }

    printFromTrie(trie, fp);
    free(trie.list);
    fclose(fp);
}