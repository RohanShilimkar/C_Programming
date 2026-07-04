#include<stdio.h>
void Pattern(int iRow,int iCol)
{
    int i=0,j=0;
    char ch ='A';

    for(i=1;i<=iRow;i++)
    {
        for(j=1,ch='A';j<=iCol;j++)
        {
            printf("%c",ch);
            ch++;
        }
        printf("\n");
    }
}

int main()
{
    int iValue1=0,iValue2=0;

    printf("Enter How many Rows:");
    scanf("%d",&iValue1);

    printf("Enter How Many Columns:");
    scanf("%d",&iValue2);

    Pattern(iValue1,iValue2);

    return 0;
}