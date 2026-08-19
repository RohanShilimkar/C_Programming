#include<stdio.h>

void Display(int No)
{
    static int i=1;

    if(i<=No)
    {
        printf(" %d ",i);
        i++;
        Display(No);
    }

}

int main()
{
    Display(5);


    return 0;
}