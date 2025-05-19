#include <stdio.h>
#include "simpio.h"

typedef struct
{
    int width;
    int height;
    int depth;
    int area;
    int volume;
} box;
void GetDim(box *T);
void CalcArea(box *T);
void CalcVolume(box *T);

/* MAIN */
int main()
{
    /* Variable Declaration */
    box XBOX;

    /* Input */
    GetDim(&XBOX);

    /* Computation */
    CalcArea(&XBOX);
    CalcVolume(&XBOX);

    /* Output */
    printf("To emvadon tou koutiou einai %d cm2\n", XBOX.area);
    printf("O ogos tou koutiou einai %d cm3\n", XBOX.volume);

return 0;
}

/* FUNCTIONS */
void GetDim(box *T)
{
    printf("Dose to mikos tou koutiou se cm: ");
    T->width = GetInteger();
    printf("Dose to ypsos tou koutiou se cm: ");
    T->height = GetInteger();
    printf("Dose to vathos tou koutiou se cm: ");
    T->depth = GetInteger();
}
void CalcArea(box *T)
{
    T->area = 2 * (T->width * T->height)
            + 2 * (T->height * T->depth)
            + 2 * (T->depth * T->width);
}
void CalcVolume(box *T)
{
    T->volume = T->width * T->height * T->depth;
}
