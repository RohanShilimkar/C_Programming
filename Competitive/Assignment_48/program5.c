#include<stdio.h>
#include<fcntl.h>
#include<string.h>

void Display(char FName[],char Line[])
{
    int fd = 0;
    int iRet=0;
    
    fd = open(FName,O_WRONLY | O_APPEND);

    if(fd == -1)
    {
        printf("Unable to open file!");
        return;
    }

    iRet = write(fd,Line,strlen(Line));

    printf("%d bytes Gets stored",iRet);

    close(fd);
}
int main()
{
    char FileName[30] = {'\0'};
    char Line[30] = {'\0'};

    printf("Enter File Name:");
    scanf("%s",FileName);

    printf("Enter the String to Add:");
    scanf(" %[^'\n']s",Line);

    Display(FileName,Line);

    return 0;
}