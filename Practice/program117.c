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
    int iCnt=0;
    int iLenght = 4;
    int Brr[iLenght];

    printf("Enter Elements:\n");

    for(iCnt=0;iCnt<iLenght;iCnt++)
    {
        scanf("%d\n",&Brr[iCnt]);
    }
 
    Display(Brr,iLenght);
    
    return 0;
}