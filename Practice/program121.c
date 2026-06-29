#include<stdio.h>
#include<stdlib.h>

void Display(int Arr[],int iSize)
{
    int iCnt =0;
    printf("Elements Are:\n");
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        printf("%d\n",Arr[iCnt]);
    }

}

int main()
{
    int *Brr = NULL;
    int iLenght=0,iCnt=0;

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

    Display(Brr,iLenght);

    //Step 5 : Deallocate Memory
    free(Brr);
    
    return 0;

}



/*
*/

