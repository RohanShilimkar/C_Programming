#include<stdio.h>

typedef int BOOL;
#define TRUE 1
#define FALSE  0

BOOL Check(int iNo)
{
    if((iNo%5)==0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

int main()
{
    int iValue = 0;
    BOOL bRet = FALSE;

    printf("Enter a Number:");
    scanf("%d",&iValue);

    bRet = Check(iValue);

    if(bRet==TRUE)
    {
        printf("%d is Divisible by 5",iValue);
    }
    else{
        printf("%d is Not Divisible by 5",iValue);
    }

    return  0;
}