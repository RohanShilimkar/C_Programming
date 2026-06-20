#include<stdio.h>

float AddTwoNumbers(float fNo1,float fNo2)
{
    float fAns=0.0f;

    fAns = fNo1 + fNo2;

    return fAns;

}

int main()
{
    
    float fValue1 = 0.0f;                               // To store First input
    float fValue2 = 0.0f;                               // To store Second input
    float fResult = 0.0f;                               // To store the Result

    printf("\nEnter First Number: ");
    scanf("%f",&fValue1);

    printf("\nEnter Second Number: ");
    scanf("%f",&fValue2);

    fResult = AddTwoNumbers(fValue1,fValue2);

    printf("Addtion is %f",fResult);
                                                         
    
    return 0;
}