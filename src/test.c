#include "../include/CuTest.h"
#include <stdio.h>

CuSuite* StrUtilGetSuite();
static void RunAllTests(void) {//запускаем все тесты
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    CuSuiteAddSuite(suite, StrUtilGetSuite());

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}


int main(void) {
    RunAllTests();
}
