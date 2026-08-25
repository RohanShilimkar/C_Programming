#include<stdio.h>
#include<io.h>
#include<fcntl.h>

int CountWhite(char FNamae[])
{
    int fd = 0,iRet=0,iCount=0;
    char Buffer[30] = {'\0'};

    fd = open(FNamae,O_RDONLY);

    while((iRet = read(fd,Buffer,sizeof(Buffer)))!=0)
    {
        for(int i=0;i<iRet;i++)
        {
            if(Buffer[i] == ' ')
            {
                iCount++;
            }
        }
    }
    close(fd);

    return iCount;
}


int main()
{
    char FileName[30] = {'\0'};
    int iRet = 0;

    printf("Enter File Name:");
    scanf("%s",FileName);

    iRet = CountWhite(FileName);
    printf("\nNumber of White Spaces are:%d",iRet);

    return 0;

}