#include<stdio.h>

void Pattern(int iRow,int iCol)
{
    int i=0,j=0;
    char ch1='A';
    char ch2 = 'a';

    for(i=1;i<=iRow;i++)
    {
       
        for(j=1,ch1='A',ch2='a';j<=iCol;j++)
        {
          if((i%2)==0)
          {
            printf("%c",ch2);
            ch2++;
          }        
        else
        {
            printf("%c",ch1);
            ch1++;
        }
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