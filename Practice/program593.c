#include<stdio.h>
#include<fcntl.h>      //File Control.h
#include<unistd.h>      //Only Linux Based
#include<string.h>

#define BUFFER_SIZE 1024

int main()
{
    char Buffer[BUFFER_SIZE]= {'\0'} ;
    int iRet = 0;
    int fd = 0;

    fd = open("program592.c",O_RDONLY);

    while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0);
    {
        printf("%s",Buffer);
        memset(Buffer,'\0',sizeof(Buffer));
    }
    close(fd);
   
    return 0;
}