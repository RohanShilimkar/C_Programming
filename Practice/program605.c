#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define BUFFER_SIZE 1024

//Change in Parameter
int CountCapital(char* FileName)
{
    int fd = 0;
    int iRet = 0;
    int i = 0;
    int iCount=0;

    char Buffer[BUFFER_SIZE] = {'\0'};

    fd = open(FileName,O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open File");
        return -1;

    }

    while((iRet = read(fd,Buffer,sizeof(Buffer)))!=0)
    {
        for(i=0;i<iRet;i++)
        {
            if((Buffer[i] >= 'A') && (Buffer[i] <= 'Z'))
            {
                iCount++;
            }
        }
        memset(Buffer,'\0',sizeof(Buffer));
    }
    
    
    close(fd);

    return iCount;

}

int main()
{
    int iRet=0;
    char Fname[30] = {'\0'};

    printf("Enter the file Name:");
    scanf("%[^'\n']s",Fname);

    iRet = CountCapital(Fname);

    printf("Number of Capital Are:%d",iRet);

  
    return 0;
}