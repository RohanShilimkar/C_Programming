#include<stdio.h>
#include<fcntl.h>      //File Control.h
#include<unistd.h>      //Only Linux Based
#include<string.h>

int main()
{
    int fd = 0;                     //File Descriptor 
    int iRet = 0;
    char Data[] = "Marvellous InfoSystems";

    fd = open("Marvellous.txt",O_CREAT,O_RDWR | O_APPEND);

    if(fd == -1)
    {
        printf("Unable to Open File!");
    }
    else
    {
        printf("File Gets Sucessfully Opened with fd: %d\n",fd);
     
        iRet = write(fd,Data,strlen(Data));

        printf("%d Bytes Gets Successfully Return\n",iRet);

        close(fd);
    }

    return 0;
}