#include<stdio.h>

int MultFact(int iNo)
{

    int i = 0;
    int mul =1;

    if(iNo<=0){
        iNo = -iNo;
    }

    for(i=1;i<iNo;i++)
    {
        if((iNo%i==0))
        {
            mul = mul * i ;

        }
    }
    return mul;
}


int main() 
{
    int iValue = 0;
    int iRet = 0;

    printf("Enter a number:");
    scanf("%d",&iValue);

    iRet = MultFact(iValue);

        printf("Multiplication Of Factors is:%d",iRet);
     
    return 0;

}