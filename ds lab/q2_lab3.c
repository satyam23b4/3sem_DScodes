#include<stdio.h>
#include<stdlib.h>
struct stack{
int size;
int top;
int *arr;
};
int isEmpty(struct stack *s)
{
    if(s->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *s)
{
    if(s->top==s->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(int input,struct stack *s)
{
   if(isFull(s))
   {
       printf("Stack overload\n");
   }
   else
   {
       s->top++;
       s->arr[s->top]=input;
   }
}
void pop(struct stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack underflow\n");
    }
    else
    {
        int val = s->arr[s->top];
        s->top--;
    }
}
void base(int n,struct stack *s)
{
    int b,input;
    printf("enter the base:\n");
    scanf("%d", &b);
    while(n!=0)
    {
        input=n%b;
        n=n/b;
        push(input,s);
    }
}
void display(struct stack *s)
{
    for(int i=0;i<s->top;i++)
    {
        printf("%d", s->arr[i]);
    }
}
void main()
{
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->size=10;
    s->top=-1;
    s->arr=(int *)malloc(s->size*sizeof(int));
    int input[s->size];
    printf("Enter the no.");
    int n;
    scanf("%d", &n);
    base(n,s);
    display(s);
    free(s->arr);
    free(s);
}
