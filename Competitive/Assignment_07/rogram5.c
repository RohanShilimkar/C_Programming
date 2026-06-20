#include<stdio.h>

int FactorialDiff(int iNo)
{
    int iCnt=0;
    int iEvenFact=1,iOddFact=1;
    int iAns = 0;

    for(iCnt=1;iCnt<=iNo;iCnt++)
    {
        if((iCnt%2)==0 )
        {
            iEvenFact = iEvenFact * iCnt;
        }
        else if((iCnt%2)!=0)
        {
            iOddFact = iOddFact * iCnt;

        }

    }
    iAns = iEvenFact - iOddFact;

    return iAns;
}

int main()
{
    int iValue=0,iRet=0;

    printf("Enter a Number:");
    scanf("%d",&iValue);

    iRet = FactorialDiff(iValue);

    printf("Odd Factorial is:%d",iRet);
    return 0;
    
}