#include "../include/Trie_H.h"
#include "../include/CuTest.h"
#include <stdio.h>
#include <stdlib.h>
#define STRING_INTIAL_SIZE 256


char* fileToString( FILE* fp ) {
    int strSize = STRING_INTIAL_SIZE;
    char* str = (char*) calloc(strSize, sizeof(char));
    int i = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {
        str[i] = c;
        i++;
        if ( i == strSize ) {
            strSize = strSize * 2;
            str = realloc(str, strSize);
        }
    }
    return str;
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
    SUITE_ADD_TEST(suite, TestCreateTrie);

    return suite;
}
