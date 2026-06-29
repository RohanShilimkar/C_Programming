#include<stdio.h>
#include<stdlib.h>

int Sum(int Arr[],int iSize)
{
    int iCnt =0;
    int iSum=0;
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        iSum+=Arr[iCnt];
    }

    return iSum;

}

int main()
{
    int *Brr = NULL;
    int iLenght=0,iCnt=0,iRet=0;

    //Step 1 : Accept Number of Elements
    printf("Enter Number of Elements:");
    scanf("%d",&iLenght);

    //Step 2: Allocate The memory
    Brr = (int *)malloc(iLenght * sizeof(int));

    //Step 3 : Accept the Values 
    printf("Enter the Elements:");
    for(iCnt=0;iCnt<iLenght;iCnt++)
    {
        scanf("%d",&Brr[iCnt]);
    }

    //Step 4 : Use the memory [Logic]

    iRet = Sum(Brr,iLenght);

    printf("Summation is: %d",iRet);

    //Step 5 : Deallocate Memory
    free(Brr);
    
    return 0;

}



/*
*/

