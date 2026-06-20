#include<stdio.h>

void OddDisplay(int iNo)
{
    int iCnt=0;

    for(iCnt=1;iCnt<=iNo;iCnt++)
    {
        if((iCnt%2)==1)
        {
            printf("%d ",iCnt);    
        }
        
    }

   /* iCnt=1;
    while(iCnt<=iNo)
    {
        if((iCnt%2)!=0)
        {
        printf("%d ",iCnt);
        }
        iCnt++;
    }
    */
}

int main()
{
    int iValue=0;

    printf("Enter a Number:");
    scanf("%d",&iValue);

    OddDisplay(iValue);

    return 0;

}