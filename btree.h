
#include<stdio.h>
#include<stdlib.h>

#define memory (struct node*)malloc(sizeof(struct node))

typedef struct node
{
    int data;
    struct node*right,*left;
}NODE;
NODE *create(NODE *root)
{
    int i,j,n;
    NODE *temp,*newnode,*parent;
    printf("Enter node limit:");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter value:");
        newnode=memory;
        scanf("%d",&newnode->data);
        newnode->left=newnode->right=NULL;

        if(root==NULL)
        {
            root=newnode;
            continue;
        }
        temp=root;
        while(temp!=NULL)
        {
            parent=temp;

            if(newnode->data > temp->data)
              {
                temp=temp->right;
              }
              else
              {
                temp=temp->left;
              }
        }
        if(newnode->data > parent->data)
        {
            parent->right=newnode;
        }
        else
        {
            parent->left=newnode;
        }
    }
    return root;

}

void Search(NODE*root,int num)
{
    int f=0;
    NODE *temp=root;
  
    while(temp!=NULL)
    {
        if(num==temp->data)
        {
           f=1;
           break;
        }
        else if(num > temp->data)
        {
            return Search(temp->right,num);
        }
        else if(num < temp->data)
        {
            return Search(temp->left,num);
        }
    }
     if(f==1)
    {
        printf("Found...");
    }
    else
    {
        printf("Not found...");
    }
}

void Inorder(NODE *root)
{
    NODE * temp=root;
    if(temp!=NULL)
    {
        Inorder(temp->left);
        printf("%d\t",temp->data);
        Inorder(temp->right);
    }
}

void Postorder(NODE*root)
{
    NODE*temp=root;
    if(temp!=NULL)
    {
        Postorder(temp->left);
        Postorder(temp->right);
        printf("%d\t",temp->data);
    }
}

struct node* Insert(struct node *root)
{
    struct node *newnode,*temp,*parent;
    int num;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->left = newnode->right = NULL;
      
    printf("Enter number to insert:");
    scanf("%d",&newnode->data);

    if(root==NULL)
    {
        root=newnode;
        return root;
    }
    temp=root;
    while(temp!=NULL)
    {
        parent=temp;
        if(newnode->data > temp->data)
        {
            temp=temp->right;
        }
        else
        {
            temp=temp->left;
        }
    }
    if(newnode->data > parent->data)
          parent->right=newnode;
        else
          parent->left=newnode;

 printf("\nValue inserted Successfully..........");
 return root;
}