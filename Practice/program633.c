#include<stdio.h>

int main()
{
    char str[50] = {'\0'};
    int iRet = 0;

    iRet = sprintf(str,"Jay Ganesh...");

    printf("Value from iRet is: %d",iRet);
    printf("\nData from str is: %s",str);


    return 0;
}