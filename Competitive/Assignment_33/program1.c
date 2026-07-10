#include<stdio.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;
BOOL CheckChar(char *str,char ch)
{
    while(*str != '\0')
    {
        if(*str == ch)
        {
            return TRUE;
        }
        str++;
    }
}

int main()
{
    char Arr[50];
    char cValue ;
    BOOL bRet = FALSE;

    printf("Enter a String:");
    scanf("%[^'\n']s",Arr);

    printf("Enter The Character:");
    scanf(" %c",&cValue);

    bRet = CheckChar(Arr,cValue);

    if(bRet == TRUE)
    {
        printf("Character Found");
    }
    else
    {
        printf("Character Not Found");
    }
    return 0;
}