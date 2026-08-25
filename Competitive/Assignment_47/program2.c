#include<stdio.h>
#include<fcntl.h>
#include<io.h>


int CountSmall(char FName[])
{
    int fd = 0,iRet=0,iCount=0;
    char Buffer[30] = {'\0'};

    fd = open(FName,O_RDONLY);

   while((iRet = read(fd,Buffer,sizeof(Buffer)))!=0)
   {
        for(int i=0;i<iRet;i++)
        {
            if(Buffer[i] >= 'a' && Buffer[i] <= 'z')
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

    printf("ENter File Name:");
    scanf("%s",FileName);

    iRet = CountSmall(FileName);

    printf("Number of Small letters are:%d",iRet);

    return 0;

}