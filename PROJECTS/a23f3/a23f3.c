#include <simpio.h>
#include "stdio.h"

int main()
{
/* Variable Declaration */
int number, new_number, x;

/* Input */
printf ("Enter number: ");
number = GetInteger();

/* Computation / Output */
x = number % 2;
if (x == 0)
{
  new_number = 0;
  while (new_number <= number)
  {
      printf ("%d ", new_number);
      new_number = new_number + 2;
  }
}
else
{
  new_number = 1;
  while (new_number <= number)
  {
      printf ("%d ", new_number);
      new_number = new_number +2;
  }
}
return 0;
}





