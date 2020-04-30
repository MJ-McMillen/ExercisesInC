/* Example code for Exercises in C.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void free_anything(int *p) {
    free(p);
}

int read_element(int *array, int index) {
    int x = array[index];
    return x;
}

int main()
{
    int never_allocated;
    int *free_twice = malloc(sizeof (int));
    int *use_after_free = malloc(sizeof (int));
    int *never_free = malloc(sizeof (int));
    int array1[100];
    int *array2 = malloc(100 * sizeof (int));

    // valgrind does not bounds-check static arrays
    //read_element(array1, -1);Paddling 1: Array indecies are from 0 to 99. no - indicies
    //read_element(array1, 100); Paddling 2: Arrays are 0 indexed. no index 100

    // but it does bounds-check dynamic arrays
    //read_element(array2, -1); Paddling 3: AGAIN arrays start at 0.
    //read_element(array2, 100); Paddling 4: Arrays still indexed at 0

    // and it catches use after free
    free(use_after_free);
    //*use_after_free = 17; Paddling 5: You already freed it. It is gone. you cant get it back.

    // never_free is definitely lost
    *never_free = 17; // This is fine. Not great. Just fine.

    // the following line would generate a warning
    // free(&never_allocated);

    // but this one doesn't
    //free_anything(&never_allocated); Paddling 6: You cant free unallocated memory

    free(free_twice);
    // free(free_twice); Paddling 7: You cant free what has already been freed. 

    return 0;
}
