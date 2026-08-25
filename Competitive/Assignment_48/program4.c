#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>

// #define BUFFER_SIZE 1024

int CalculateFileSize(char FName[])
{
    /*

    int fd =0,iRet =0,iSize=0;
    char Buffer[BUFFER_SIZE] = {'\0'};

    fd = open(FName,O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open File");
        return -1;
        
    }

    while((iRet = read(fd,Buffer,sizeof(Buffer)))!=0)
    {
        iSize = iSize + iRet;
    }
    close(fd);
    return iSize;
    
    */
    
    struct stat sobj;
    
    stat(FName,&sobj);
    
    return sobj.st_size;

}

int main()
{
    char FileName[30] = {'\0'};
    int iRet = 0;

    printf("Enter File Name:");
    scanf("%[^'\n']s",FileName);

    iRet = CalculateFileSize(FileName);

    printf("Size of File is %d bytes",iRet);
    return 0;
}