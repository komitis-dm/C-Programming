#include <stdio.h>
#include "simpio.h"

int main(){

/* Variable Declaration */

int coffees, change;

/* Input */

printf("Dwse kafedes:");
coffees = GetInteger();

/* Computation */

if (coffees* 70 > 500)
{
    printf ("Den ftanoun ta xrhmata gia tosous kafedes");
    return 0;
}
else
{
    change =  500 - (coffees * 70);

    printf("Resta\n");
    printf("Kermata 2E: %d\n", (change) / 200);
    printf("Kermata 1E: %d\n", ((change) % 200) / 100);
    printf("Kermata 50L: %d\n",((((change) % 200)) % 100) / 50);
    printf("Kermata 20L: %d\n",(((((change) % 200)) % 100) % 50) / 20);
    printf("Kermata 10L: %d\n",((((((change) % 200)) % 100) % 50) % 20) / 10);

}
return 0;
}

