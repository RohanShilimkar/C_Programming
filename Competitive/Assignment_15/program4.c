#include<stdio.h>
#include<stdlib.h>

void Range(int Arr[],int iLength,int iStart,int iEnd)
{
    int iCnt=0;

    for(iCnt=0;iCnt<iLength;iCnt++)
    {
        if((Arr[iCnt] >= iStart) && (Arr[iCnt] <= iEnd))
        {
            printf("%d  ",Arr[iCnt]);
        }
    }

}


int main()
{
    int *p = NULL;
    int iCnt=0,iSize=0,iValue1=0,iValue2=0;
    

    printf("\nEnter how many elements:");
    scanf("%d",&iSize);

    printf("\nEnter Starting Point:");
    scanf("%d",&iValue1);

    printf("\nEnter Ending Point:");
    scanf("%d",&iValue2);

    p = (int *)malloc(iSize * sizeof(int));

    if(p == NULL)
    {
        printf("Unable to allocate Memory!");
        return -1;
 
    }

    printf("Enter %d Elements:",iSize);
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        printf("\nEnter %d Element:",iCnt);
        scanf("%d",&p[iCnt]);
    }


     Range(p,iSize,iValue1,iValue2);


    free(p);


    return 0;
}