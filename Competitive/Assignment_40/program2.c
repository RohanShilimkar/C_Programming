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

void Insert(PPNODE first,int iNo)
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

int FirstOccur(PNODE first,int iNo)
{
    int i = 1;
    while(first != NULL)
    {
        if(first->data == iNo)
        {
            break;
        }
        i++;
        first = first->next;
    }
    return i;
}
int main()
{
    PNODE head = NULL;
    int iRet = 0;
    
    Insert(&head,40);
    Insert(&head,10);
    Insert(&head,33);
    Insert(&head,20);

    iRet = FirstOccur(head,10);

    printf("\n%d",iRet);
   
    return 0;
}