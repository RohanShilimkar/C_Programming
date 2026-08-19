#include<stdio.h>

int Max(int No)
{
    int iDigit = 0;
    static int iMax = 0;

    if(No>0)
    {
        iDigit = No % 10;
        if(iDigit > iMax )
        {
            iMax  = iDigit;
        }
        No = No / 10;
        Max(No);
    }

    return iMax;
}

int main()
{
    int iValue = 0;
    int iRet = 0;

    printf("Enter Number:");
    scanf("%d",&iValue);

    iRet = Max(iValue);

    printf("Largest Digit is: %d",iRet);

    return 0;
}