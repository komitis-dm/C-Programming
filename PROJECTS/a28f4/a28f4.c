#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

int get_code();
double discount_precentage (int code);
int product_points(int code, double fprice);

/* MAIN */

int main()
{
    /* Variable Declaration */
    int code, points;
    double price, finalPrice, discount, total, discountSum;
    total = discountSum = 0;
    points = 0;
    while ((code = get_code()))
    {
    /* Input */
    printf("Dwse thn timh: ");
    price = GetReal();

    /*Computation*/
    discount = discount_precentage(code) * price;
    discountSum += discount;
    finalPrice = price - discount;
    total += finalPrice;
    points += product_points(code,finalPrice);
    }

    /*Output */
    printf("------------------\n");
    printf("Teliko synolo: %.2f Euro\n", total);
    printf("Ekptwsh: %.2f Euro\n",discountSum);
    printf ("Pontoi: %d\n", points);

    return 0;
}



/* FUNCTIONS */

int get_code()
{
    int code;

    while(TRUE)  /*while(TRUE) Means this Loop runs forever until stopped */
    {
        printf("Dwse ton kwdiko: ");
        code = GetInteger ();
        if (code>= 0 && code<= 2000)
        {
            return code;
        }
        else printf ("Lathos Kwdikos (0-2000) \n");
    }
}

double discount_precentage(int code)
{
    if (code<= 300) return 0.05;
    if (code<= 500) return 0.10;
    if (code<= 1000) return 0.15;
    else return 0.20;
}

int product_points(int code, double fprice)
{
    int points = 1;
    if (code>= 1000 && code<=1500)
        points += ceil(fprice/5);
    return points;
}
