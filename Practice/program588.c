#include<stdio.h>
#include<fcntl.h>      //File Control.h
#include<unistd.h>      //Only Linux Based
#include<string.h>


#define BUFFER_SIZE 100

int main()
{
    int fd = 0;                     //File Descriptor 
    int iRet = 0;
    char Data[BUFFER_SIZE] = {'\0'};


    fd = open("Marvellous.txt",O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to Open File!");
    }
    else
    {
        lseek(fd,5,0);

        iRet = read(fd,Data,10);

        printf("%d Byte gets Read Succesfully",iRet);

        printf("\nData From File is %s",Data);
        
        close(fd);


        ///////////////////////////////////////////////////////

        memset(Data,'\0',sizeof(Data));
        
        lseek(fd,5,1);

        iRet = read(fd,Data,10);

        printf("\n%d Byte gets Read Succesfully",iRet);

        printf("\nData From File is %s",Data);
    }

    return 0;
}