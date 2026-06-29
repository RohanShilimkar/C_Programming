#include<stdio.h>
#include<stdlib.h>

int Product(int Arr[],int iLength)
{
    int iCnt=0;
    int iMult=1;

    for(iCnt=0;iCnt<iLength;iCnt++)
    {
        if(Arr[iCnt] % 2 == 1)
        {
            iMult = iMult * Arr[iCnt];

        }
    }

    return iMult;

}

int main()
{
    int *p = NULL;
    int iCnt=0,iSize=0,iValue=0;
    int iRet = 0;

    printf("Enter how many elements:");
    scanf("%d",&iSize);

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


    iRet = Product(p,iSize);

    printf("%d",iRet);

    free(p);


    return 0;
}