/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;
int print_local(int *vary);


// PART 4
int print_local(int *vary)
{
  //makes a local variable, prints its address, returns 0
  int vary2 = 13;
  printf("Address of local variable 1 is %p\n",vary);
  printf("Address of local variable 2 is %p\n",&vary2);
  if (vary > &vary2)
  {
    printf("stack grows down\n");
  }
  else if (vary < &vary2)
  {
    printf("stack grows up\n");
  }
  else
  {
    printf("ya done goofed\n");
  }
  return 0;
}

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    void *q = malloc(128);
    int r = p-q;
    char *s = "Hello, World";
    void *chunk1 = malloc(14);
    void *chunk2 = malloc(14);
    int math = chunk1 - chunk2;

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("q points to %p\n",q); // shows our new malloc location
    printf ("the difference is %d\n",r);
    printf ("s points to %p\n", s);
    print_local(&var2); //it goes down! so it wont run into the heap.
    printf ("Address of chunk 1 is %p\n", chunk1);
    printf ("Address of chunk 2 is %p\n", chunk2);
    printf ("The space between chunks is %d\n", math);

    return 0;
}
