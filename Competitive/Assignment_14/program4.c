#include<stdio.h>
#include<stdlib.h>

int Frequency(int Arr[],int iLength)
{
    int iCnt=0,iFreq=0;

    for(iCnt=0;iCnt<iLength;iCnt++)
    {
        if(Arr[iCnt] == 11)
        {
            iFreq++;
        }

    }
    return iFreq;
}

int main()
{
    int iSize=0,iCnt=0,iRet=0;
    int *p = NULL;
    
    printf("Enter How many Elements:");
    scanf("%d",&iSize);

    p = (int *)malloc(iSize * sizeof(int));

    if(p == NULL)
    {
        printf("Unable to Allocate Memory1");
        return -1;
    }

    printf("Enter %d Elemenets\n",iSize);

    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        printf("Enter element:%d ",iCnt);
        scanf("%d",&p[iCnt]);
    }

    iRet = Frequency(p,iSize);

    printf("Result is: %d",iRet);

    free(p);

    return 0;

}