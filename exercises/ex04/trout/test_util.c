#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "minunit.h"
#include "util.c"
#include "trout.h"

/* this function tests tv from util. */

typedef struct timeval Timeval;
int tests_run = 0;

static char *test1() {
    struct timeval out;
    struct timeval in;
    out.tv_usec =500000;
    out.tv_sec = 10;
    in.tv_usec =100000;
    in.tv_sec = 0;
    tv_sub(&out, &in);
    char *message = "test1 failed: tv_sub(\"500000us\", \"100000us\") should return 400000usec";
    mu_assert(message, out.tv_usec == 400000);
    return 0;
}
static char *test2() {
    struct timeval out;
    struct timeval in;
    out.tv_sec = 156;
    out.tv_usec = 0;
    in.tv_sec = 5;
    in.tv_usec = 100000;
    tv_sub(&out, &in);
    char *message = "test2 failed: tv_sub(\"156s\", \"5s, 100000us\") should return 150sec";
    mu_assert(message, out.tv_sec == 150);
    return NULL;
}
static char *test3() {
    struct timeval out;
    struct timeval in;
    out.tv_sec = 10;
    out.tv_usec = 100000;
    in.tv_sec = 100;
    in.tv_usec = 100000;
    tv_sub(&out, &in);
    char *message = "test1 failed: endswith(\"10s, 100000us\", \"100s, 100000\") should return -90sec";
    mu_assert(message, out.tv_sec == -90);
    return NULL;
}
static char * all_tests() {
    mu_run_test(test1);
    mu_run_test(test2);
    mu_run_test(test3);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED HOORAY\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
