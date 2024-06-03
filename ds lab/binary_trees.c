#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *lc;
    struct node *rc;
};
struct node *createNode(int val)
{
   struct node *newNode = (struct node*)malloc(sizeof(struct node));
   newNode->data=val;
   newNode->lc=NULL;
   newNode->rc=NULL;
   return newNode;
}
struct node *insertNode(struct node *root,int val);
void inorderTraverse(struct node *root);
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
struct node *deleteNode(struct node *root, int key)
{
    if(root==NULL)
    {
        return root;
    }
    if(key< root->data)
    {
        root->lc = deleteNode(root->lc, key);
    }
    else if(key> root->data)
    {
        root->rc = deleteNode(root->rc, key);
    }
    else{
        if(root->lc == NULL)
        {
            struct node *temp = root->rc;
            free(root);
            return temp;
        }
        else if(root->rc == NULL)
        {
            struct node *temp = root->lc;
            free(root);
            return temp;
        }
        struct node *temp = findMin(root->rc);
        root->data=temp->data;
        root->rc=deleteNode(root->rc, temp->data);
    }
    return root;
};
struct node *findMin(struct node *root)
{
    while(root->lc != NULL)
    {
        root=root->lc;
    }
    return root;
};
void main()
{
    printf("Enter the value of the root node: ");
    int val,num;
    scanf("%d", &val);
    struct node *root = createNode(val);
    printf("Enter the no. of nodes to be entered: ");
    scanf("%d", &num);
    for(int i=0;i<num;i++)
    {
        printf("Enter the value: ");
        scanf("%d", &val);
        insertNode(root,val);
    }
    printf("press 1 for inorder, 2 for postorder, 3 for preorder");
    int key;
    scanf("%d", &key);
    switch(key)
    {
    case 1:
        printf("inorder traversal: ");
        inorderTraverse(root);
        break;
    case 2:
        printf("preorder traversal: ");
        preorderTraverse(root);
        break;
    case 3:
        printf("postorder traversal: ");
        postorderTraverse(root);
        break;
    }
}
struct node *insertNode(struct node *root,int data)
{
    if(root==NULL)
    {
        return createNode(data);
    }
    if(data<root->data)
    {
        root->lc = insertNode(root->lc,data);
    }
    else if(data>root->data)
    {
        root->rc = insertNode(root->rc,data);
    }
    return root;
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
void preorderTraverse(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ", root->data);
        inorderTraverse(root->lc);
        inorderTraverse(root->rc);
    }
}
void postorderTraverse(struct node *root)
{
    if(root!=NULL)
    {
        inorderTraverse(root->lc);
        inorderTraverse(root->rc);
        printf("%d ", root->data);
    }
}
