#include <simpio.h>
#include "stdio.h"
#include "genlib.h"

int main()
{
    /* Variable Declaration */
    int limit,denominator;
    float sum;

    /* Input */
    printf("Dwse orio: ");
    limit = GetInteger();

    denominator = 1;
    sum = 0;

    /* Computation */
    do
    {
        sum = sum + (1.00/denominator);
        denominator++;
    } while (denominator <= limit);

    /* Output */
    printf("To athroisma einai: %.2f", sum);

    return 0;
}
