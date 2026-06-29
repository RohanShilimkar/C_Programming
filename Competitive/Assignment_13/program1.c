#include<stdio.h>
#include<stdlib.h>

int Difference(int Arr[],int iLength)
{
    int iCnt=0,iSum=0,iEvenSum=0,iOddSum=0;

    for(iCnt=0;iCnt<iLength;iCnt++)
    {
        if(Arr[iCnt] % 2 == 0)
        {
            iEvenSum += Arr[iCnt];
        }
        else
        {
            iOddSum += Arr[iCnt];
        }
    }
    return (iEvenSum - iOddSum);
}

int main()
{
    int iValue=0 , iSize=0 , iRet=0 , iCnt=0;
    int *p = NULL;


    printf("Enter How many Elements:");
    scanf("%d",&iSize);

    p = (int *)malloc(iSize * sizeof(int));

    if(p == NULL)
    {
        printf("Unable to allocate memory!");
        return -1;
    }

    printf("Enter %d Elements",iSize);

    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        printf("\nEnter element:%d :",iCnt+1);
        scanf("%d",&p[iCnt]);
    }

    iRet = Difference(p,iSize);

    printf("Result is: %d",iRet);

    free(p);

    return 0;
}