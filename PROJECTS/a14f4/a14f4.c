#include <stdio.h>
#include "simpio.h"

int max (int a, int b);
int gr (int a, int b, int c);


int main()
{
    /* Variable Declaration */
    int a,b,c;
    double y;

    /* Input */
    printf("Dwse a: ");
    a = GetInteger();
    printf("Dwse b: ");
    b = GetInteger();
    printf("Dwse c: ");
    c = GetInteger();

    /* Computation */
    y = (((2 * max(a,b)) + (3 * gr(a,b,c)))/4);

    /* Output */
    printf("y = %.2f", y);

    return 0;
}


int max (int a, int b)
{
    if (a>b)
        return a;
    else
        return b;
}

int gr (int a, int b, int c)
{
    if (max(a,b) < c)
        return c;
    else if (max (a,b) > c)
        return max(a,b);
}
