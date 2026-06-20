#include<stdio.h>

int main()
{
    
    float fValue1 = 0.0f;                               // To store First input
    float fValue2 = 0.0f;                               // To store Second input
    float fResult = 0.0f;                               // To store the Result

    printf("\nEnter First Number: ");
    scanf("%f",&fValue1);

    printf("\nEnter Second Number: ");
    scanf("%f",&fValue2);

    fResult = fValue1 + fValue2;                        // Perform the Addition

    printf("Addition is: %f",fResult);
    
    return 0;
}