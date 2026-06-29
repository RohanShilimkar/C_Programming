#include<stdio.h>

int Sum(int  Arr[],int iSize)
{
    int iSum=0;
   int iCnt=0;
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
         iSum += Arr[iCnt];
    }
    
    return iSum;
}

int main()
{
    int iCnt=0;
    int iRet = 0;
    int iLenght = 4;
    int Brr[iLenght];

    printf("Enter Elements:\n");

    for(iCnt=0;iCnt<iLenght;iCnt++)
    {
        scanf("%d",&Brr[iCnt]);
    }
 
    iRet = Sum(Brr,iLenght);
    
    printf("Addition of Elements:%d",iRet);
    
    return 0;
}