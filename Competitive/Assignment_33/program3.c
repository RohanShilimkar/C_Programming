#include<stdio.h>


int CountChar(char str[],char ch)
{
   int i=0;

   for(i=0;i<str['\0'];i++)
   {
        if(str[i] == ch)
        {
            break;
        }
   }
   return i;

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