#include<stdio.h>
#include<stdlib.h>
struct time
{
    int hour;
    int min;
    int sec;
};
void readTime(struct time *t);
void logic(struct time *t);
void displayTime(struct time t);
void main()
{
    struct time t;
    printf("Enter the details: ");
    readTime(&t);
    logic(&t);
    displayTime(t);
}
void readTime(struct time *t)
{
        printf("Enter hour:\n");
        scanf("%d", &t->hour);
        printf("Enter minutes:\n");
        scanf("%d", &t->min);
        printf("Enter seconds:\n");
        scanf("%d", &t->sec);
}
void logic(struct time *t)
{
    int h, m, s, AddSub;
    printf("if subtract time then press 1 if add press 2\n");
    scanf("%d", &AddSub);
    switch(AddSub)
    {
    case 1 :
        printf("\nEnter hour: ");
        scanf("%d", &h);
        t->hour=t->hour+h;
        printf("\nEnter min: ");
        scanf("%d", &m);
        t->min=t->min+m;
        printf("\nEnter sec: ");
        scanf("%d", &s);
        t->sec=t->sec+s;
        break;
    case 2:
        printf("\nEnter hour: ");
        scanf("%d", &h);
        t->hour=t->hour-h;
        printf("\nEnter min: ");
        scanf("%d", &m);
        t->min=t->min-m;
        printf("\nEnter sec: ");
        scanf("%d", &s);
        t->sec=t->sec-s;
        break;
    }
void displayTime(struct time t)
    {
        printf("new time is: ");
        printf("%d:%d:%d", t.hour,t.min,t.sec);
    }
}
