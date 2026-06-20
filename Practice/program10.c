///////////////////////////////////////////////////////
//
// Include Required Header Files
//
//////////////////////////////////////////////////////


#include<stdio.h>

////////////////////////////////////////////////////////
//
//      Function Name : AddTwoNumbers
//      Input :         float.float
//      Output:         float
//      Description:    Performs Addition of 2 floats
//      Date :          08/05/2026
//      Author:         Rohan Rajan Shilimkar
//
///////////////////////////////////////////////////////

float AddTwoNumbers(
                        float fNo1,                      // first Input
                        float fNo2                       // Second Input
                    )
{
    float fAns=0.0f;                                     //Variable To store result

    fAns = fNo1 + fNo2;                                  // Perform Addition

    return fAns;

}

////////////////////////////////////////////////////////
//
//      Application to perform Addition of 2 floats values
//
////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////
//
// Input : 10.0  11.0
// Output: 21.0
//
///////////////////////////////////////////////////////

