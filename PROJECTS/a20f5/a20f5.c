#include <stdio.h>
#include "simpio.h"

#define S 5

int main()
{
    /* Variable Declaration*/
    int i;
    int matrix[S];
    int M2[S];

    /* Input */
    for (i=0; i<S; i++)
    {
    printf("Enter number: ");
    matrix[i] = M2[i] = GetInteger();
    }

    /* Computation */
    M2[0] = matrix [S-1];
    for (i=1; i<S; i++)
    {
        M2[i] = matrix[i-1];
    }

    for (i=0; i<S; i++)
    {
        printf("%d ", M2[i]);
    }

    return 0;
}

