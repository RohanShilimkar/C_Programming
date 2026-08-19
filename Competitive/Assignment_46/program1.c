#include<stdio.h>

int WhiteSpace(char *str)
{
    static int iCount = 0;

    if(*str != '\0')
    {
        if(*str == ' ')
        {
            iCount++;
        }
        str++;
        WhiteSpace(str);
    }

    return iCount;
}


int main()
{
    char arr[30] = {'\0'};
    int iRet = 0;

    printf("Enter String:");
    scanf("%[^'\n']s",arr);

    iRet = WhiteSpace(arr);

    printf("Number of Spaces are: %d",iRet);

    return 0;
}