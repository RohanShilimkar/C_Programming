#include<stdio.h>

void MultipleDisplay(int iNo)
{
    int iCnt=0;
    int iSum=0;

    for(iCnt=1;iCnt<=5;iCnt++)
    {
        iSum = iNo * iCnt;

        printf("%d ",iSum);
        
        //printf("%d ",iNo * iCnt);
    }
}

int main()
{
    int iValue=0;

    printf("Enter a Number:");
    scanf("%d",&iValue);

    MultipleDisplay(iValue);

    return 0;

}