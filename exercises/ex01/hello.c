#include <stdio.h>
/* Observations:
  adding the int x = 5 adds code to the assembly language output. (2 lines)
  adding the int x = 5 does not add extra code to the optomized assembly language output
  ALSO for next year, please specify that the flag is O2 not 02 I spent 20 min trying to catch that mistake.

  when i print the 5, the code gets shorter.

  My hypothosis is optomisation takes out everything not referenced again. If there is a variable declared but not used the code goes away?

*/
int a_function();
int a_function()
{
  char* fish = "tuna";
  printf("%s\n",fish);
  return 0;
}
int main() {
    int x = 5;
    int y = x + 1;
    printf("%i\n",y);
    a_function();
    return 0;
}
