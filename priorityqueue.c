#include <stdio.h>
#include <stdlib.h>
#define MAX 6
void insert_by_priority(int);
void delete_by_priority(int);
void create();
void check(int);
void display_priorityqueue();
int prique[MAX];
int front,rear;
void main()
{
    int n,ch;
    printf("\n1 - To Insert an element into queue");
    printf("\n2 - To Delete an element from queue");
    printf("\n3 - To Display queue elements");
    printf("\n4 - Exit");
    create();
    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter value to be inserted : ");
            scanf("%d",&n);
            insert_by_priority(n);
            break;
        case 2:
            printf("\nEnter value to be deleted : ");
            scanf("%d",&n);
            delete_by_priority(n);
            break;
        case 3:
            display_priorityqueue();
            break;
        case 4:
            exit(0);
        default:
            printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
}
void create()
{
    front=rear=-1;
}
void insert_by_priority(int data)
{
    if(rear>=MAX-1)
    {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }
    if((front==-1)&&(rear==-1))
    {
        front++;
        rear++;
        prique[rear] = data;
        return;
    }
    else
        check(data);
    rear++;
}
void check(int data)
{
    int i,j;
    for (i=0;i<=rear;i++)    {
        if (data>=prique[i])
        {
            for (j=rear+1;j > i;j--)
            {
                prique[j]=prique[j-1];
            }
            prique[i] = data;
            return;
        }
    }
    prique[i]=data;
}
void delete_by_priority(int data)
{
    int i;
    if ((front==-1)&&(rear==-1))
    {
        printf("\nQueue is empty no elements to delete");
        return;
    }
    for (i =0;i <=rear;i++)
    {
        if (data==prique[i])
        {
            for (;i<rear;i++)
            {
                prique[i] = prique[i + 1];
            }
        prique[i] =-99;
        rear--;
        if (rear==-1)
            front = -1;
        return;
        }
    }
    printf("\n%d not found in queue to delete", data);
}
void display_priorityqueue()
{
    if((front==-1)&&(rear==-1))
    {
        printf("\nQueue is empty");
        return;
    }
    for (; front<=rear;front++)
    {
        printf(" %d ",prique[front]);
    }
    front = 0;
}
