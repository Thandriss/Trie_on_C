#include <stdio.h>
#include <stdlib.h>
typedef struct Trie {
    int value;
    int counter;
    struct Trie *list;// список детей-деревьев
}Trie;


void printFromTrie(Trie trie, FILE *pIobuf) {
    fprintf(pIobuf, "%d: ",trie.value);
    for (int i = 0; i < trie.counter; ++i) {
        if (trie.list != NULL) {
            fprintf(pIobuf, "%d", trie.list[i].value);
            if (i != trie.counter - 1) {
                fprintf(pIobuf, ", ");
            } else {
                fprintf(pIobuf, "\n");
            }
        }
    }
    for (int i = 0; i < trie.counter; ++i) {
        printFromTrie(trie.list[i], pIobuf);
        fprintf(pIobuf, "\n");
    }
};

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
void add(Trie *pt, const int *pv, const int *pc) {
    pt = findPlace(pt, pv);
    Trie *child = malloc(sizeof(Trie));
    child->value = *pc;
    child -> counter = 0;
    child->list = malloc(sizeof(Trie));
    if ((void *) pt->value == NULL) {//корень
        Trie *tt = malloc(sizeof(Trie));
        tt->value = *pv;
        tt -> counter = 1;
        tt->list = malloc(tt->counter * sizeof(Trie));
        tt -> list[tt->counter - 1] = *child;
        pt -> counter++;
        pt -> list = realloc(pt->list, pt->counter * sizeof(Trie));
        pt -> list[pt->counter - 1] = *tt;//добавит child
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
    trie.value = (int) NULL;
    trie.counter = 0;
    int val, child;
    if ((fp = fopen(inputFile, "r")) == NULL) {
        printf("Failed to open %s\n",inputFile);
        exit(1);
    }

    while (fscanf(fp, "%d-%d\n", &val, &child) == 2) {
        printf("%d-%d\n", val, child);
        add(&trie, &val, &child);
    }
    if ((fp = fopen(outputFile, "w")) == NULL) {
        printf("Fail to open or create %s\n",outputFile);
        exit(1);
    }
    for (int  i = 0;  i < trie.counter; ++ i) {
        printFromTrie(trie.list[i], fp);
    }
}



