#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define BUFFER_SIZE 1024

int CalculateFileSize(char FileName[])
{
    int fd = 0,iRet = 0,iSize=0;
    char Buffer[BUFFER_SIZE] = {'\0'};

    fd = open(FileName,O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open File");
        return -1;

    }

    while((iRet = read(fd,Buffer,sizeof(Buffer)))!=0)
    {
        iSize = iSize + iRet;
    }

    return iSize;
     
    close(fd);


}

int main()
{
    int iRet = 0;
    char Fname[30] = {'\0'};

    printf("Enter the file Name:");
    scanf("%[^'\n']s",Fname);

    iRet = CalculateFileSize(Fname);

    printf("\nFile Size is: %d Bytes",iRet);
  
    return 0;
}