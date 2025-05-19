#include <stdio.h>
#include "simpio.h"
#include "genlib.h"
#include "string.h"
#define MAXS 100

typedef struct
{
    char name[30];
    int apousies;
}studentT;

void readInput (FILE *infile, studentT students[],int *p0ver100, int *pStudents);
void writeOutput (FILE *outfile,int size, studentT students[], int total);

/* MAIN */
int main()
{
    /* Variable Declaration */

    FILE *infile, *outfile;
    char infilename[30];
    char outfilename[30];
    int p0ver100, numstudents;
    studentT students[MAXS];

    /* Input */
    while(TRUE)
    {
        printf("Dwse onoma arxeiou eisodou: ");
        gets(infilename);
        infile = fopen(infilename, "r");
        if (infile != NULL) break;
        printf("Cannot input file %s. Please try again .\n", infilename);
    }

    printf("Dwse onoma arxeiou eksodou: ");
    gets(outfilename);
    outfile = fopen(outfilename, "w");

    /* Computation */
    readInput(infile, students, &p0ver100, &numstudents);

    /* Output */
    writeOutput(outfile, p0ver100, students, numstudents);
    fclose(infile);
    fclose(outfile);

    return 0;
}

/* FUNCTIONS */
void readInput (FILE *infile, studentT students[],int *p0ver100, int *pStudents)
{
    char name[30];
    char comments[68];
    char termch;
    int apousies;
    int nscan;
    *pStudents = 0;
    *p0ver100 = 0;

    while(TRUE)
    {
        nscan = fscanf(infile,"%30[^,], %d, %68[^\n]%c", name, &apousies, comments, &termch);
        if (nscan == EOF) break;
        if (termch != '\n' || nscan != 4)
        {
            printf("error");
            exit(1);
        }
        (*pStudents)++;
        if (apousies > 100)
        {
            students[*p0ver100].apousies = apousies;
            strcpy(students[*p0ver100].name, name);
            (*p0ver100)++;
        }
    }
}
void writeOutput (FILE *outfile,int size, studentT students[], int total)
{
    int i;
    fprintf(outfile, "%-30s%-9s\n", "ONOMATEPWNYMO","APOYSIES");
    for(i=1; i<=39; i++)
        fputc('-', outfile);
    fputc('\n', outfile);

    for (i=0; i<size; i++)
        fprintf(outfile,"%-30s%9d\n", students[i].name,students[i].apousies);
    for(i=1; i<=39; i++)
        fputc('-', outfile);
    fputc('\n', outfile);
    fprintf(outfile,"%-30s%9d\n", "SYNOLO MATHITWN:", total);
    fprintf(outfile,"%-30s%9d\n", "SYNOLO APONTWN:", size);
}
