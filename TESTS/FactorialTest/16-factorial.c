/*
�����: factorial
�������: ������� �������� ������� n (����� int)
������: �������� a �� �� ���������� ��� n ������������ (����� long int)
Perigrafi: � ��������� paragontiko ������������ ��� ���������� ���� n!=n*(n-1)!
           ��� ����� ���������� ��� ����� ���.
*/
#include <stdio.h>

/* ������ ���������� */
long int factorial(int n);

main(){
        int n;
    long int a; /* ��� ��������� a ������������ �� ���������� */
    printf("Dwse thetiko akeraio:");
    scanf("%d",&n);
    /* ����� ���������� paragontiko */
    a=factorial(n);
    printf("To paragontiko tou %d einai %ld\n",n,a);
    system("pause");
}

/* ���������� �� ����������� ���� �������� �������*/
long int factorial(int n){
    long int a;
    if(n==1) a=1;
    else a=n*factorial(n-1); /* ���������� ����� */
    return a;
}
