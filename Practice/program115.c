#include<stdio.h>

void Display(int  Arr[],int iSize)
{
   int iCnt=0;
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
         printf("%d\n",Arr[iCnt]);
    }
    
}

int main()
{
    int iLenght = 4;
    int Brr[iLenght] = {10,20,30,40};   //  Error

    Display(Brr,iLenght);
    
    return 0;
}