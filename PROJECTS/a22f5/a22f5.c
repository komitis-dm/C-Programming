#include <stdio.h>
#include "simpio.h"
#include "math.h"

#define S 16

long long GetLongLong(void);

/* MAIN */

int main()
{
    /* Variable Declaration */
    long long number, num, temp, sum, T[S];
    int i;

    /* Input */
    printf("Insert card number:");
    number = GetLongLong();

    /* Computation */
    num = number;
    for (i=S-1; i>=0; i--)
    {
        T[i] = num % 10;
        num /= 10;
    }
                                /* Digit Size Check */
    if (num != 0)
    {
        printf("%lld is INVALID.", number);
        return 0;
    }
                                /* First Number Check */
    if (T[0]<4 || T[0]>7)
    {
        printf("%lld is INVALID.", number);
        return 0;
    }

                                /* Multiply every other digit with 2 */
    for (i=0; i<S; i=i+2)
    {
        T[i] = T[i] * 2;
        if (T[i] % 10 != 0);
        {
            temp = T[i] % 10;
            T[i] /= 10;
            T[i] = T[i] + temp;
        }
    }
                                /* Find Sum of all Digits */
    sum = 0;
    for (i=0; i<S; i++)
        sum += T[i];

    /* Output */
                                /* Check Sum of all Digits */
    if (sum % 10 == 0)
        printf("%lld is VALID.", number);
    else
        printf("%lld is INVALID.", number);

    return 0;
}


/* FUNCTIONS */

long long GetLongLong(void)
{
    string line;
    long long value;
    char termch;

    while (TRUE) {
        line = GetLine();
        switch (sscanf(line, " %lld %c", &value, &termch))
        {
          case 1:
            FreeBlock(line);
            return (value);
          case 2:
            printf("Unexpected character: '%c'\n", termch);
            break;
          default:
            printf("Please enter an integer\n");
            break;
        }
        FreeBlock(line);
        printf("Retry: ");
    }
}
