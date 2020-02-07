/*



*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_NUM_INTS 13
#define BUFFER_SIZE 128


int check_number(char *input)
{
  // checks the number to make sure its a int.
  // returns 0 for a good int.
  // returns 0 for a bad entry
  char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  if (atoi(input) != 0)
  {
    // checking to see if atoi does not have errors.
    return 0;
  }
  else if (atoi(input)==0 && (input == "0"))
  {
    // checking whether the number is actually 0
    return 0;
  }
  else if (strspn(input,alphabet)>0)
  {
    printf("I am very dissapointed in you. Letters cannot be added together. Please try again. \n");
    // there are letters in the input
    return 1;
  }
  else if (strsp(input,".")>0)
  {
    // you probably gave me a float
    printf("\nIs this a float? Were you even listening to me? I told you to give me INTEGERS. INTEGERS you fool are WHOLE NUMBERS.\n");
    return 1;
  }
  else
  {
    printf("\nI dont know what to say except... \n ... \n...\n...\n WRONG INPUT. I ADD NUMBERS NOT WHATEVER THIS IS.\n");
    return 1;
  }
}

int sum_num(int num_num, int* array)
{
  // sums all the numbers in the 13 long array.
  int sum = 0;
  int *s = &sum;
  for (int i =0; i < num_num;i++)
  {
    *s = sum + array[i];
  }
  return sum;
}

int main()
{
  int num_nums = 0; // number of numbers
  int *num_nums_p = &num_nums; //pointer for num nums.
  char name[20];
  char answer[20];
  char current_val[BUFFER_SIZE];

  int numbers[MAX_NUM_INTS];
  int *nums = numbers;



  // beginning of game interface.
  printf("Hello. What is your name?\n");
  fgets(name,20,stdin);
  printf("\nNice to meet you %s I am Adder. Would you like to play a game?\n",name);
  fgets(answer,20,stdin);
  printf("\nWell. I dont really care what you want.\n I am an Adder. Type in up to %d integers one at a time, push Control-D when you are done.\n \n And I will (gasp) add them together.\n\n",MAX_NUM_INTS);
  while(num_nums < MAX_NUM_INTS && current_val != "d")
  {
    fgets(current_val, BUFFER_SIZE,stdin);
    while( check_number(current_val)!=0 && current_val != "stahp")
    {
      printf("\nTry Again.\n");
      fgets(current_val,BUFFER_SIZE,stdin);
    }
    nums[num_nums]= atoi(current_val);
    *num_nums_p= num_nums+1;
  }
  if (num_nums==(MAX_NUM_INTS-1))
  {
    printf("\nI only take %d integers. Remember?\n",MAX_NUM_INTS);
  }
  printf("\nAnyway... all those numbers added together equal....\n drumroll please \n %d \n Your Welcome.\n Bye Bye \n", sum_num(num_nums,nums));

}
