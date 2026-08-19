#include<stdio.h>

void Display(int No)
{
    static int i=0;

    if(i<No)
    {
        printf(" * ");
        i++;
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