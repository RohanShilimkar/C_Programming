#include<stdio.h>

int Factorial(int iNo)
{
  int iCnt=0;
  int iFact=1;
  
  if(iNo<0)
  {
    iNo = -iNo;
  }

  for(iCnt=1;iCnt<=iNo;iCnt++)
  {
    iFact = iFact * iCnt;
  }

  return iFact;

  /*
      iCnt =1;
      while(iCnt<=iNo)
      {  
        iFact = iFact * iCnt;
        iCnt++;
      }
  */
}

int main()
{
  int iValue=0,iRet=0;

  printf("Enter a Number;");
  scanf("%d",&iValue);

  iRet = Factorial(iValue);

  printf("factoraial of Number is:%d",iRet);


  return 0;

}