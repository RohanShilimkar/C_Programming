#include<stdio.h>

int CountSmall(char *str)
{
    int iSmall=0;
    int iCapital=0;
    int ans=0;
    while(*str != '\0')
    {
        if(*str >= 'a' && *str <= 'z')
        {
            iSmall++;
        }
        else if(*str >= 'A' && *str <= 'Z')
        {
            iCapital++;
        }
        str++;
    }
  
    ans = iCapital - iSmall ;

    if(ans<0)
    {
        ans = -ans;
    }
    return ans;
}

int main()
{
    char arr[20];
    int iRet=0;

    printf("Enter String: ");
    scanf("%[^'\n]s",arr);

    iRet = CountSmall(arr);

    printf("Small Letters are:%d",iRet);

    return 0;

}