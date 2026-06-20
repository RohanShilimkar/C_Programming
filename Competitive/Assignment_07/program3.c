#include<stdio.h>

int EvenFactor(int iNo)
{
    int iCnt=0,iFact=1;

    for(iCnt=1;iCnt<=iNo;iCnt++)
    {
        if(iCnt%2==0)
        {
            iFact = iFact * iCnt;
        }
    }

    return iFact;
}

int main()
{
    int iValue=0,iRet=0;

    printf("Enter a Number:");
    scanf("%d",&iValue);

    iRet = EvenFactor(iValue);

    printf("%d",iRet);

    return 0;
}