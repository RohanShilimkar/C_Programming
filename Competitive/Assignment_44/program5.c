#include<stdio.h>

void Display(int No)
{
    static char ch = 'a';

    if(No>0)
    {
        printf(" %c ",ch);
        ch++;
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