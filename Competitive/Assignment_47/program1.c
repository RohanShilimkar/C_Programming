#include<stdio.h>
#include<io.h>
#include<fcntl.h>

int CountCapital(char FName[])
{
    int fd = 0;
    int iRet = 0;
    int iCount=0;
    char Buffer[30] = {'\0'};

    fd = open(FName, O_RDONLY);

    while((iRet = read(fd,Buffer,sizeof(Buffer)))!=0)
    {
        for(int i=0;i<iRet;i++)
        {
            if(Buffer[i] >= 'A' && Buffer[i] <='Z')
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
    int iRet =0;

    printf("Enter file Name:");
    scanf("%s",FileName);

    iRet = CountCapital(FileName);

    printf("\nNumber of Capital Letters are: %d",iRet);

    return 0;

}