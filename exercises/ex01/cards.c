#include <stdio.h>
#include <stdlib.h>

int plus_or_minus (int val)
/* this function decides whether or not the card should be added or subtracted
 from the total.*/
  {
    if ((val > 2)&& (val < 7))
    {
      return 1;
    }
    else if (val == 10)
    {
      return -1;
    }
    else
    {
      return 0;
    }
  }

int switchy (char* cn)
/* this function handles all the different cases for card input */
  {
    int val = 0;
    switch(cn[0])
    {
      case 'K':
      case 'Q':
      case 'J':
        return 10;
      case 'A':
        return 11;
      default:
        val = atoi(cn);
        if ((val < 1) || (val > 10))
        {
          puts("I don't understand that value!");
          return 0;
        }
        return val;
    }
  }

void what_card()
/* generates input value */
{
  puts("Enter the card_name: ");
}

int main()
{
     char card_name[3];
     int count = 0;
     while (card_name[0] != 'X')
     {
       what_card();
       scanf("%2s", card_name);
       count += plus_or_minus(switchy(card_name));
       printf("Current count: %i\n", count);
     }
     return 0;
  }
