#include<stdio.h>


int CountChar(char *str,char ch)
{
    int iCount=0;
    while(*str != '\0')
    {
        if(*str == ch)
        {
            iCount++;
        }
        str++;
    }

    return iCount;
}

int main()
{
    char Arr[50];
    char cValue ;
    int iRet=0;
  

    printf("Enter a String:");
    scanf("%[^'\n']s",Arr);

    printf("Enter The Character:");
    scanf(" %c",&cValue);

    iRet = CountChar(Arr,cValue);

    printf("Frequency of Character is:%d",iRet);
   
    return 0;
}