#include<stdio.h>

int MultiDigits(int iNo)
{
    int iDigit=0;
    int iCnt=1;


    while(iNo!=0)
    {
        iDigit = iNo % 10;
      
        iCnt  = iCnt * iDigit ;

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

    iRet = MultiDigits(iValue);

    printf("Multiplication of Factors : %d",iRet);

    return 0;
}