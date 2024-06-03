#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
int size;
int top;
char *str;
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
void push(char input,struct stack *s)
{
   if(isFull(s))
   {
       printf("Stack overload\n");
   }
   else
   {
       s->top++;
       s->str[s->top]=input;
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
        char val = s->str[s->top];
        s->top--;
    }
}
void palindrome(struct stack *s)
{
    int key=1;
    for(int i=0;i<=(s->top)/2;i++)
    {
        if(s->str[i]!=s->str[(s->top)-i])
        {
            key=0;
            break;
        }
    }
    if (key==1)
    {
        printf("its a palindrome");
    }
    else{
        printf("its not a palindrome");
    }
}
void main()
{
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->size=100;
    s->top=-1;
    s->str=(char *)malloc(s->size*sizeof(char));
    char input[s->size];
    printf("Enter the string\n");
    scanf ("%s", input);
    for(int i=0;i<s->size;i++)
    {
        push(input[i], s);
    }
    palindrome(s);
    free(s->str);
    free(s);
}

