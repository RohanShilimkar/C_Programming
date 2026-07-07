#include<stdio.h>

void Display(char ch)
{
    if(ch >= 'a' && ch <= 'z')
    {
        printf("%c",ch-('a' - 'A'));
    }
    else if(ch >='A' && ch <= 'Z')
    {
        printf("%c",ch + ('a' - 'A'));
    }
    else
    {
        printf("%c",ch);
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