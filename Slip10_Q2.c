/*Q 2) Write a C program that accepts the vertices and edges of a graph and stores it as an adjacency matrix.
Display the adjacency list. */

#include<stdio.h>
#include<stdlib.h>
#define memory (NODE*)malloc(sizeof(NODE))
typedef struct node
{
    int data;
    struct node*next;
}NODE;


struct node *head[50];
void displaylist(int n)
{
    printf("Adjacency List::\n");
    int i;
    struct node *temp;
    for(i=0;i<n;i++)
    {
        printf("V%d -->",i+1);
      for(temp=head[i];temp!=NULL;temp=temp->next)
      {
        printf("V%d -->",temp->data);
      }
      printf("NULL\n");
    }
}

void List(int a[50][50],int n)
{
    NODE *temp,*newnode;
    int i,j;
    
    for(i=0;i<n;i++)
    {
        head[i]=NULL;
        for(j=0;j<n;j++)
        {
            if(a[i][j]==1)
            {
                newnode=memory;
                newnode->data=j+1;
                newnode->next=NULL;

                if(head[i]==NULL)
                {
                    head[i]=temp=newnode;
                   continue;
                }

                    temp->next=newnode;
                    temp=newnode;
            }
        }
    }
   
}
int main()
{
    int a[50][50],n,i,j;
    printf("Enter limit of vertices:");
    scanf("%d",&n);

    printf("Enter the Edge:\n");
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(i==j)
                        a[i][j]=0;
                    else
                    {
                        printf("Is ther edges bet V%d to %dV::",i+1,j+1);
                        scanf("%d",&a[i][j]);
                    }    
                }
            }   
        printf("\nAccepted matrix:\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%d\t",a[i][j]);
            }
            printf("\n");
        }
        List(a,n);
        displaylist(n);
        
         /*
        0 1 1 0
        0 0 0 0
        0 1 0 0
        0 0 1 0
        */
}   