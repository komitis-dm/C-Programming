#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include "math.h"
#define rate 0.07
#define init_cars 80000
#define limit 160000


int main()
{
/* Variable Declaration */
long years, cars;

/* Input */
years = 0;
cars = init_cars;

/* Computation */
while (cars <= limit)
{
    cars = ceil(cars * (1 + rate));
    years++;
}

/* Output */
printf ("%ld\n%ld", years,cars);

}
