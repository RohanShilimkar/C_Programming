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

BOOL Search(PNODE first ,int iNo)
{
    while(first != NULL)
    {
        if(first->data == iNo)
        {
            break;
        }
        first = first->next;
    }

    if(first == NULL)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

int main()
{

    PNODE head = NULL;
    BOOL bRet = FALSE;

    InsertLast(&head,40);
    InsertLast(&head,30);
    InsertLast(&head,20);
    InsertLast(&head,10);

    bRet = Search(head,60);
    
    if(bRet == TRUE)
    {
        printf("Number is Present!");
    }
    else
    {
        printf("Number is Not Present!");
    }

    return 0;

}