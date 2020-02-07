/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

1. This program creates an array of a length defined by the global variable
SIZE. foo prints the 'empty' array then fills it spot by spot with the number 42
. it then returns the array. then bar makes and prints an array before creating a new arrya
of [0,1,2,3,4]. it then tries to print all the elements of the foo array.

2. I recuved a warning for function 'foo'. the warning said the function returns
an address of a local variable. I think this means that the array's memory spot
will be up for grabs after the function is over so if the pointer is used later,
it will point to some random numbers instead of the array set up in the function.
this is because the array is local.

3. I got a segmentation fault. I think I got this because I tried to access
a bit of memory that no longer belonged to the array I was trying to call. The
thing my array pointer from foo pointed at was no longer availible.

4. The same thing happened. :(

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    //printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    //printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
