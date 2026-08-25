#include<stdio.h>
#include<fcntl.h>
#include<io.h>

int CountChar(char FName[],char ch)
{
    int fd = 0,iRet=0,iCount=0;
    char Buffer[30] = {'\0'};

    fd = open(FName,O_RDONLY);

    while((iRet = read(fd,Buffer,sizeof(Buffer)))!=0)
    {
        for(int i=0;i<iRet;i++)
        {
            if(Buffer[i] == ch)
            {
                iCount++;
            }
        }
    }
    close(fd);
    return iCount;
}


int main()
{
    char FileName[30] = {'\0'};
    int iRet =0;
    char cValue = '\0';

    printf("Enter File Name:");
    scanf("%s",FileName);
    
    printf("Enter the Character:");
    scanf(" %c",&cValue);

    iRet = CountChar(FileName,cValue);

    printf("Frequency of %c Value is: %d",cValue,iRet);


    return 0;
}