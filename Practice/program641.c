#include<stdio.h>

#include<stdlib.h>



int main()
{
    #ifdef _WIN32
        system("dir");
    #elif
        system("ls");
    #endif
        

    return 0;
}