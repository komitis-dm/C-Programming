#include <simpio.h>
#include "stdio.h"
#include "genlib.h"
#include "math.h"

int main()
{
/* Variable Declaration */
long init_cars;
double rate;
long limit, cars, years;

/* Input */
printf("Dwse ton arxiko arithmo autokinhtwn:");
init_cars = GetLong();

printf("Dwse ton ethsio rythmo ayxhshs:");
rate = GetReal();

printf ("Dwse to orio:");
limit = GetLong ();

cars = init_cars;
years = 0;

/* Computation */
while (cars <= limit)
{
    cars = ceil(cars * (1 +rate));
    years++;
}
/* Output */
printf ("After %ld years the number of Cars is %ld.\n", years, cars);

return 0;

}
