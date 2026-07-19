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

int LastOccur(PNODE first,int iNo)
{
    int i = 1;
    int iLast = -1;

    while(first != NULL)
    {
        if(first->data == iNo)
        {
         iLast = i;   
        }
        i++;
        first = first->next;
    }
    return iLast;
}
int main()
{
    PNODE head = NULL;
    int iRet = 0;
    
    InsertLast(&head,40);
    InsertLast(&head,10);
    InsertLast(&head,33);
    InsertLast(&head,10);


    iRet = LastOccur(head,10);

    printf("\nFirst Occurence is at postion: %d",iRet);
   
    return 0;
}