#include<stdio.h>


int main()
{
    char str[80] = {'\0'};

    printf("Enter Command:");
    scanf("%[^'\n']s",str);

    printf("Entered Command is: %s",str);

    return 0;

}