#include <stdio.h>
#include "simpio.h"
#include "string.h"

typedef struct
{
	char Name[60];
	int Month;
	int Duration;
} WPStruct;
void ReadWorkpackages(int n,WPStruct WP[]);
void FindFirstWp(int n, WPStruct WP[], WPStruct FirstWP[], int *min_index);
int FindMakespan(int n, WPStruct WP[]);

/* MAIN */
int main()
{
    /* Variable Declaration */
    int n, i, min_index, makespan;
    WPStruct WP[100], FirstWP[100];

    /* Input */
    printf("Total work packages: ");
    n = GetInteger();

    ReadWorkpackages(n, WP);

    /* Computation */
    FindFirstWp(n,WP,FirstWP,&min_index);
    makespan = FindMakespan(n,WP);

    /* Output */
    if (min_index > 1)                                /* Case of >1 WPs starting together */
    for (i=0; i<min_index; i++)
    {
        printf("FIRST WP: %s start: %d duration: %d\n", FirstWP[i].Name,
                                                        FirstWP[i].Month,
                                                        FirstWP[i].Duration);
    }
    else                                              /* Case of just 1 WP */
    printf("FIRST WP: %s start: %d duration: %d\n", FirstWP[0].Name,
                                                    FirstWP[0].Month,
                                                    FirstWP[0].Duration);

    printf("Total duration = %d\n", makespan);

    return 0;
}

/* FUNCTIONS */
void ReadWorkpackages(int n, WPStruct WP[])
{
    int i;
	for (i=0; i<n; i++)
	{
		printf("WP Name:");
		gets(WP[i].Name);
		printf("WP Month:");
		WP[i].Month = GetInteger();
		printf("WP Duration:");
		WP[i].Duration = GetInteger();
	}
}
void FindFirstWp(int n, WPStruct WP[], WPStruct FirstWP[], int *min_index)
{
	int i;
    strcpy ((FirstWP[0].Name), (WP[0].Name));
    FirstWP[0].Month = WP[0].Month;
    FirstWP[0].Duration = WP[0].Duration;
	for (i=1; i<n; i++)
	{
		if (WP[i].Month == FirstWP[0].Month)
		{
			FirstWP[*min_index] = WP[i];
			(*min_index)++;
		}
		else if (WP[i].Month < FirstWP[0].Month)
		{
			strcpy (FirstWP[0].Name, WP[i].Name);
			FirstWP[0].Month = WP[i].Month;
			FirstWP[0].Duration = WP[i].Duration;
			*min_index = 1;
		}
	}
}
int FindMakespan(int n, WPStruct WP[])
{
	int makespan;
	int i;
	makespan = (WP[0].Duration + WP[0].Month);
	for (i=1; i<n; i++)
	{
		if ((WP[i].Duration + WP[i].Month) > makespan)
		{
			makespan = (WP[i].Duration + WP[i].Month);
		}
	}
	return makespan;
}
