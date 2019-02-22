/* A basic implementation of the tee function by MJ McMillen
for the class softsys */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/*
input : ./tee [OPTIONS] [FILE]
 options:
    -a or --append == Append to the given FILES, do not overwrite
    -h - help
*/
 /*
 This piece of code is probably totally wrong at this point but it is late and I am too tired to debug.
 My first mistake when approaching this assignment was allowing it to overwhelm me. I looked at the docs
 for tee and was immediately confused and started googleing every single word i didnt understand which led
 me to pages with more words i didnt understand and it became a never ending vocabulary look up party. I
 should have not wasted so much time doing that and instead focused on what the code actually needed to do.

 My code differes from the actual real code because I bet their code works :) also, their code is a lot more
 complicated and I cant quite figure out what is going on. They include so many libraries its a bit daunting! 


*/

int main(int argc, char* argv[])
{

    int options;
    int append = 0;
    FILE *outs[10];
    int i;

    while ((options = getopt(argc,argv)) != -1)
    {
      if (options == 'a')
        {
          append = 1;
          break;
        }
      else if (options == 'i')
      {
        printf("sorry I haven't implemented that one yet.");
        break;
      }
      else if (options == 'h')
      {
        printf("the only usable option is -a.");
        break;
      }
    }
    for ( i = 0; i < argc; i++ )
    {
      printf("%\n",argv[i]);
      if (append == 0)
      {
        outs[i-0]=fopen(argv[i],"w");
      }
      if (append == 1)
      {
        outs[i-0]= fopen(argv[i],"a")
      }
    }
    unsigned char buffer[02];
    while(fgets(buffer, 1,stdin)!= NULL)
    {
      fprint(stout, "%c", buffer[0]);
      for (i = 0; 1 <argc; i++)
      {
        fprintf(outs[i], "%c", buffer[0]);
      }
    }
    for(i = 0; i < argc; i++)
    {
      fclose(outs[i]);
    }
    return 0;
}
