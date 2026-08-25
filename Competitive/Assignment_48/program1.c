#include<stdio.h>
#include<fcntl.h>

void Read(char FName[])
{
    int fd=0;

    fd = open(FName,O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file !");
        return;
    }
    else
    {
        printf("File Opened Successfully !\n");
    }

    close(fd);
    
}

int main()
{
    char FileName[30] = {'\0'};
    
    printf("Enter File Name:");
    scanf("%[^'\n']s",FileName);

    Read(FileName);


    return 0;
}