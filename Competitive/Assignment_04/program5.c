#include<stdio.h>

int FactDiff(int iNo)
{
    int iCnt=0;
    int iIsFactor=0;
    int iNoFactor=0;
    int iAns = 0;

    for(iCnt=1;iCnt<iNo;iCnt++)
    {
        if((iNo%iCnt)==0)
        {
            iIsFactor = iIsFactor + iCnt;
        }
        else
        {
            iNoFactor = iNoFactor + iCnt;
        }
    }
    
    iAns = iIsFactor - iNoFactor;
    // return (iIsFactor - iNoFactor);

    return iAns;
}

int main()
{
    int iValue=0;
    int iRet = 0;

    printf("Enter a Number:");
    scanf("%d",&iValue);

    iRet = FactDiff(iValue);

    printf("%d",iRet);

    return 0;
}