#include<stdio.h>
#include<stdlib.h>

int FirstOcc(int Arr[],int iLength,int iNo)
{
    int iCnt=0;

    for(iCnt=0;iCnt<iLength;iCnt++)
    {
        if(Arr[iCnt]==iNo)
        {
            return iCnt;
        }
    }

}

int main()
{
    int *p = NULL;
    int iCnt=0,iSize=0,iValue=0;
    int iRet = 0;

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

    printf("Enter %d Elements:",iSize);
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        printf("\nEnter %d Element:",iCnt);
        scanf("%d",&p[iCnt]);
    }


    iRet = FirstOcc(p,iSize,iValue);

    if(iRet == -1)
    {
        printf("There is no such Number");

    }
    else
    {
        printf("First Occurence of Number is %d",iRet);
    }

    free(p);


    return 0;
}