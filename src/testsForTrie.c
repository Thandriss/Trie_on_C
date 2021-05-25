#include "../include/Trie_H.h"
#include "../include/CuTest.h"
#include <stdio.h>
#include <stdlib.h>
#define STRING_INTIAL_SIZE 256


char* fileToString( FILE* fp ) {
    int strSize = STRING_INTIAL_SIZE;
    char* string = (char*) malloc(strSize * sizeof(char));
    int i = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {
        string[i] = c;
        i++;
        if ( i == strSize ) {
            strSize = strSize * 2;
            string = realloc(string, strSize);
        }
    }
    return string;
}

void TestTrieAdd(CuTest *tc) {
    Trie *trie;
    trie->list = NULL;
    trie->value = (int) NULL;
    trie->counter = 0;
    int par = 5;
    int ch = 3;
    add(trie, (int *) par, (const int *) ch);
    Trie *oldtrie = trie;
    trie = findPlace(trie, (int *) par);
    if (trie->value == par) {
        for (int i = 0; i < trie->counter; i++) {
            if (trie->list[i].value == ch) {
                CuAssertIntEquals_Msg(tc, "Node is created!", trie->list[i].value, ch);
            }
        }
    }
    trie = oldtrie;
    par = 6;
    ch = 1;
    add(trie, (int *) par, (const int *) ch);
    oldtrie = trie;
    trie = findPlace(trie, (int *) par);
    if (trie->value == par) {
        for (int i = 0; i < trie->counter; i++) {
            if (trie->list[i].value == ch) {
                CuAssertIntEquals_Msg(tc, "Node is created!", trie->list[i].value, ch);
            }
        }
    }
    trie = oldtrie;
    par = 1;
    ch = 4;
    add(trie, (int *) par, (const int *) ch);
    findPlace(trie, (int *) par);
    if (trie->value == par) {
        for (int i = 0; i < trie->counter; i++) {
            if (trie->list[i].value == ch) {
                CuAssertIntEquals_Msg(tc, "Node is created!", trie->list[i].value, ch);
            }
        }
    }
}

void TestCreateTrie(CuTest *tc){
    createTrie("../test_files/In1.txt", "../test_files/TOut1.txt");
    createTrie("../test_files/In2.txt", "../test_files/TOut2.txt");
    char* path = "../test_files/TOut1.txt";
    FILE* actualFile = fopen(path, "r");
    char* actualOutput = fileToString(actualFile);
    fclose(actualFile);
    path = "../test_files/Out1.txt";
    FILE* expectedFile = fopen(path, "r");
    char* expectedOutput = fileToString(expectedFile);
    fclose(expectedFile);
    CuAssertStrEquals(tc, expectedOutput, actualOutput);
    path = "../test_files/TOut2.txt";
    actualFile = fopen(path, "r");
    actualOutput = fileToString(actualFile);
    fclose(actualFile);
    path = "../test_files/Out2.txt";
    expectedFile = fopen(path, "r");
    expectedOutput = fileToString(expectedFile);
    fclose(expectedFile);
    CuAssertStrEquals(tc, expectedOutput, actualOutput);
}
CuSuite* StrUtilGetSuite() {
    //функция для кучи тестов
    printf("Tests:\n");
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestTrieAdd);
    SUITE_ADD_TEST(suite, TestCreateTrie);
    return suite;
}