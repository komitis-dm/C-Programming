#include <stdio.h>
#include "simpio.h"
#include "ctype.h"
#include "string.h"

#define N 100

/* MAIN */
int main()
{
    /* Variable Declaration */
    char str[N];
    int i, j, sum, digits;

    /* Input */
    printf("Insert a string: ");
    gets(str);

    /* Computation */
    char D [strlen(str)];
    j=0;
    sum = 0;
    digits = 0;
    D[j] = -1;

    for (i=0; str[i] != '\0'; i++)
    {
        if (isdigit(str[i]) == 1)
        {
            D[j] = str[i];
            j++;
            digits++;
            sum = sum + (str[i] - '0');   /* Converting "Char" to an integer */
        }
    }

    /* Output */
    if (D[0] == -1)
        printf("No digits in input.");
    else
    {
        printf("%c ", D[0]);
        if (digits > 1)
        {
            for (i=1; i<digits; i++)
                printf("+ %c ", D[i]);
            printf("= %d", sum);
        }
        else
            printf("= %d", sum);
    }
    return 0;
}
