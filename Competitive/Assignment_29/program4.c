#include<stdio.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

BOOL ChkSmall(char ch)
{
    if(ch>='a' && ch<='z')
    {
        return TRUE;
    }
    return FALSE;

}
int main()
{
    char cValue = '\0';
    BOOL bRet = FALSE;

    printf("Enter the Character:");
    scanf("%c",&cValue);

    bRet = ChkSmall(cValue);

    if(bRet == TRUE)
    {
        printf("It is Small Case Character");
    }
    else
    {
        printf("It is not Small Case Character");
        
    }

    return 0;

}