#include<stdio.h>

float AddTwoNumbers(
                        float fNo1,                      // first Input
                        float fNo2                       // Second Input
                    )
{
    float fAns=0.0f;                                     //Variable To store result

    fAns = fNo1 + fNo2;                                  // Perform Addition

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

    fResult = AddTwoNumbers(fValue1,fValue2);           //

    printf("Addtion is %f",fResult);
                                                         
    
    return 0;
}