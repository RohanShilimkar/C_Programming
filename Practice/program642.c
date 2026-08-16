#include<stdio.h>
#include<stdlib.h>


int main()
{
    #ifdef _WIN32
        printf("Project is Running on Windows Platform\n");
    #else 
        printf("Project is Running on Linux/MacOS Platform");    
    #endif


        

    return 0;
}