#include<stdio.h>

void Display(int No)
{
    static char ch='A';

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
    Display(6);

    return 0;
}