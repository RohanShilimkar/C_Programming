#include<stdio.h>

void Display(int No)
{
    static int i=1;

    if(No>0)
    {
        printf("%d * ",No);
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