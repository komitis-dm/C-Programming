#include <stdio.h>
#include "simpio.h"

void decompose(long *Num, int *MaxDigit, int *DigitSum, float *Average);
int FindDigitSum(long *Num);
int FindMaxDigit(int *DigitSum, int DigitArray[]);
float FindAverage(int *DigitSum, int DigitArray[]);


// MAIN //
int main()
{
    // Variable Declaration //
    long Num;
    int MaxDigit, DigitSum;
    float Average;

    // Input //
    printf("Please insert non-negative number:");
    Num = GetLong();
    MaxDigit = 0;
    DigitSum = 0;
    Average = 0;

    // Computation //
    decompose (&Num, &MaxDigit, &DigitSum, &Average);

    // Output //
    printf("Digits: %d\n", DigitSum);
    printf("Average: %.3f\n", Average);
    printf("Max: %d", MaxDigit);

    return 0;
}
// FUNCTIONS //

void decompose(long *Num, int *MaxDigit, int *DigitSum, float *Average)
{
    *DigitSum = FindDigitSum(Num);
    long TestNumber;
    int DigitArray[*DigitSum], i;
    TestNumber = *Num;
    for (i=0; i<*DigitSum; i++)
    {
        DigitArray[i] = TestNumber % 10;
        TestNumber = TestNumber / 10;
    }
    *MaxDigit = FindMaxDigit(DigitSum, DigitArray);
    *Average = FindAverage(DigitSum, DigitArray);

}
int FindMaxDigit(int *DigitSum, int DigitArray[])
{
    int MaxDigit, i;
    MaxDigit = DigitArray[0];
    for (i=1; i<*DigitSum; i++)
    {
        if (DigitArray[i] > MaxDigit)
            MaxDigit = DigitArray[i];
    }
    return MaxDigit;
}
int FindDigitSum (long *Num)
{
    int DigitSum;
    long TestNumber;
    TestNumber = *Num;
    DigitSum = 0;
    while (TestNumber != 0)
    {
        TestNumber = TestNumber / 10;
        DigitSum++;
    }
    return DigitSum;

}
float FindAverage(int *DigitSum, int DigitArray[])
{
    int i;
    float Average, sum;
    sum = 0;
    Average = 0;
    for (i=0; i<*DigitSum; i++)
    {
        sum = sum + DigitArray[i];
    }
    Average = sum / *DigitSum;
    return Average;
}
