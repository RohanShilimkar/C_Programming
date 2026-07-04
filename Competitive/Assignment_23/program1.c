#include<stdio.h>

void Pattern(int iRow,int iCol)
{
    int iCnt=0;
    int iCnt2=0;

    for(iCnt=1;iCnt<=iRow;iCnt++)
    {
        for(iCnt2=0;iCnt2<iCol;iCnt2++)
        {
            printf(" * ");
        }
        
        printf("\n");
    }

}

int main()
{
    int iValue1=0,iValue2=0;

    printf("Enter Number of rows:");
    scanf("%d",&iValue1);
        
    printf("Enter Number of Columns:");
    scanf("%d",&iValue2);

    Pattern(iValue1,iValue2);

    return 0;
}