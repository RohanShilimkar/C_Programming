#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

#define BUFFER_SIZE 1024

int CalculateFileSize(char FileName[])
{
    struct stat sobj;

    stat(FileName,&sobj);

    return sobj.st_size;

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