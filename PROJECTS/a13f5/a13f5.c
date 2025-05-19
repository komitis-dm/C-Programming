#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include "stdlib.h"

void populate_data (int r, int c, int A[r][c]);
void print_array (int r, int c, int A[r][c]);
void change_array (int r, int c, int A[r][c]);
int find_max (int i, int r, int c, int A[r][c]);

/* MAIN */

int main ()
{
    /* Variable Declaration */
    int R, C;

    /* Input */
    printf("Dwse ton arithmo twn grammwn: ");
    R = GetInteger();
    printf("Dwse ton arithmo twn sthlwn: ");
    C = GetInteger();

    int A[R][C];
    /* Output */
    populate_data (R, C, A);
    printf("ARXIKOS PINAKAS\n");
    print_array (R, C, A);
    change_array (R, C, A);
    printf("ALLAGMENOS PINAKAS\n");
    print_array (R, C, A);

    return 0;
}





/* FUNCTIONS */

void print_array (int r, int c, int A[r][c])
{   int i, j;
    for (i=0; i<r; i++)
    {
        for (j=0; j<c; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
}

void populate_data (int r, int c, int A[r][c])
{
    int i, j;
    srand(time(0));   // FOR RANDOM NUMBER BASED ON SEED OF CURRENT TIME //
    for (i=0; i<r; i++)
        for (j=0; j<c; j++)
            A[i][j] = (rand() % 100);
}

void change_array (int r, int c, int A[r][c])
{
    int i,j, max_index;
    for (i=0; i<r; i++)
    {
        max_index = find_max(i, r, c, A);
        for (j=0; j<max_index; j++)
            A[i][j] = A[i][max_index];
    }
}

int find_max (int i, int r, int c, int A[r][c])
{
    int j, max, index;
    j = 0;
    max = A[i][j];
    index = j;
    for (j=0; j<c; j++)
        if (A[i][j] > max)
        {
            max = A[i][j];
            index = j;
        }
    return index;
}
