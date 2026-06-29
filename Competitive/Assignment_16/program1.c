#include<stdio.h>
#include<stdlib.h>

int Maximum(int Arr[],int iLength)
{
    int iCnt=0;
    int iMax=Arr[0];

    for(iCnt=0;iCnt<iLength;iCnt++)
    {
        if(Arr[iCnt] > iMax)
        {
            iMax = Arr[iCnt];
        }

    }
    return iMax;
}

int main()
{
    int iSize=0,iRet=0,iCnt=0;
    int *p = NULL;

    printf("Enter How many Elements:");
    scanf("%d",&iSize);

    p = (int *)malloc(iSize * sizeof(int));

    printf("Enter %d Elements\n",iSize);

    for(iCnt=0;iCnt < iSize;iCnt++)
    {
        printf("Enter %d Element",iCnt);
        scanf("%d",&p[iCnt]);
    }
    iRet = Maximum(p,iSize);

    printf("%d",iRet);


    return 0;

}