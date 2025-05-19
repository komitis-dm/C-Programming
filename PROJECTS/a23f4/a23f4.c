#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

bool Valid_Time(int hour, int min, int sec);
bool Valid_Hour(int hour);
bool Valid_Min(int min);
bool Valid_Sec(int sec);

int main()
{
    /* Variable Declaration */
    int x,y,z;

    /* Input */
    printf ("Dwse tis ores: ");
    x = GetInteger();
    printf ("Dwse ta lepta: ");
    y = GetInteger();
    printf ("Dwse ta defterolepta: ");
    z = GetInteger();

    /* Output */

    if (Valid_Time (x, y, z))
    {
        printf ("WRA EGKYRH");
    }
    else
    {
        printf ("WRA MH EGKYRH");
    }

    return 0;
}

/* Functions */

bool Valid_Time(int hour, int min, int sec)
{
    return (Valid_Hour(hour) && Valid_Min(min) && Valid_Sec(sec) >=1);
}

bool Valid_Hour(int hour)
{
    return hour >= 0 && hour <= 23;
}

bool Valid_Min(int min)
{
    return min >= 0 && min <= 59;
}

bool Valid_Sec(int sec)
{
    return sec >= 0 && sec <= 59;
}
