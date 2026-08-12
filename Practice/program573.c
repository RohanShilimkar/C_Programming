#include<stdio.h>
#include<fcntl.h>       //File Control.h

int main()
{
    int fd = 0;                     //File Descriptor 

    
    fd = open("Marvellous.txt",O_CREAT);

    if(fd == -1)
    {
        printf("Unable to Create File!");
    }
    else
    {
        printf("File Gets Sucessfully Created with fd:%d\n",fd);

    }

    return 0;
}