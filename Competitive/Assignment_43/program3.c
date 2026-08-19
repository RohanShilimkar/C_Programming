#include<stdio.h>

void Display(int No)
{
    if(No>0)
    {
        printf("%d",No);
        No--;
        Display(No);
    }
}

int main()
{
    Display(5);


    return 0;
}