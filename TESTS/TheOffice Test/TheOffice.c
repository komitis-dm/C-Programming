#include <stdio.h>
#include "simpio.h"
#include "string.h"
//#define NUM 1//

typedef struct
{
    char FirstName[20];
    char LastName[20];
    char Rank[40];
}Office;

typedef struct
{
    int FirstName;
    int LastName;
}Spaces;

void FillOffice (int n, Office A[], Spaces B[]);
void PrintOffice (int n, Office A[], Spaces B[]);
void WriteOffice (int n, Office A[], Spaces B[]);

/* MAIN */
int main()
{
    /* Variable Declaration */
    printf("Welcome to Dunder Mifflin (Scranton, PA)\n\n");
    printf("How many members would you like to register:");

    int NUM;
    scanf("%d", &NUM);
    Office List[NUM];
    Spaces Spaces[NUM];

    /* Input */
    printf("\n");
    FillOffice(NUM,List,Spaces);

    /* Computation */
    WriteOffice(NUM,List,Spaces);

    /* Output*/
    PrintOffice(NUM,List,Spaces);
}

/* FUNCTIONS */
void FillOffice (int n, Office A[], Spaces B[])
{
    int i;
    // Used because the first "gets" is bugged and won't work//
    char str[10];
    gets(str);

    for (i=0; i<n; i++)
    {
        printf("Give the employee's First Name:");
        gets(A[i].FirstName);
        B[i].FirstName = strlen(A[i].FirstName);

        printf("Give the employee's Last Name:");
        gets(A[i].LastName);
        B[i].LastName = strlen(A[i].LastName);

        printf("Give the employee's Job Rank:");
        gets(A[i].Rank);

        printf("\n");
    }
}

void PrintOffice (int n, Office A[], Spaces B[])
{
    int i,j;

    printf("First Name:         Last Name:          Rank:\n");
    for (i=0; i<n; i++)
    {
        printf("%s", A[i].FirstName);
        for (j=0; j< (20 - (B[i].FirstName)); j++)
        {
            printf(" ");
        }
        printf("%s", A[i].LastName);
        for (j=0; j< (20 - (B[i].LastName)); j++)
        {
            printf(" ");
        }
        printf("%s", A[i].Rank);
        printf("\n");
    }
}

void WriteOffice (int n, Office A[], Spaces B[])
{
    int i,j;
    char MSG[100] = {"First Name:         Last Name:          Rank:\n"};

    FILE *pf;
    pf = fopen("Office.txt","a");
    if (pf == NULL)
        printf("Unable to open the file\n");
    else
    {
        //fputs(MSG, pf);//
        for (i=0; i<n; i++)
        {
            fputs(A[i].FirstName, pf);
            for (j=0; j< (20 - (B[i].FirstName)); j++)
            {
                fputs(" ",pf);
            }
            fputs(A[i].LastName, pf);
            for (j=0; j< (20 - (B[i].LastName)); j++)
            {
                fputs(" ",pf);
            }
            fputs(A[i].Rank, pf);
            fputs("\n",pf);
        }
    }
    fclose(pf);
}
