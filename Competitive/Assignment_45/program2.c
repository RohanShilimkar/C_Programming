#include<stdio.h>

int Sum(int No)
{
    int iDigit=0;
    static int iSum=0;

    if(No>0)
    {
        iDigit = No % 10;
        iSum = iSum + iDigit;
        No = No / 10;       // Sum(No/10);
        Sum(No);
    }

    return iSum;
}


int main()
{
    int iValue = 0;
    int iRet = 0;

    printf("Enter Number:");
    scanf("%d",&iValue);

    iRet = Sum(iValue);
    printf("Sum is: %d",iRet);
    return 0;
}