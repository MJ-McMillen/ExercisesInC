/*
This homework was a bit of a wild ride for me. It took me a long time to
figure out where the information that is fed into tee came from.  I did
not understand what standard input meant or how i was supposed to call
the function. Once I learned that when I call stdinput it took input
from the command line. I also then found out that the pipe functionality
was also built in yay! (I spent about four frusterated hours trying to
figure this part out.) Katie Foster helped me out with this.

Once I got that part, the rest of the coding went quite quickly. I did
sort of do this exersize last year but it very much did not work. I took
the general functions used (like getopt) and encorperated them. Once I
understood excactly how to call and use tee, coding was very fast. I wrote it
in about an hour and it worked on my third try! (its printf not fprint apparently)

In the future, I will ask for help a bit sooner if i am not understanding the
documentation. Normally, i have trouble with how to actually run the program which
is a weird step to get stuck on.

My code is nice but not as complex looking as the official code. I also did not
implement all the other options. I honestly cannot really understand half of the
pro code. It feels like I am learning a new forign language. When I try and read the
proffessional implementation, I can recognize simple words I know but am overwhelmed
by all I do not know. f


*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER 64

int main(int argc, char* argv[])
{

    int options;
    int append = 0;
    FILE* outs;
    int i;
    char input_buff[MAX_BUFFER];

    while ((options = getopt(argc,argv,"a:")) != -1) // gives me the options
    {
      if (options == 'a')
        {
          append = 1; // we are appending
          break;
        }
      else
      {
        printf("Sorry, the only usable option is -a append.");
        break;
      }
    }
    while(fgets(input_buff, 1,stdin)!= NULL)
    {
      if (argv[i][0] != '-')
      {
        if(append == 1)
        {
          // we need to add onto the end.
          outs = fopen(argv[i],"a");
        }
        else
        {
          // we are overwriting everything.
          outs = fopen(argv[i],"w");
        }
        fputs(input_buff,outs);
        fclose(outs);

      }

    }
    return 1;
  }
