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

int CountEven(PNODE first)
{
    int iEven = 0;

    while(first != NULL)
    {
        if((first->data % 2) == 0)
        {
            iEven++;
        }
        first = first->next;
    }
    return iEven;
}

int main()
{

    PNODE head = NULL;
    int iRet = 0;

    InsertLast(&head,40);
    InsertLast(&head,77);
    InsertLast(&head,20);
    InsertLast(&head,10);

    iRet = CountEven(head);

    printf("\nEven Number of Nodes are: %d",iRet);
    
   
    return 0;

}