#include<stdio.h>

#define PI 3.14

double CircleArea(float fRadius)
{
    float fArea  = 0.0f;

    fArea = PI *fRadius * fRadius;

    return fArea;

}


int main()
{
    float fValue=0.0f;
    double fRet=0.0;

    printf("Enter a Radius:");
    scanf("%f",&fValue);

    fRet = CircleArea(fValue);

    printf("Area Of Circle is:%f",fRet);
    return 0;
    
}