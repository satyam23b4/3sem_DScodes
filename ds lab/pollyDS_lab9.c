#include<stdio.h>
#include<stdlib.h>
struct node
{
    int exp;
    int coeff;
    struct node *next;
};
struct node *createNode(int pow,int coef)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->exp = pow;
    newNode->coeff = coef;
    newNode->next = NULL;
    return newNode;
};
void insertNode(int n, struct node **head1, struct node **head2);
void display(struct node *head1, struct node *head2, int n);
//void Add(struct node *head1, struct node *head2);
void add(struct node *head1, struct node *head2, int n);
void main()
{
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    printf("Enter the highest exponent among the polynomials: ");
    int n;
    scanf("%d", &n);
    insertNode(n, &head1, &head2);
    display(head1,head2,n);
    add(head1, head2, n);
    //Add(head1,head2);
}
void insertNode(int n, struct node **head1, struct node **head2)
{
    printf("Enter the coefficients for the first polynomial: ");
    int coef;
    struct node *curr1;
    struct node *curr2;
    for(int i=0;i<=n;i++)
    {
        printf("coeff of x^%d : ", i);
        scanf("%d", &coef);
        if(i==0)
        {
            *head1 = createNode(i,coef);
            curr1=*head1;
        }
        else
        {
            curr1->next=createNode(i,coef);
            curr1=curr1->next;
        }
    }
    printf("Enter the coefficients for the second polynomial: ");
    for(int i=0;i<=n;i++)
    {
        printf("coeff of x^%d : ", i);
        scanf("%d", &coef);
        if(i==0)
        {
            *head2 = createNode(i,coef);
            curr2=*head2;
        }
        else
        {
            curr2->next=createNode(i,coef);
            curr2=curr2->next;
        }
    }
}
void display(struct node *head1, struct node *head2, int n)
{
    struct node *curr1=head1;
    struct node *curr2=head2;

    printf("first polynomial is:\n");
    while(curr1 != NULL)
    {
        printf(" %dx^%d +", curr1->coeff, curr1->exp);
        curr1=curr1->next;
    }
    printf("second polynomial is:\n");
    while(curr2 != NULL)
    {
        printf(" %dx^%d +", curr2->coeff, curr2->exp);
        curr2=curr2->next;
    }
    printf("\n");

}
void add(struct node *head1, struct node *head2, int n)
{
    struct node *curr1 = head1;
    struct node *curr2 = head2;
    struct node *head3 = NULL;
    struct node *curr3;
    for(int i=0;i<=n;i++)
    {
        if(i==0)
        {
            head3=createNode(i, (head1->coeff)+(head2->coeff));
            curr3=head3;
        }
        else
        {
            curr1=curr1->next;
            curr2=curr2->next;
            curr3->next=createNode(i,(curr1->coeff)+(curr2->coeff));
            curr3=curr3->next;
        }
    }
    printf("the addition of the polynomials is: ");
    curr3=head3;
    while(curr3 !=NULL)
    {
        printf(" %dx^%d +", curr3->coeff, curr3->exp);
        curr3=curr3->next;
    }
}
