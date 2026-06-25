#include<stdio.h>

int RangeSum(int iStart,int iEnd)
{
    int iCnt =0;
    int iSum=0;

    if(iStart < 0 || iEnd <0 )
    {
        return -1;
    }
    
    

    for(iCnt=iStart;iCnt<=iEnd;iCnt++)
    {
        if(iCnt % 2 == 0){
            iSum = iSum + iCnt;
        }
    } 

    return iSum;
}

int main()
{
    int iValue1=0,iValue2=0;
    int iRet = 0;


    printf("Enter Start:");
    scanf("%d",&iValue1);

    
    printf("Enter End:");
    scanf("%d",&iValue2);

    iRet = RangeSum(iValue1,iValue2);

    if(iRet == -1)
    {
        printf("Enter Positive Number Only!");
    }
    else{
        printf("Addition is:%d",iRet);
    }
    return 0;

}