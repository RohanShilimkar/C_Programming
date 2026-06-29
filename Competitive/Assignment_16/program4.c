#include<stdio.h>
#include<stdlib.h>

void Display(int Arr[],int iLength)
{
    int iCnt=0;
    int iDigit=0;
    
    for(iCnt=0;iCnt<iLength;iCnt++)
    {
        if(Arr[iCnt] >=100 && Arr[iCnt]<=1000)
        {
            printf("%d  ",Arr[iCnt]);
        }

    }

/*        int iNo=0;
        
        for(iCnt=0;iCnt<iLength;iCnt++)
        {
            iNo = Arr[iCnt];
            int iDigitCount=0;

            while(iNo !=0)
            {
                iDigitCount++;
                iNo = iNo / 10;

            }
              
            if(iDigitCount == 3)
            {   
                printf("%d  ",Arr[iCnt]);
            }
        }
  */  

    
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
    
    Display(p,iSize);

    free(p);

    return 0;

}