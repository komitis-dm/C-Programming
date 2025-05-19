#include <stdio.h>
#include "simpio.h"
#include "string.h"

#define OriginalMembers 14
#define NumSalesmen 5
#define NumCEOs 3

typedef struct
{
    char Name[30];
    char Title[100];
}OfficeWorkers;

void PrintWorkers (OfficeWorkers People[], int n);

int main()
{
    /* Variable Declaration */
    int Number;
    OfficeWorkers OriginalCast[OriginalMembers] = {
                                                "Michael Scott", "Manager",
                                                "Pam Beasly", "Secretary",
                                                "Jim Halpert", "Salesman",
                                                "Dwight Schrute","Salesman/Assistant to the Regional Manager",
                                                "Stanley Hudson", "Salesman",
                                                "Phyllis Vance", "Salesman",
                                                "Oscar Martniez", "Lead Accountant",
                                                "Angela Martin", "Lead Accountant",
                                                "Kevin Malone", "Accountant",
                                                "Creed Bratton", "Quality Control",
                                                "Meredith Palmer", "Supplier Relations",
                                                "Toby Flenderson", "Human Resources",
                                                "Kelly Kapoor", "Customer Relations",
                                                "Ryan Howard", "Temp",
                                                };
    OfficeWorkers Salesmen[] = {
                                "Jim Halpert", "Salesman",
                                "Dwight Schrute","Salesman/Assistant to the Regional Manager",
                                "Stanley Hudson", "Salesman",
                                "Phyllis Vance", "Salesman",
                                "Andy Bernard", "Salesman"
                                };
    OfficeWorkers CEOs[] = {
                            "David Wallace", "CEO - Dunder Miflin",
                            "Robert California", "CEO - Sabre",
                            "Jo Bennett", "Former CEO/Owner - Sabre"
                            };

    /* Input */
    printf("The Office\n\nCharacters and their Jobs:\n\nFor Salesmen Enter '1'\nFor CEOs Enter '2'\n");
    Number = GetInteger();
    while (Number != 1 && Number != 2)
    {
        printf("Try Again");
        Number = GetInteger();
    }
    /* Output */
    switch (Number)
    {
        case 1:
            PrintWorkers (Salesmen,NumSalesmen);
        case 2:
            PrintWorkers(CEOs,NumCEOs);
    }

    printf("\n\nBONUS!!!!\nTo see the Original Cast Enter 99\n");
    Number = GetInteger();
    if (Number == 99)
        PrintWorkers (OriginalCast, OriginalMembers);
    else
        printf("Better Luck next time!!!");

    return 0;
}


void PrintWorkers (OfficeWorkers People[], int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("%s: %s\n", People[i].Name, People[i].Title);
    }
}
