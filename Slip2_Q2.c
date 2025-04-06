/*Q 2) Implement a Binary search tree (BST) library (btree.h) with operations – create, search, inorder. Write a
menu driven program that performs the above operations.*/

#include"btree.h"
#include<stdio.h>

int main()
{
    int ch;
    struct node*root=NULL;
    do{

        printf("\n1-Create\n2-Search\n3-Inorder\n4-Exit\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:root=create(NULL);
                    break;
            case 2:printf("Enter number to search:");
                    int num;
                    scanf("%d",&num);
                    Search(root,num);
                    break;
            case 3:Inorder(root);
                    break;        
        }
    }while(ch<4);
}