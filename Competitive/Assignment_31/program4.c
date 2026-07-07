#include<stdio.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

BOOL ChkVowel(char *str)
{
    while(*str !='\0')
    {
        if(*str == 'a' || *str == 'e' || *str == 'i' ||*str == 'o' ||*str == 'u')
        {
            return TRUE;
        }
        str++;
    }
}

int main()
{
    char arr[20];
    BOOL bRet =FALSE;

    printf("Enter a String: ");
    scanf("%[^'\n']s",arr);

    bRet = ChkVowel(arr);

    if(bRet == TRUE)
    {
        printf("Contains Vowels");
    }
    else{
        
        printf("No Vowels");
    }

    return 0;

}