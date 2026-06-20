/*
        Start
            Accept numberas no

            if no is completely divisble by 2them print even
            otherwise print odd

        stop


        Start
            Accept number as no
            
            Divide no by 20
            if remainder is 0
                 print as even 
            othrewise
                print as odd


        stop
*/



#include<stdio.h>

int main()
{
    int iValue = 0;
    int iRemainder=0;

    printf("Enter a Number:");
    scanf("%d",&iValue);

    iRemainder = iValue % 2;

    if(iRemainder == 0)
        printf("Number is Even");
    else
        printf("Number is Odd");


    return 0;
}