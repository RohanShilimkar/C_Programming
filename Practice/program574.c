#include<stdio.h>
#include<fcntl.h>       //File Control.h

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
    }

    return 0;
}