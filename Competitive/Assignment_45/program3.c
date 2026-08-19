#include<stdio.h>

int Strlen(char *str)
{   
    static int iCount = 0;

    if(*str != '\0')
    {
        iCount++;
        str++;
        Strlen(str);
    }

    return iCount;
}

int main()
{
    char arr[20] = {'\0'};
    int iRet = 0 ;

    printf("Enter String:");
    scanf("%[^'\n']s",arr);

    iRet = Strlen(arr);

    printf("Length of String is: %d",iRet);

    return 0;
}