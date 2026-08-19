#include<stdio.h>

int Mult(int No)
{
    static int iMult = 1;
    int iDigit=0;

    if(No>0)
    {
        iDigit = No % 10;
        iMult = iMult * iDigit;
        No = No /10;
        Mult(No);
    }
    return iMult;

}

int main()
{
    int iValue = 0;
    int iRet = 0;

    printf("Enetr a Number:");
    scanf("%d",&iValue);

    iRet = Mult(iValue);

    printf("Product is: %d",iRet);

    return 0;
}