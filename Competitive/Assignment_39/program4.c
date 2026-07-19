#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

struct node
{
    int data;
    struct node *next;

};
typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;
typedef int BOOL;

void InsertLast(PPNODE first,int iNo)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn  = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;

    }

}

int CountFreq(PNODE first,int iNo)
{
    int iFreq = 0;

    while(first != NULL)
    {
        if(first->data == iNo)
        {
            iFreq++;
        }
        first = first->next;
    }
    return iFreq;
}

int main()
{

    PNODE head = NULL;
    int iRet = 0;

    InsertLast(&head,10);
    InsertLast(&head,10);
    InsertLast(&head,20);
    InsertLast(&head,10);

    iRet = CountFreq(head,10);

    printf("\nNumber of Occurs : %d",iRet);
    
   
    return 0;

}