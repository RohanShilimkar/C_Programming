#include<stdio.h>

void Reverse(char *str)
{
    int i=0;
    char *start = str;

    while(*str != '\0')
    {
        str++;
    }

    str--;

    while(str >= start)
    {
        printf("%c",*str);
        str--;
    }
}

int main()
{
    char arr[20];
    

    printf("Enter a String: ");
    scanf("%[^'\n']s",arr);

    Reverse(arr);

    return 0;

}