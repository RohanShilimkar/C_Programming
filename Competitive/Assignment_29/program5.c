#include<stdio.h>

void DisplaySchedule(char ch)
{
    if(ch=='A' || ch == 'a')
    {
        printf("Your Exam Is At 7 AM ");
    }
    else if(ch=='B' || ch == 'b')
    {
        printf("Your Exam Is At 8:30 AM");
    }
    else if(ch=='C'|| ch == 'c')
    {
        printf("Your Exam Is At 9:20 AM");
    }
    else
    {
        printf("Your Exam Is At 10:30 AM");
        
    }
}
int main()
{
    char cValue = '\0';

    printf("Enter the Character:");
    scanf("%c",&cValue);

    DisplaySchedule(cValue);

    return 0;

}