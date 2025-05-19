#include <stdio.h>
#include "simpio.h"

int f (int x);
int g (int x, int y);


/* MAIN */

int main()
{
    /* Variable Declaration */
    int x,y;

    /* Input */
    printf ("Enter x: ");
    x = GetInteger();
    printf ("Enter y: ");
    y = GetInteger();

    /* Output */
    printf ("f(x) = f(%d) = %d\n", x, f(x));
    printf ("g(x,y) = g(%d,%d) = %d\n", x, y, g(x,y));
    printf ("f(g(x,y)) = f(g(%d,%d) = %d\n", x, y, f(g(x,y)));

    return 0;
}


/* FUNCTIONS */

int f (int x)
{
    int result;
    if (x>0)
    {
        result = x + 2;
        return result;
    }
    else if (x<=0)
    {
        result = (-3 * x) +7;
        return result;
    }
}


int g (int x, int y)
{
    int result;
    if (x>0 && y>0)
    {
        result = x - y;
        return result;
    }
    else
    {
        result = (7 * x) - 5;
        return result;
    }
}
