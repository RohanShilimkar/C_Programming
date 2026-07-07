#include<stdio.h>

void Display(char ch)
{
    if((ch >='a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        printf("Decimal :%d",ch);
        printf("\nOctal :%o",ch);
        printf("\nHexadecimal :%x",ch);

    }
}

int main()
{
    char cValue='\0';

    printf("Enter a Character:");
    scanf("%c",&cValue);

    Display(cValue);


    return 0;
}