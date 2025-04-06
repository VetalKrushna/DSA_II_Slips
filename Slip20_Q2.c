/*Q 2) Write a program which uses binary search tree library and count the total nodes and total leaf nodes in
the tree.int countLeaf(T) – returns the total number of leaf nodes from BST */

#include<stdio.h>
#include"btree.h"
int countLeaf(NODE*root)
{
    NODE*temp=root;
    static int cnt=0;
    if(temp!=NULL)
     {
        if(temp->left==NULL && temp->right==NULL)
        {
            cnt++;
        }
        countLeaf(temp->left);
        countLeaf(temp->right);
    }
    return cnt;
}

int counttotalnode(NODE*root)
{
    static int cnt=0;
    NODE*temp=root;
    if(temp!=NULL)
    {
        cnt++;
        counttotalnode(temp->left);
        counttotalnode(temp->right);
    }
    return cnt;
}

int main()
{
    int ch;
    NODE*root=NULL;
    do
    {
       
        printf("\n1-Create\n2-Display\n3-Count Leaf Node\n4-Count total Node\nEnter choic:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:root=create(root);
            break;
        case 2:Inorder(root);
                break;
        case 3:printf("Leaf Node:%d",countLeaf(root));
                break;     
        case 4:printf("Total Node:%d",counttotalnode(root));
                break;        
        default:
            break;
        }
    } while (ch<5);
    
}