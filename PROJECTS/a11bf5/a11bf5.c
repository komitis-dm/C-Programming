#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"

/* CHANGE BEFORE SUBMITΙΝG (CTS = 10, S = 3) */
#define CTS 10
#define S 3

void ReadData (int r, int c, double temper[r][c]);
double CalculateAverage (int r, int c, double temper[r][c]);
void CalculateAvCity (int r, int c, double temper[r][c], double average []);
void CalculateMaxDeviation (int r, int c, double temper[r][c], double natavg, double mdeviation[]);
void PrintResults (int r, double natavg, double average[], double mdeviation[]);

/* MAIN */

int main()
{
    double temper[CTS][S];
    double average[CTS], mdeviation[CTS];
    double natavg;


    ReadData(CTS, S, temper);
    natavg = CalculateAverage(CTS, S, temper);
    CalculateAvCity (CTS, S, temper, average);
    CalculateMaxDeviation (CTS, S, temper, natavg, mdeviation);
    PrintResults (CTS, natavg, average, mdeviation);

    return 0;
}

/* FUNCTIONS */

void ReadData(int r, int c, double temper[r][c])
{
	int i,j;

    /*Read all Temperatures*/
	for (i=0; i<r; i++)
		for (j=0; j<c; j++)
		  	{ printf("Temp of City %d During %d 8-hour period: ",i,j);
              temper[i][j] = GetReal();
              }
}

double CalculateAverage(int r, int c, double temper[r][c])
{
    int i,j;
    double natavg;

    /*Calculating The Average of all Cities&Temps*/
    natavg = 0;
    for (i=0; i<r; i++)
      for (j=0; j<c; j+=1)
         natavg += temper[i][j];
    natavg = natavg/(r*c);
    return natavg;
}

void CalculateAvCity (int r, int c, double temper[r][c], double average [])
{
    int i,j;

    /*Calculating Average temp on each City*/
	for (i=0; i<r; i++)
    {
        average[i] = 0;
        for (j=0; j<c; j++)
        {
            average[i] += temper[i][j];
        }
        average[i] = average[i]/c;
    }

}

void CalculateMaxDeviation (int r, int c, double temper[r][c], double natavg, double mdeviation[])
{
    int i,j;
    double devnat[r][c]; // C99 (Dynamic Matrix)
    /*Calculating Standard Deviation*/
    for (i=0; i<r; i++)
        for (j=0; j<c; j++)
            devnat[i][j] = fabs(natavg - temper[i][j]);

	/*Calculating max Deviation*/
    for (i=0; i<r; i++)
    {
        mdeviation[i] = devnat[i][0];
        for(j=1; j<c; j++)
            if (mdeviation[i]<devnat[i][j]) mdeviation[i] = devnat[i][j];
    }
}

void PrintResults (int r, double natavg, double average[], double mdeviation[])
{
    int i;
    /*Printing results*/
    printf("%3.1f\n", natavg);
    for (i=0; i<CTS; i+=1)
		printf("City %d  %.1f  %.1f\n",i, average[i], mdeviation[i]);
    system("PAUSE");
}
