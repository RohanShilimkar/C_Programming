#include<stdio.h>

void struprx(char *str)
{
   while(*str != '\0')
   {
        if((*str >= 'a') && (*str <= 'z'))
        {
            *str = *str -32;
        }
        str++;
    }
}

int main()
{
    char arr[20];
    

    printf("Enter a String: ");
    scanf("%[^'\n']s",arr);

    striprx(arr);

    printf("Modified String is: %s",arr);
    return 0;

}