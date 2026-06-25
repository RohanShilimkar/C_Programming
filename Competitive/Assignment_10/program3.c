#include<stdio.h>

int KMtooMeter(int iNo)
{
    int iAns=0;

    iAns =  iNo * 1000;

    return iAns;
}

int main()
{
    int iValue=0,iRet=0;

    printf("Enter Distance:");
    scanf("%d",&iValue);

    iRet = KMtooMeter(iValue);

    printf("Distance in meter is:%d",iRet);


    return 0;
}