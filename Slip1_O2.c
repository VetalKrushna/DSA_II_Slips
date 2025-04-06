/*Q 2) Implement a Binary search tree (BST) library (btree.h) with operations – create, insert, preorder.
Write a menu driven program that performs the above operations. */

#include<stdlib.h>
#include<stdio.h>

struct node
{
    int data;
    struct node *left,*right;
};
int n,i,j;


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
struct node* create(struct node *root)
{
    struct node*temp,*newnode,*parent;
    int i,n;
    printf("Enter limit:");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
           newnode=(struct node*)malloc(sizeof(struct node));
           printf("Enter value:");
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
                if(newnode->data > temp->data )
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

    }
    return root;
   
}
void Preorder(struct node*root)
{
    struct node*temp=root;
    if(temp!=NULL)
    {
        printf("%d\t",temp->data);
        Preorder(temp->left);
        Preorder(temp->right);
    }
}
int main()
{
    int ch;
    struct node*root=NULL;
    do{

        printf("\n1-Create\n2-Insert\n3-Preorder\n4-Exit\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:root=create(NULL);
                    break;
            case 2:root=Insert(root);
                    break;
            case 3:Preorder(root);
                    break;        
        }
    }while(ch<4);
}