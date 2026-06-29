#include<stdio.h>
#include<stdlib.h>


int CountEvenOdd(int Arr[],int iLength)
{
    int iCnt =0;
    int iEven=0;
    int iOdd=0;

    for(iCnt=0;iCnt<iLength;iCnt++)
    {
        if(Arr[iCnt] % 2 == 0)
        {
            iEven++;
        }
        else
        {
            iOdd++;
        }
    }

    return (iEven-iOdd);
}

int main()
{
    int iSize=0,iCnt=0,iRet=0;
    int *p = NULL;

    printf("Enter How Many elements:");
    scanf("%d",&iSize);

    p = (int*)malloc(iSize * sizeof(int));

    if(p == NULL)
    {
        printf("Unable to locate Memory!");
    }

    printf("Enter %d Element\n",iSize);

    for(iCnt= 0;iCnt<iSize;iCnt++)
    {
        printf("Enter Element:%d :",iCnt);
        scanf("%d",&p[iCnt]);
    }

    iRet = CountEvenOdd(p,iSize);

    printf("Result is %d",iRet);

    free(p);

    return 0;

}