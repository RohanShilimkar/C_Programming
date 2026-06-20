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
    // Variable creation with Default values
    float i=0.0f , j=0.0f , k=0.0f;

    printf("\nEnter First Number: ");
    scanf("%f",&i);

    printf("\nEnter Second Number: ");
    scanf("%f",&j);

    k = i + j;

    printf("Addition is: %f",k);
    
    return 0;
}