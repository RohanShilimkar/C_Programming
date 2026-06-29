#include<stdio.h>

void CallByAddress(int *iPtr)   //Callie
{
    (*iPtr)++;

}

int main()
{
    int iValue = 11;

    CallByAddress(&iValue); // CALLER

    printf("Value After function call:%d",iValue);

    
    return 0;
}