#include<stdio.h>
#include<fcntl.h>

#define BUFFER_SIZE 1024

void Display(char FName[])
{
    int fd = 0;
    int iRet=0;
    char Buffer[BUFFER_SIZE]={'\0'};

    fd = open(FName,O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open File!");
    }
    
    while((iRet = read(fd,Buffer,sizeof(Buffer)))!=0)
    {
        write(1,Buffer,iRet);
    }

    close(fd);
}

int main()
{
    char FileName[30] = {'\0'};

    printf("Enter File Name:");
    scanf("%[^'\n']s",FileName);

    Display(FileName);

    return 0;
}