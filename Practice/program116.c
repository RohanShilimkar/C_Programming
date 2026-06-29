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
    int Brr[iLenght];

    Brr[0]=10;
    Brr[1]=20;
    Brr[2]=30;
    Brr[3]=40;

    Display(Brr,iLenght);
    
    return 0;
}