#include <stdio.h>
#include "simpio.h"
#include "stdlib.h"

#define NUM 50

void printArr (int A[], int n);
void populate (int A[], int n);
int checkTable (int A[], int B[], int n, int N);

/* MAIN */

int main ()
{
    /* Variable Declaration */
    int a[NUM], b[NUM], N;

    /* Input */
    populate (a, NUM);
    printArr (a, NUM);
    printf("\n--------------\n");
    printf("Dose arithmo apo to 0 ews to 9: ");
    N = GetInteger();

    /* Output */
    printf("\no Arithmos %d emfanizetai %d fores.\n", N, checkTable(a, b, NUM, N));
    printf("Stis Theseis:");
    printArr (b, checkTable(a, b, NUM, N));
    printf("\n--------------");

}


/* FUNCTIONS */

void printArr (int A[], int n)
{
    int i;
    for (i=0; i<n; i++)
        printf(" %d ", A[i]);
}

void populate (int A[], int n)
{
    int i;
    srand(time(0));
    for (i=0; i<n; i++)
        A[i] = (rand() % 10);
}

int checkTable(int A[], int B[], int n, int N)
{
    int i,j, sum;
    sum = 0;
    j = 0;
    for (i=0; i<n; i++)
    {
        if(A[i] == N)
        {
            sum ++;
            B[j] = i;
            j++;
        }
    }
    return sum;
}
