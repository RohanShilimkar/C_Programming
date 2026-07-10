#include<stdio.h>

void StrCatX(char *src,char *dest)
{
    
    while(*src != '\0')
    {
        src++;
    }
    
    while(*dest !='\0')
    {
        *src = *dest;
        src++;
        dest++;
    }
    *src  = '\0';
}

int main()
{
    char arr[70] = "Marvellous Infosystem ";
    char brr[30] =  "Logic Builing";

    StrCatX(arr,brr);
    
    printf("%s",arr);

    return 0;

}