#include<stdio.h>

void display(int iNo)
{
    int iCnt=0;
    //filter
    if(iNo<0)
    {
        printf("Invalid Input");
        return;
    }
    
      for(iCnt=1;iCnt<=iNo;iCnt++)
    {
        printf("\nJay Ganesh...");
    }

}

int main()
{
    int iCnt=0;
    int iValue=0;

    printf("Enter frequency:");
    scanf("%d",&iValue);
    
    display(iValue);

    return 0;
}