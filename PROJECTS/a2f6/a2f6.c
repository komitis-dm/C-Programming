#include <stdio.h>
#include "simpio.h"

#define S 100

int readArray(int A[], int SIZE, int *max, int *min);
void MaxMin (int number, int *max, int *min);

// MAIN //
int main()
{
    // Variable Declaration //
    int A[S], max, min, sum;

    // Input //
    printf("Enter the elements of the array, one per line.\n");
    printf("Use -1 to signal the end of the list.\n");

    // Computation //
    sum = readArray(A, S, &max, &min);

    // Output //
    printf("The range of values is %d-%d", min, max);

    return 0;
}


// FUNCTIONS //

int readArray(int A[], int SIZE, int *max, int *min)
{
    int i, sum;
    i = 0;
    sum = 0;
    printf("? ");
    A[i] = GetInteger();
    if (A[i] != -1)
    {
        sum++;
        *max = A[i];
        *min = A[i];
    }

    for (i=1; i<SIZE; i++)
    {
        printf("? ");
        A[i] = GetInteger();
        if (A[i] != -1)
        {
            sum++;
            MaxMin (A[i], max, min);
        }
        else
            break;
    }
    return sum;
}

void MaxMin (int number, int *max, int *min)
{
    if (number> *max)
        *max = number;
    else if (number< *min)
        *min = number;
}
