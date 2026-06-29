#include<stdio.h>
#include<stdlib.h>

void DigitSum(int Arr[],int iLength)
{
    int iCnt=0;
    int iDigit=0;
    int iNo=0;
    
    for(iCnt=0;iCnt<iLength;iCnt++)
    {
        int iSum=0;
        iNo = Arr[iCnt];
        
       while(iNo !=0)
        { 
            iDigit = iNo % 10 ; 
            iSum = iSum +iDigit;
            iNo = iNo / 10;
        }
        printf("%d  ",iSum);
    }

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
    
    DigitSum(p,iSize);

    free(p);

    return 0;

}