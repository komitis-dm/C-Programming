#include <stdio.h>
#include "simpio.h"
#include "string.h"

#define RENTS 20
typedef struct
{
    int number;
    char type[20];
    int cc;
    char name[20];
    int days;
    float daily_rate;
    float total_charge;
} car_rentalT;
typedef struct
{
    int cc;
    char type[20];
    float amount;

} best_carT;

int get_data(car_rentalT rentals[]);
float calc_totals(int num_rentals, car_rentalT rentals[]);
best_carT find_best(int num_rentals, car_rentalT rentals[]);
void print_data(int num_rentals, car_rentalT rentals[], float total, best_carT best);

/* MAIN */
int main()
{
    /* Variable Declaration */
    car_rentalT rentals[RENTS];
    best_carT best;
    int num_rentals;
    float total;

    num_rentals = get_data(rentals);
    total = calc_totals( num_rentals, rentals);
    best = find_best(num_rentals, rentals);

    print_data(num_rentals, rentals, total, best);

    return 0;
}

/* FUNCTIONS */
int get_data(car_rentalT rentals[])
{
    int num_rentals, i;
    printf("Dose ton arithmo ton enoikiaseon: ");
    num_rentals = GetInteger();
    for (i=0; i<num_rentals; i++)
    {
        printf("\nDose ta stioxeia tis enoikiasis %d\n",i);

        rentals[i].number = i;

        printf("Dose marka: ");
        gets(rentals[i].type);

        printf("Dose kyvika: ");
        rentals[i].cc = GetInteger();

        printf("Dose onoma pelati: ");
        gets(rentals[i].name);

        printf("Dose imeres enoikiasis: ");
        rentals[i].days = GetInteger();

        printf("Dose timi ana imera: ");
        rentals[i].daily_rate = GetReal();

        rentals[i].total_charge = rentals[i].days * rentals[i].daily_rate;
    }
    return num_rentals;
}
float calc_totals(int num_rentals, car_rentalT rentals[])
{
    int i;
    float total = 0;

    for (i=0; i<num_rentals; i++)
    {
        rentals[i].total_charge = rentals[i].days * rentals[i].daily_rate;
        total += rentals[i].total_charge;
    }
    return total;
}
best_carT find_best(int num_rentals, car_rentalT rentals[])
{
    int i;
    best_carT best;

    strcpy(best.type, rentals[0].type);
    best.cc = rentals[0].cc;
    best.amount = rentals[0].total_charge;

    for(i=1; i<num_rentals; i++)
    {
        if (best.amount < rentals[i].total_charge)
        {
            strcpy(best.type, rentals[i].type);
            best.amount = rentals[i].total_charge;
            best.cc = rentals[i].cc;
        }
    }
    return best;
}
void print_data(int num_rentals, car_rentalT rentals[], float total, best_carT best)
{
    int i;
    printf("\n\n");
    printf("%-7s %-20s %-10s %-5s %-5s %-6s %-8s\n",
           "Number", "Name","Type","CC","Days","Price","Total");
    for (i=0; i<73; i++)printf("-");
    printf("\n");

    for (i=0; i<num_rentals; i++)
    {
        printf("%-7d %-20s %-10s %-5d %-5d %-6.2f %-8.2f\n",
           rentals[i].number,
           rentals[i].name,
           rentals[i].type,
           rentals[i].cc,
           rentals[i].days,
           rentals[i].daily_rate,
           rentals[i].total_charge);
    }

    for (i=0; i<73; i++)printf("-");
    printf("\n");
    printf("%58s %-8.2f\n","Total",total);
    printf("Best car: %s %d rented for %.2f Euros.\n",best.type, best.cc, best.amount);
}
