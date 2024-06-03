#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
void insert(struct node **head, int val, struct node **tail);
void Delete(struct node **head, int val, struct node **tail);
void display(struct node *head, struct node *tail);
void main()
{
    struct node *head = NULL;
    struct node *tail = NULL;
    int key, val;

    do{
        printf("press 1 to enter the value, 2 to delete, 3 to display, 4 to end");
        scanf("%d", &key);
        switch(key)
        {
        case 1:
            printf("enter the value to be inserted: ");
            scanf("%d", &val);
            insert(*head, val);
            break;
        case 2:
            printf("enter the value to be deleted: ");
            scanf("%d", &val);
            Delete(*head, val);
            break;
        case 3:
            printf("the list is:\n");
            display(head);
        }
    }while(key!=4);
}

void insert(struct node **head, int val, struct node **tail)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if(*head==NULL)
    {
        newNode->data=val;
        newNode->next=*head;
        newNode->prev=*head;
        *head=newNode;
        *tail=newNode;
    }
    else
    {
        newNode->data=val;
        *tail->next=newNode;
        newNode->prev=*tail;
        newNode->next=*head;
        *head->prev=newNode;
        *tail=newNode;
    }
}
void Delete(struct node **head, int val, struct node **tail)
{

}
