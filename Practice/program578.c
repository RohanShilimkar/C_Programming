#include<stdio.h>
#include<fcntl.h>      //File Control.h
#include<unistd.h>      //Only Linux Based

int main()
{
    int fd = 0;                     //File Descriptor 
    int iRet = 0;
    
    fd = open("Marvellous.txt",O_RDWR | O_APPEND);

    if(fd == -1)
    {
        printf("Unable to Open File!");
    }
    else
    {
        printf("File Gets Sucessfully Opened with fd: %d\n",fd);
     
        iRet = write(fd,"Jay Ganesh...",13);

        printf("%d Bytes Gets Successfully Return\n",iRet);

        close(fd);
    }

    return 0;
}