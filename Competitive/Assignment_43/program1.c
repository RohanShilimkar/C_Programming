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
    Display(5);


    return 0;
}