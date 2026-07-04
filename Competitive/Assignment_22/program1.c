#include<stdio.h>

void Pattern(int iNo)
{
    int iCnt=0;
    for(iCnt=0;iCnt<iNo;iCnt++)
    {
        printf("%c",(97-32)+iCnt);
    }
}
/*
void Pattern(int iNo)
{
    char ch = 'A';
    int iCnt=0;
    for(iCnt=0;iCnt<iNo;iCnt++)
    {
        printf("%c",'A'+iCnt);
    }
    
}
*/

/*
void Pattern(char cArr[],int iNo)
{
    int iCnt=0;  
    char ch= 'A';
    for(iCnt=0;iCnt<iNo;iCnt++)
    {
        cArr[iCnt] = 'A'+iCnt;
    }
    
    cArr[iCnt] = '\0';
}
*/

int main()
{
    int iValue = 0;
    
    printf("Enter a Number:");
    scanf("%d",&iValue);
    
    Pattern(iValue);
    return 0;
} 
/*
int main()
{
    int iValue = 0;
    char cArr[iValue];
    
    printf("Enter a Number:");
    scanf("%d",&iValue);
    
    
    Pattern(cArr,iValue);
    printf("%s",cArr);
    
    return 0;
} 
*/