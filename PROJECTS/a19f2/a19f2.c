#include <stdio.h>
#include "simpio.h"

int main()
{

/* Variable Declaration */

int grams;
float fee;

/* Input */

printf("Dwse gram CO2/khm:");
grams = GetInteger();

/* Computation */

if ((grams >= 0) && (grams <= 120))
{
    fee = (float)grams * 0.9;
    printf("To poso pliromis einai: %.1f\n",fee);
    return 0;
}
else if ((grams >= 121) && (grams <= 140))
{
    fee = (float)grams * 1.1;
    printf("To poso pliromis einai: %.1f\n",fee);
    return 0;
}
else if (grams > 140)
{
    fee = (float)grams * 1.7;
    printf("To poso pliromis einai: %.1f\n",fee);
    return 0;
}






return 0;
}
