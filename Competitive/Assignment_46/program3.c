#include<stdio.h>

int CountSmall(char *str)
{
    static int iCount = 0;

    if(*str != '\0')
    {
        if((*str >= 'a') && (*str <= 'z'))
        {
            iCount++;
        }
        str++;
        CountSmall(str);
    }

    return iCount;
}


int main()
{
    char arr[30] = {'\0'};
    int iRet = 0;

    printf("Enter String:");
    scanf("%[^'\n']s",arr);

    iRet = CountSmall(arr);

    printf("Small Characters are: %d",iRet);

    return 0;
}