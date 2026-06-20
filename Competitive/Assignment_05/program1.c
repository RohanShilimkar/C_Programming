#include<stdio.h>

void Pattern(int iNo)
{
    int iCnt =0;

    for(iCnt=1;iCnt<=5;iCnt++)
    {
        printf(" $\t*");
    }
}

int main()
{
    int iValue = 0;

    printf("Enter a Number:");
    scanf("%d",&iValue);

    Pattern(iValue);

    return 0;
}