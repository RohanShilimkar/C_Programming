#include<stdio.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

BOOL Display(char ch)
{
    if(ch == '!' || ch == '@' || ch == '#' || ch == '$' || 
       ch == '%' || ch == '^' || ch == '&' || ch == '*')
    {
        return TRUE;
    }


}

int main()
{
    char cValue='\0';
    BOOL bRet = FALSE;

    printf("Enter a Character:");
    scanf("%c",&cValue);

    bRet = Display(cValue);

    if(bRet ==TRUE)
    {
        printf("Special Character");
    }
    else{
        printf("Not A Special Character");
    }

    return 0;
}