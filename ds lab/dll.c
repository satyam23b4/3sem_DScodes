#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void insert(struct node **head, int data);
void Delete(struct node **head, int data);
void display(struct node *head);
void main()
{
    struct node *head = NULL;
    int key,val;
    do{
        printf("enter 1 for inserting, 2 for deleting, 3 for reversing, 4 for displaying, 5 for exiting\n");
        scanf("%d", &key);
        switch(key)
        {
        case 1:
            printf("enter the value to be inserted: ");
            scanf("%d", &val);
            insert(&head,val);
            break;
        case 2:
            printf("enter the value to be deleted: ");
            scanf("%d", &val);
            Delete(&head,val);
            break;
        case 3:
            printf("linked list reversed\n");
            reverse(&head);
            break;
        case 4:
            printf("the inserted linked list is: ");
            display(head);
            break;
        }
    }while(key!=5);

}
void insert(struct node **head,int val)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if((*head)==NULL)
    {
        newNode->next = NULL;
        newNode->prev=NULL;
        newNode->data = val;
        *head = newNode;
    }
    else{
        newNode->data = val;
        newNode->next = (*head);
        newNode->prev = NULL;
        (*head)->prev = newNode;
        *head=newNode;
    }
}
void Delete(struct node **head, int val) {
    struct node *current = *head;

    while (current != NULL && current->data != val) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Value not found.\n");
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
}
void display(struct node *head)
{
    struct node *p = head;
    while(p!=NULL)
    {
        printf("%d", p->data);
        p=p->next;
    }printf("\n");
}
void reverse(struct node **head)
{
    struct node *current=*head;
    struct node *temp=NULL;
    while(current!=NULL)
    {
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }
    if(temp!=NULL)
    {
        *head=temp->prev;
    }
    else
    {
        head=temp;
    }
}
