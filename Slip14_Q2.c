/*Q 2) Write a C program which uses Binary search tree library and displays nodes at each level,
 and total levels in the tree*/

 #include<stdio.h>
 #include"btree.h"

 #define MAX 20

struct queue
{
    struct node* data[MAX];
    int front, rear;
}q;

void init()
{
    q.front = q.rear = -1;
}

int isempty()
{
    return q.front == q.rear;
}

int isfull()
{
    return q.rear == MAX-1;
}

void add(NODE* key)
{
    q.data[++q.rear] = key;
}

NODE* rm()
{
    return q.data[++q.front];
}

void Levelorder(NODE *root)
{
    NODE *temp,*M=NULL;
    int level=1;
    init();
    add(root);
    add(M);

    printf("\nLevel::%d",level);

    while(!isempty())
    {
        temp=rm();

        if(temp==M)
        {
            level++;
            if(!isempty())
            {
                printf("\nLevel::%d",level);
                add(M);
            }
        }
       else
        {
            printf("\t%d",temp->data);
             if(temp->left)
                 add(temp->left);
             if(temp->right) 
                add(temp->right);
        }
    }
    printf("\nTotal Level:%d",level);
    printf("\n");
}

int main()
{
    int ch;
    NODE*root=NULL;
    do
    {
       
        printf("\n1-Create\n2-Display\n3-Level Wise and Total Level\nEnter choic:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:root=create(NULL);
            break;
        case 2:Inorder(root);
                break;
        case 3:Levelorder(root);
                break;     
        
        }
    } while (ch<4);
    
}


