#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

BOOL Check(int Arr[],int iLength)
{
    int iCnt = 0;
    for(iCnt=0;iCnt<iLength;iCnt++)
    {
        if(Arr[iCnt] == 11)
        {
            return TRUE;
        }
        
    }

    return FALSE;
}

int main()
{
    int *p = NULL;
    int iSize=0,iCnt=0;
    BOOL bRet = FALSE;

    printf("Enter How Many elements:");
    scanf("%d",&iSize);

    p = (int *)malloc(iSize * sizeof(int));

    if(p == NULL)
    {
        printf("Unable to allocate Memory!");
        return -1;
    }

    printf("Enter %d Elements\n",iSize);

    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        printf("Enter %d Element: ",iCnt);
        scanf("%d",&p[iCnt]);
    }

    bRet = Check(p,iSize);

    if(bRet == TRUE)
    {
        printf("11 is Present");
    }
    else
    {
        printf("11 is Not Present");
    }

    free(p);

    return 0;

}