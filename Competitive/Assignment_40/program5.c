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

int CountLess(PNODE first,int iNo)
{
    int i = 0;

    while(first != NULL)
    {
        if(first->data < iNo)
        {
            i++;
        }
        first = first->next;
    }
    return i;
}
int main()
{
    PNODE head = NULL;
    int iRet = 0;
    
    InsertLast(&head,30);
    InsertLast(&head,56);
    InsertLast(&head,63);
    InsertLast(&head,10);


    iRet = CountLess(head,40);

    printf("\nNumber Less than are: %d",iRet);
   
    return 0;
}