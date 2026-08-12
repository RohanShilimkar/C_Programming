#include<stdio.h>
#include<fcntl.h>      //File Control.h
#include<unistd.h>      //Only Linux Based

int main()
{
    int fd = 0;                     //File Descriptor 

    fd = open("Marvellous.txt",O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to Open File!");
    }
    else
    {
        printf("File Gets Sucessfully Opened with fd: %d\n",fd);

        close(fd);
    }

    return 0;
}