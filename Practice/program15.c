#include<stdbool.h>
#include<stdio.h>

bool CheckEvenOdd(int iNo)
{
     int iRemainder=0;
    
    iRemainder = iNo % 2;

    if(iRemainder==0)
    {
        return true;
    }
    else
        return false;


}


int main()
{
    int iValue = 0;
    bool bRet  = false;

    printf("Enter a Number to check whether it is even or odd: ");
    scanf("%d",&iValue);

    bRet = CheckEvenOdd(iValue);

    if(bRet ==true)
        printf("%d is even",iValue);
    else    
        printf("%d is Odd",iValue);

    return 0;
}