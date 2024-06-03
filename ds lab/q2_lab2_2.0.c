#include<stdio.h>
#include<stdlib.h>
struct student
{
    char name[50];
    int rollNo;
    char grade[2];
};
void readStudent(struct student s[], int n);
void sortStudent(struct student s[], int n);
void displayStudent(struct student s[], int n);
void main()
{
    int i,n;
    struct student s[10];
    printf("Enter the number of students: ");
    scanf("%d", &n);
    printf("Enter the details of the students:\n");
    readStudent(s,n);
    sortStudent(s,n);
       printf("The sorted list of students is: ");
    displayStudent(s,n);
}
void sortStudent(struct student s[], int n)
{
    int i,j;
    struct student temp;
    for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(s[i].rollNo>s[j].rollNo)
                {
                    temp=s[i];
                    s[i]=s[j];
                    s[j]=temp;
                }
            }
        }
}
void displayStudent(struct student s[], int n)
{
    int i;
    for(i=0;i<n;i++)
       {
           printf("name is: %s\n", s[i].name);
           printf("roll no is: %d\n", s[i].rollNo);
           printf("grade is: %s\n", s[i].grade);
       }
}
void readStudent(struct student s[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter name:\n");
        scanf("%s", s[i].name);
        printf("Enter roll no:\n");
        scanf("%d", &s[i].rollNo);
        printf("Enter grade:\n");
        scanf("%s", s[i].grade);
    }
}
