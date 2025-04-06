/* Q 1) Write a C program for the implementation of Topological sorting.*/
#include<stdio.h>
#define MAX 20
struct stack
{
    int data[MAX];
    int top;
}s;

void init()
{
    s.top=-1;
}

void push(int key)
{
    s.data[++s.top]=key;
}

int pop()
{
    return s.data[s.top--];
}

int isempty()
{
    return s.top==-1;
}

void topo(int a[10][10],int n)
{
    int visit[20]={0};
    int ind[20]={0};
    int j,i,v;
    init();
    for(i=0;i<n;i++)
    {
        ind[i]=0;
        for(j=0;j<n;j++)
        {
            ind[i]=ind[i]+a[j][i];
        }
    }

    while(1)
    {
        for(i=0;i<n;i++)
        {
            if(ind[i]==0 && visit[i]==0)
            {
                push(i);
                visit[i]=1;
                printf("V%d\t",i+1);
            }
        }
        if(isempty())
        {
            break;
        }
        v=pop();
        for(i=0;i<n;i++)
        {
            if(a[v][i]==1)
            {
                ind[i]--;
            }
        }
    }

}

int main()
{
    int a[10][10],i,j,n;
    printf("Enter vertex Limit:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=0;
            {  
                scanf("%d",&a[i][j]);
            }
           
        } 
        printf("\n");
    } 
    printf("\nAdjacency Matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        { 
         printf("%d\t",a[i][j]);
           
        }
        printf("\n");
    }
    printf("\n\nTopological order:");
    topo(a,n);
    /*
    input matrix
    0 1 1 0 0
    0 0 0 1 0
    0 0 0 1 1
    0 0 0 0 1
    0 0 0 0 0
    
    */
}

