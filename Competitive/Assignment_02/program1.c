#include<stdio.h>

void Display(int iNo)
{
    int iCnt = 0;
    if(iNo<0){
      iNo = -iNo;
    } 
    while(iCnt<iNo)
    {
        printf("(*)%d ",iCnt);
        iCnt++;
    }

}

int main()
{
    int iValue = 0;

    printf("Enter a Number:");
    scanf("%d",&iValue);

    Display(iValue);

    return 0;

}