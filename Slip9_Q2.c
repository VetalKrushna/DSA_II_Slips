/*Q 2) Implement a Binary search tree (BST) library (btree.h) with operations – create, 
insert,post order. Write a menu driven program that performs the above operations.*/

#include"btree.h"
#include<stdio.h>

int main()
{
    int ch;
    struct node*root=NULL;
    do{

        printf("\n1-Create\n2-Insert\n3-Postorder\n4-Exit\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:root=create(NULL);
                    break;
            case 2:Insert(root);
                    break;
            case 3:Postorder(root);
                    break;        
        }
    }while(ch<4);
}