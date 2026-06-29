#include<stdio.h>
#include<stdlib.h>

int Frequency(int Arr[],int iLength,int iNo)
{
    int iCnt=0,iFreq=0;

    for(iCnt=0;iCnt<iLength;iCnt++)
    {
        if(Arr[iCnt] == iNo)
        {
            iFreq++;
        }

    }
    return iFreq;
}

int main()
{
    int iSize=0,iCnt=0,iValue=0,iRet=0;
    int *p = NULL;
    
    printf("Enter How many Elements:");
    scanf("%d",&iSize);

    printf("Enter the Number:");
    scanf("%d",&iValue);

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

    iRet = Frequency(p,iSize,iValue);

    printf("Frequency of %d is %d",iValue,iRet);

    free(p);

    return 0;

}