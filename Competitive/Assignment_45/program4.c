#include<stdio.h>

int Fact(int No)
{
   static int i=1;
   static int iFact = 1;

    if(i<=No)
    {
        iFact = iFact * i;
        i++;
        Fact(No);
    }

    return iFact;
    
}

int main()
{
    int iValue = 0;
    int iRet = 0;

    printf("Enter a Number:");
    scanf("%d",&iValue);

    iRet = Fact(iValue);

    printf("Factorial is: %d",iRet);

    return 0;

}