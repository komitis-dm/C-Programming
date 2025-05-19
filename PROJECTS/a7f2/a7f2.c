#include <stdio.h>
#include "simpio.h"

int main(){

/* Variable Declaration */
int hours;
long code;
double salary, wage, weekly_rate;

/* Input-Copmutation */
printf("Dwse ton kwdiko:");
code = GetLong();

if (code >= 1000)
{
    printf("Dwse ton ethsio mistho:");
    salary = GetReal();
    weekly_rate = salary/52.0;
}
else
{
    printf("Dwse tis wres ebdomadiaias ergasias:");
    hours = GetInteger();
    printf ("Dwse thn amoibh ana wra:");
    wage = GetReal ();
    if (hours <= 40)
        {
         weekly_rate = hours * wage;
        }
    else weekly_rate = 40*wage + (hours - 40) * wage * 1.5;
}

/* Output */
printf ("H ebdomadiaia amoibh einai %g\n", weekly_rate);

return 0;

}
