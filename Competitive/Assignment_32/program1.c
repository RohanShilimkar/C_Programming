#include<stdio.h>

void strlwrx(char *str)
{
    if(*str >= 'a' && *str <='z')
    {
        *str + ('a' - 'A');
    }
    else if (*str >= 'A' && *str <='Z')
    {
        *str - ('a' - 'A');
    }
}

int main()
{
    char arr[20];
    

    printf("Enter a String: ");
    scanf("%[^'\n']s",arr);

    strlwrx(arr);

    printf("Modified String is: %s",arr);
    return 0;

}