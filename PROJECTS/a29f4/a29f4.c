#include <stdio.h>
#include "simpio.h"

int gcd (int a, int b);
bool is_coprime (int a, int b);
int phi (int number);

/* MAIN */
int main()
{
    /* Variable Declaration */
    int X,i;

    /* Input */
    printf("Enter X:");
    X = GetInteger();


    /* Output */
    i = 1;
    while (i <= X)
    {
        printf ("phi(%d) = %d\n", i, phi(i));
        i++;
    }
    return 0;
}

/* FUNCTIONS */
int gcd (int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b,a % b);
}

bool is_coprime (int a, int b)
{
    return gcd(a,b) == 1;
}

int phi (int number)
{
    int i;
    int sum;
    i = 1;
    sum = 0;
    while (i <= number)
    {
       if (is_coprime(i,number))
       {
           sum++;
           i++;
       }
       else
        i++;
    }
    return sum;
}
