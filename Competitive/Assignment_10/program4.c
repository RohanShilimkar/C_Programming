#include<stdio.h>


double FHtoCS(float fTemp)
{
    float fCelsius=0.0f;

    fCelsius = (fTemp-32)* 5/9;

    return fCelsius;
}


int main()
{
    float fValue=0.0f;
    double dRet=0.0;

    printf("Enter temperature in Fahrenheit:");
    scanf("%f",&fValue);

    dRet = FHtoCS(fValue);

    printf("Temperature in Celcius is:%lf",dRet);

    return 0;

}