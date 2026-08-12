#include<stdio.h>
#include<fcntl.h>      //File Control.h
#include<unistd.h>      //Only Linux Based
#include<string.h>


#define BUFFER_SIZE 100

int main()
{ 
    unlink("Marvellous.txt");
   
    return 0;
}