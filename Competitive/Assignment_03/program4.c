#include<stdio.h>

void DisplayConvert(char CValue)
{
    if(CValue>='A' && CValue<='Z')
    {
        printf("%c",CValue + 32);
    }
  else if(CValue>='a' && CValue<='z')
  {
    printf("%c",CValue -32);
  }
  else{
    printf("Invalid Input");
  }
}
int main()
{    char cValue = '\0';

    printf("Enter a Character:");
    scanf("%c",&cValue);

    DisplayConvert(cValue);

    return 0;
 
}