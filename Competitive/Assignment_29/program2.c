#include<stdio.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

BOOL ChkCapital(char ch)
{
    if(ch>='A' && ch<='Z')
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

    bRet = ChkCapital(cValue);

    if(bRet == TRUE)
    {
        printf("It is Capital Character");
    }
    else
    {
        printf("It is not a Character");
        
    }

    return 0;

}