#include <stdio.h>
#include "simpio.h"

#define BANDS 3
#define LETTERS 25
#define HOURS 6

void FillArrayZero (int x, int T[]);                 /* Sets all the values of a One-Dimensional Array = 0 */
void FillMatrixZero (int x, int y, float T[x][y]);   /* Sets all the values of a Two-Dimensional Array = 0 */
void FindMax(int x, int T[], int index[], int Max[], int *tie);

/* MAIN */
int main()
{
    /* Variable Declaration */
    char* Bands[BANDS] = {"Accept","Anthrax","Black Sabbath","Dio","Helloween","Iron Maiden",
    "Judas Priest","Manowar","Megadeth","Metallica","Motley Crue","Nazareth","Ozzy Osborne","Pantera",
    "Queensryche","Rammstein","Raven","Sabaton","Saxon","Scorpions","Sepultura","Slayer","W.A.S.P."};
    char * BandsHere[HOURS][BANDS];
    int i,j, tie, index[HOURS], Max[HOURS],IsHere[HOURS];
    float TimesHere[BANDS][2];

    FillArrayZero(HOURS,IsHere);       /* IsHere = 0 */
    FillArrayZero(HOURS,index);
    FillArrayZero(HOURS,Max);
    FillMatrixZero(BANDS,2,TimesHere);  /* TimesHere = 0 */

    for (i=0; i<BANDS; i++)
    {
        printf("%s\n", Bands[i]);
    }
        for (i=0; i<BANDS; i++)
        {
            j = 0;
            printf("Arrival Time (18.00 - 23.00): ");
            TimesHere[i][j] = GetReal();
            if (TimesHere[i][j] == 18.00)
            {
                IsHere[1]++, IsHere[2]++, IsHere[3]++, IsHere[4]++, IsHere[5]++, IsHere[6]++;
                BandsHere[1][1]=Bands[i],BandsHere[2][2]=Bands[i],BandsHere[3][3]=Bands[i],
                BandsHere[4][4]=Bands[i],BandsHere[5][5]=Bands[i],BandsHere[6][6]=Bands[i];
            }
            else if (TimesHere[i][j] == 19.00)
            {
                IsHere[2]++, IsHere[3]++, IsHere[4]++, IsHere[5]++, IsHere[6]++;
                BandsHere[2][2]=Bands[i],BandsHere[3][3]=Bands[i],BandsHere[4][4]=Bands[i],
                BandsHere[5][5]=Bands[i],BandsHere[6][6]=Bands[i];
            }
            else if (TimesHere[i][j] == 20.00)
            {
                IsHere[3]++, IsHere[4]++, IsHere[5]++, IsHere[6]++;
                BandsHere[3][3]=Bands[i],BandsHere[4][4]=Bands[i],BandsHere[5][5]=Bands[i],
                BandsHere[6][6]=Bands[i];
            }
            else if (TimesHere[i][j] == 21.00)
            {
                IsHere[4]++, IsHere[5]++, IsHere[6]++;
                BandsHere[4][4]=Bands[i],BandsHere[5][5]=Bands[i],BandsHere[6][6]=Bands[i];
            }
            else if (TimesHere[i][j] == 22.00)
            {
                IsHere[5]++, IsHere[6]++;
                BandsHere[5][5]=Bands[i],BandsHere[6][6]=Bands[i];

            }
            else if (TimesHere[i][j] == 23.00)
            {
                IsHere[6]++;
                BandsHere[6][6]=Bands[i];
            }

            j++;
            printf("Departure Time (19.00 - 24.00): ");
            TimesHere[i][j] = GetReal();
            if (TimesHere[i][j] == 19.00)
            {
                IsHere[2]--, IsHere[3]--, IsHere[4]--, IsHere[5]--, IsHere[6]--;
                BandsHere[2][2]=0,BandsHere[3][3]=0,BandsHere[4][4]=0,BandsHere[5][5]=0,BandsHere[6][6]=0;
            }
            if (TimesHere[i][j] == 20.00)
            {
                IsHere[3]--, IsHere[4]--, IsHere[5]--, IsHere[6]--;
                BandsHere[3][3]=0,BandsHere[4][4]=0,BandsHere[5][5]=0,BandsHere[6][6]=0;
            }
            if (TimesHere[i][j] == 21.00)
            {
                IsHere[4]--, IsHere[5]--, IsHere[6]--;
                BandsHere[4][4]=0,BandsHere[5][5]=0,BandsHere[6][6]=0;
            }
            if (TimesHere[i][j] == 22.00)
            {
                IsHere[5]--, IsHere[6]--;
                BandsHere[5][5]=0,BandsHere[6][6]=0;
            }
            if (TimesHere[i][j] == 23.00)
            {
                IsHere[6]--;
                BandsHere[6][6]=0;
            }
        }
        FindMax(HOURS,IsHere,index,Max,&tie);
        if (tie != 0)
            for (i=0; i<=tie; i++)
            {
                for (j=0; j<6; j++)
                {
                    printf("%s ", BandsHere[index[i]][Max[i]]);
                }
                printf("\n");
            }
        else
            printf("%d", Max[0]);

    return 0;
}

/* FUNCTIONS */
void FillArrayZero (int x, int T[])
{
    int i;
    for (i=0; i<x; i++)
            T[i] = 0;
}
void FillMatrixZero (int x, int y, float T[x][y])
{
    int i,j;
    for (i=0; i<x; i++)
        for (j=0; j<y; j++)
            T[i][j] = 0;
}

void FindMax(int x, int T[], int index[], int Max[], int *tie)
{
    int i;
    i = 0;
    index = 0;
    Max = 0;
    *tie = 0;
    Max[i] = T[i];
    for (i=1; i<x; i++)
        if (T[i] > Max[i])
        {
            Max[i] = T[i];
            index[i] = i;
        }
        else if(T[i] == Max[i])
        {
            Max[i+1] = Max[i];
            index[i+1] = i;
            *tie = *tie+1;
        }
}
