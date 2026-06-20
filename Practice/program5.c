/*
    Algorithm

    Start
        Accept First Number as no1
        Accept Second Number as no2
        Perform Addition of no1 and no2
        Display the Result
    Stop
*/


#include<stdio.h>

int main()
{
    float i,j,k;

    printf("\nEnter First Number: ");
    scanf("%f",&i);

    printf("\nEnter Second Number: ");
    scanf("%f",&j);

    k = i + j;

    printf("Addition is: %f",k);
    
    return 0;
}