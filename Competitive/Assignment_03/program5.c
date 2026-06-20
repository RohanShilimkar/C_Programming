#include<stdio.h>

typedef int BOOL;

#define TRUE 1
#define FALSE 0

BOOL ChkVowel(char CValue)
{
    if(CValue=='a'|| CValue=='e' || CValue=='i' || CValue=='o'|| CValue=='u')
    {
        return TRUE;
    }
    else {
        return FALSE;
    }
}


int main()
{
    char cValue ='\0';
    BOOL bRet = FALSE;

    printf("Enter a Character:");
    scanf("%c",&cValue);

    bRet = ChkVowel(cValue);

    if(bRet == TRUE){

        printf("%c is vowel",cValue);
    }
    else {
        printf("%c Is not vowel",cValue);
    }

    return 0;

}