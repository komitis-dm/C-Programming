#include <stdio.h>
#include "simpio.h"
#include "math.h"

#define CTS 10
#define S 3

/* MAIN */

int main()
{
    /* Variable Declaration */
    double temper [CTS][S];
    double devnat [CTS][S];
    double average [CTS];
    double mdeviation[CTS];
    double natavg;
    int i, j;

    /* Input */
    for (i=0; i<CTS; i++)
    {
        for (j=0; j<S; j++)
        {
            printf("Temp of City %d During %d 8-hour period: ",i ,j);
            temper[i][j] = GetReal();
        }
    }

    /* Computation */

    /* National Average */
    natavg = 0;
     for (i=0; i<CTS; i++)
    {
        for (j=0; j<S; j++)
        {
            natavg = natavg + temper[i][j];
        }
    }
    natavg = natavg / (CTS * S);

    /* City Average */
     for (i=0; i<CTS; i++)
    {
        average[i] = 0;
        for (j=0; j<S; j++)
        {
            average[i] += temper [i][j];
        }
        average [i] = average [i]/S;
    }

    /* Deviation of each "8-Hour" from National Average */
    for (i=0; i<CTS; i++)
    {
        for (j=0; j<S; j++)
        {
            devnat[i][j] = fabs(natavg - temper[i][j]);
        }
    }

    /* Max Deviation of a city's "8-Hour" from National Average */
    for (i=0; i<CTS; i++)
    {
        mdeviation[i] = devnat[i][0];
        for(j=1; j<S; j++)
        {
            if (mdeviation[i] < devnat[i][j])
                mdeviation[i] = devnat[i][j];
        }
    }


    /* Output */
    printf("%0.1f\n", natavg);
    for (i=0; i<CTS; i++)
    {
        printf("City %d  %.1f  %.1f\n",i , average[i], mdeviation[i]);
    }

    return 0;
}

