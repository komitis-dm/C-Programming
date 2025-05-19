#include <stdio.h>
#include "simpio.h"
#include "math.h"

#define S 5

int main()
{
    /* Variable Declaration */
    double array [S];
    double distance [S-1];
    int i;

    /* Input */
    for (i=0; i<S; i++)
    {
        printf("Enter number (%d):", i);
        array[i] = GetReal();
    }
    /* Computation */
    for (i=0; i<S-1; i++)
    {
        distance[i] = fabs(array[i] - array[i+1]);
    }

    /* Output */
    for (i=0; i<S; i++)
    {
        printf("%.2f ", array[i]);
    }
    printf("\n");
    for (i=0; i<S-1; i++)
    {
        printf("%.2f ",distance[i]);
    }
    return 0;
}
