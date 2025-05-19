#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

bool IsArmstrong (int x);
int Sum_Cube (int x);
int cube (int x);

int main ()
{

/* Variable Declaration */
int i;

/* Output */
for (i = 1; i <= 999; i ++)
    {
      if (IsArmstrong(i)) printf ("%d\n", i);
    }

system ("PAUSE");
return 0;

}


/* Functions */
bool IsArmstrong (int x)
{
    return Sum_Cube(x) == x;
}

int Sum_Cube (int x)
{
    int dig1, dig2 ,dig3;
    dig1 = x % 10;
    dig2 = (x % 100) / 10;
    dig3 = x / 100;

    return cube(dig1) + cube(dig2) + cube(dig3);
}

int cube (int x)
{
    int prod, i;
    prod = 1;
    for (i = 0; i < 3; i++)
    {
        prod = prod * x;
    }
    return prod;
}
