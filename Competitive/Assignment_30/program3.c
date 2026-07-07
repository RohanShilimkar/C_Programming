#include<stdio.h>

void Display(char ch)
{
   if(ch >= 'A' && ch <= 'Z')
   {
    for(int i=ch;i<='Z';i++)
    {
        printf(" %c ",i);
    } 
   }
   else if( ch >= 'a' && ch <= 'z')
   {
     for(int i=ch;ch>='a';ch--)
     {
        printf(" %c ",ch);
     }
   }
   else{
    return;
   }
}

int main()
{
    char cValue='\0';

    printf("Enter a Character:");
    scanf("%c",&cValue);

    Display(cValue);


    return 0;
}