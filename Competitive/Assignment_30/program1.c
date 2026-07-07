#include<stdio.h>

void DisplayASCII()
{
    printf("Symbol\tDecimal\tHexadecimal\tOctal\n");
    for(int i=0;i<=255;i++)
    {
        printf("%c\t%d\t\t%X\t\t%o\n",i,i,i,i);
    }
}

int main()
{
    DisplayASCII();

    return 0;

}