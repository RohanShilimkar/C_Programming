#include<stdio.h>

void PrintEven(int iNo)
{
    if(iNo<=0){
        return ;
    }

    for(int iCnt=1;iCnt<=iNo;iCnt++)
    {
       printf("%d ",iCnt*2);
    }



}

int main()
{

    int iValue = 0;

    printf("Enter a Number:");
    scanf("%d",&iValue);

    PrintEven(iValue);

    return 0;

}