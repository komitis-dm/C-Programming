#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main()
{
/* Variable Declaration */

int number;

/* Input */

printf("Dwse enan arithmo apo to 1 eos to 7: ");
number = GetInteger();

/* Computation-Output */

if ((number > 7) || (number <= 0))
{
    printf("ERROR");
    return 0;
}
else
{
    switch (number)
    {
    case 1:
        printf ("The day is Monday");
        break;
    case 2:
         printf ("The day is Tuesday");
         break;
    case 3:
         printf ("The day is Wednesday");
         break;
    case 4:
         printf ("The day is Thursday");
         break;
    case 5:
         printf ("The day is Friday");
         break;
    case 6:
         printf ("The day is Saturday");
         break;
    case 7:
         printf ("The day is Sunday");
         break;
    }
}
return 0;
}
