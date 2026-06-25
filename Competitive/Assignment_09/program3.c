#include<stdio.h>

int CountRange(int iNo)
{
    int iDigit=0;
    int iCnt=0;

    while(iNo!=0)
    {
        iDigit = iNo%10;

        if(iDigit < 7 && iDigit > 3)
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

    iRet = CountRange(iValue);

    printf("Total number between 3 and 7 : %d",iRet);

    return 0;
}