#include<stdio.h>
#include<stdlib.h>

typedef  int BOOL;

#define TRUE 1
#define FALSE 0

BOOL Check(int Arr[],int iLength,int iNo)
{
    int iCnt = 0;

    for(iCnt=0;iCnt<iLength;iCnt++)
    {
        if(Arr[iCnt] == iNo)
        {
            return TRUE;
        }
    }

    return FALSE;


}

int main()
{
    int *p = NULL;
    int iCnt=0,iSize=0,iValue=0;
    BOOL bRet = FALSE;

    printf("Enter how many elements:");
    scanf("%d",&iSize);

    printf("Enter Number:");
    scanf("%d",&iValue);

    p = (int *)malloc(iSize * sizeof(int));

    if(p == NULL)
    {
        printf("Unable to allocate Memory!");
        return -1;
 
    }

    printf("\nEnter %d Elements:",iSize);
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        printf("\nEnter %d Element:",iCnt);
        scanf("%d",&p[iCnt]);
    }

    bRet = Check(p,iSize,iValue);

    if(bRet == TRUE)
    {
        printf("\n%d Number is Present",iValue);
    }
    else
    {
        printf("\n%d Number is Not Present",iValue);

    }

    free(p);


    return 0;

}