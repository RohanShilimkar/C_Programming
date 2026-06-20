#include<stdio.h>

double SquarMeter(int iNo)
{
    double dValue=0.0;

   dValue = iNo * 0.0929;

   return dValue;
  
}

int main()
{
    int iValue=0;
    double dRet=0.0;

    printf("Enter area in Sq.ft:");
    scanf("%d",&iValue);

    dRet = SquarMeter(iValue);

    printf("Area in Sq.m is:%lf",dRet);

    return 0;

}