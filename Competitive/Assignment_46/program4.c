#include<stdio.h>

int Min(int No)
{
    int iDigit = 0;
    static int iMin = 9;

    if(No>0)
    {
        iDigit = No % 10;
        if(iMin > iDigit )
        {
            iMin  = iDigit;
        }
        No = No / 10;
        Min(No);
    }

    return iMin;
}

int main()
{
    int iValue = 0;
    int iRet = 0;

    printf("Enter Number:");
    scanf("%d",&iValue);

    iRet = Min(iValue);

    printf("Smallest Digit is: %d",iRet);

    return 0;
}