#include<stdio.h>

int Rev(int No)
{
    int iDigit = 0;
    static int iRev= 0;

    if(No>0)
    {
        iDigit = No % 10;
        iRev  = (iRev * 10) + iDigit;
        No = No / 10;
        Rev(No);
    }
    return iRev;
}

int main()
{
    int iValue = 0;
    int iRet = 0;

    printf("Enter Number:");
    scanf("%d",&iValue);

    iRet = Rev(iValue);

    printf("Reverse Number is: %d",iRet);

    return 0;
}