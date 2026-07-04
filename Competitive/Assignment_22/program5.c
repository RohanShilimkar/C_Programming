#include<stdio.h>

void Pattern(int iNo)
{
    int iCnt=0;
    for(iCnt=0;iCnt<=iNo;iCnt++)
    {
        printf("%d\n",2*iCnt);
    }
}


int main()
{
    int iValue=0;

    printf("Enter a Number:");
    scanf("%d",&iValue);

    Pattern(iValue);

    return 0;
}