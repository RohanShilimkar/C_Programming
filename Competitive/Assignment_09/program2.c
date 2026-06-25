#include<stdio.h>

int CountOdd(int iNo)
{
    int iDigit=0;
    int iCnt=0;

    while(iNo!=0)
    {
        iDigit = iNo%10;

        if(iDigit % 2 != 0)
        {
            iCnt++;
        }

        iNo = iNo / 10;
    }

    return iCnt;
}

int main()
{
    int iValue=0;
    int iRet=0;

    printf("Enter a Number:");
    scanf("%d",&iValue);

    iRet = CountOdd(iValue);

    printf("Total Odd Number: %d",iRet);

    return 0;
}