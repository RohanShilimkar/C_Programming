#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define BUFFER_SIZE 1024

void FileCopy(char FileNameSrc[],char FileNameDest[])
{
    int fd = 0,iRet = 0;
    char Buffer[BUFFER_SIZE] = {'\0'};
    int fdSrc=0,fdDest=0;

    fdSrc = open(FileNameSrc,O_RDONLY);

    if(fdSrc == -1)
    {
        printf("Unable to open Source File");
        return;
    }

    fdDest = open(FileNameDest,O_CREAT);

    if(fdDest == -1)
    {
        printf("Unable to create Destination File");
        return;
    }

    while((iRet = read(fdSrc,Buffer,sizeof(Buffer)))!=0)
    {
        write(fdDest,Buffer,iRet);
        memset(Buffer,'\0',sizeof(Buffer));
    }
   
    close(fdSrc);
    close(fdDest);
}

int main()
{
    char FnameSrc[30] = {'\0'};
    char FnameDest[30] = {'\0'};

    printf("Enter The Source File Name:");
    scanf("%[^'\n']s",FnameSrc);

    printf("\nEnter the Destination file name");
    scanf(" %[^'\n']s",FnameDest);              

    FileCopy(FnameSrc,FnameDest);

    
  
    return 0;
}