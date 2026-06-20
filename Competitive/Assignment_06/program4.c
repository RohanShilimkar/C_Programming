#include<stdio.h>

void Table(int iNo)
{
    int iCnt=0;
    
    if(iNo<0)
    {
        iNo = -iNo;
    }

    for(iCnt=1;iCnt<=10;iCnt++)
    {
        printf("%d\n", iNo * iCnt);
    }
}

int main()
{
    int iValue=0;

    printf("Enter a Number:");
    scanf("%d",&iValue);

    Table(iValue);

    return 0;

}