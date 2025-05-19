#include <stdio.h>
#include "simpio.h"

long encode (long N);
bool check (long EN);

/* MAIN */

int main()
{
    /* Variable Declaration */

    long N, EN, upper_lim, lower_lim;

    /* Input */

    printf("Lower Limit:");
    lower_lim = GetLong();
    printf ("Upper Limit:");
    upper_lim = GetLong();

    /* Output */

    N = lower_lim;

    while (N <= upper_lim)
    {
        EN = encode(N);
        printf("Code: %ld Encoding: %ld isValid:", N, EN);
        if (check(EN))
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n2");
        }
        N++;
    }

    return 0;
}




/* FUNCTIONS */

long encode (long N)
{
    int digits, EN;
    digits = (98 - (N * 100) % 97) % 97;
    EN = (N * 100) + digits;
    return EN;
}

bool check (long EN)
{
    return (EN % 97 ==1);
}
