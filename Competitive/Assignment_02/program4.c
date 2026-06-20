#include<stdio.h>

void Display(int iNo,int iFreqency)
{
    int iCnt= 0;

    if(iNo<0){
        iNo = -iNo;
    }

    if(iFreqency<0){
        iFreqency = -iFreqency;
    }

    if(iFreqency==0){
        return;
    }

    for(iCnt=1;iCnt<=iFreqency;iCnt++)
    {
        printf("%d ",iNo);
    }
}

int main()
{
    int iValue = 0;
    int iFreq = 0;

    printf("Enter a Number:");
    scanf("%d",&iValue);

     
    printf("Enter Frequency:");
    scanf("%d",&iFreq);

    Display(iValue,iFreq);

    return 0;
}