#include<stdio.h>

void CheckEvenOdd(int iNo)
{
     int iRemainder=0;
    
    iRemainder = iNo % 2;

    if(iRemainder == 0)
        printf("Number is Even");
    else
        printf("Number is Odd");


}


int main()
{
    int iValue = 0;
   

    printf("Enter a Number:");
    scanf("%d",&iValue);

    CheckEvenOdd(iValue);



    return 0;
}