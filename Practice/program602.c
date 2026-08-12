#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

#define BUFFER_SIZE 1024

void DisplayFileInformation(char FileName[])
{
    struct stat sobj;

    stat(FileName,&sobj);

    printf("File Name: %s",FileName);
    printf("\nInode Number: %d",sobj.st_ino);
    printf("\nFile Size is:%lld",sobj.st_size);
    
}

int main()
{
    
    char Fname[30] = {'\0'};

    printf("Enter the file Name:");
    scanf("%[^'\n']s",Fname);

    DisplayFileInformation(Fname);

    return 0; 
}