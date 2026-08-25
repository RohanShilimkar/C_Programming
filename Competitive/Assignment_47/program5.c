#include<stdio.h>
#include<fcntl.h>
#include<io.h>

void Display(char FName[],int iNo)
{
    int fd = 0,iRet=0,iCount=0;
    char Buffer[iNo];

    fd = open(FName,O_RDONLY);

    iRet = read(fd,Buffer,iNo);
    
    if(iRet > 0)
    {
        write(1,Buffer,iRet);
    }
    close(fd);
}


int main()
{
    char FileName[30] = {'\0'};
    int iValue = 0;

    printf("Enter File Name:");
    scanf("%s",FileName);
    
    printf("Enter the Number of Characters:");
    scanf(" %d",&iValue);

    Display(FileName,iValue);


    return 0;
}