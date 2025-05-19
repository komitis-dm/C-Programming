#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int main()
{

/* Variable Declaration */
int init_age, age, oldest, youngest;


/* Input */

printf("Dwse ilikia: ");
init_age = GetInteger();

oldest = init_age;
youngest = init_age;

printf("Dwse ilikia: ");
age = GetInteger();

/* Computation */
while (age != -1)
{
    if (age > oldest)
    {
        oldest = age;
    }
    else if (age < youngest)
    {
        youngest = age;
    }
    printf("Dwse ilikia: ");
    age = GetInteger ();
}

/* Output */
printf("H megalyteri ilikia einai %d\n", oldest);
printf("H mikroteri ilikia einai %d", youngest);

return 0;
}
