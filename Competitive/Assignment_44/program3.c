#include<stdio.h>

void Display(int No)
{
    if(No>0)
    {
        printf(" %d ",No);
        No--;
        Display(No);
    }
}

int main()
{
    int iValue = 0;

    printf("Enter Number:");
    scanf("%d",&iValue);
    Display(iValue);

    return 0;
}