#include<stdio.h>

void CallByValue(int iNo)
{
    iNo++;
}

int main()
{
    int iValue = 11;

    CallByValue(iValue);

    printf("Value After function call:%d",iValue);

    
    return 0;
}