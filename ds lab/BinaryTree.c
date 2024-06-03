#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *lc;
    struct node *rc;
};
struct node *newNode(int val)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    createNode->data = val;
    createNode->lc=NULL;
    createNode->rc=NULL;
    return createNode;
};
void insertNode(struct node **root)
{
    printf("Enter the value to be entered in root node:\n");
    int val;
    scanf("%d", &val);
    *root->data=val;
    printf("Enter the value to be inserted in left child of %d:\n", (*root)->data);
    scanf("%d", &val);
    (*root)->left = newNode(val);
    printf("Enter the value to be inserted in right child of %d:\n", (*root)->data);
    scanf("%d", &val);
    (*root)->right = newNode(val);

}
void inorderTraverse(struct node *root)
{
    if(root!=NULL)
    {
        inorderTraverse(root->lc);
        printf("%d ", root->data);
        inorderTraverse(root->rc);
    }
}
struct node *findMin(struct node *Node)
{
    while(Node->lc!=NULL)
    {
        Node=Node->lc;
    }
    return Node;
};
struct node *deleteNode(struct node *root, int key)
{
    if(root==NULL)
    {
        return root;
    }
    if(root->data < key)
    {
        root->lc=deleteNode(root->lc,key);
    }
    else if(root->data>key)
    {
        root->rc=deleteNode(root->rc,key);
    }
    else
    {
        if(root->lc==NULL)
        {
            struct node *temp = root->rc;
            free(root);
            return temp;
        }
        else if(root->rc==NULL)
        {
            struct node *temp = root->lc;
            free(root);
            return temp;
        }
        struct node *temp = findMin(root->rc);
        root->data=temp->data;
        root->rc=deleteNode(root->rc,temp->data);
        return root;
    }
}
void main()
{
    struct node *root = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data of root: ");
    int val;
    scanf("%d", &val);
    root->data=val;
    root->lc=NULL;
    root->rc=NULL;
    insertNode(root);
    printf("the entered binary tree is: ");
    inorderTraverse(root);
}
