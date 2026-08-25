#include<stdio.h>
#include<fcntl.h>

void Create(char FName[])
{
    int fd=0;

    fd = open(FName,O_CREAT);

    if(fd == -1)
    {
        printf("Unable to Create file !");
        return;
    }
    else
    {
        printf("File Created Successfully !\n");
    }

    close(fd);
    
}

int main()
{
    char FileName[30] = {'\0'};

    
    printf("Enter File Name:");
    scanf("%[^'\n']s",FileName);
    
    Create(FileName);


    return 0;
}