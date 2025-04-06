/* Q 1) Write a C program that accepts the vertices and edges of a graph and store it as an adjacency
matrix.Implement function to traverse the graph using Depth First Search (DFS) traversal. */

#include<stdio.h>

void DFS(int a[10][10],int n,int v)
{
    static int visit[10]={0};
    int i=v;
    visit[i]=1;
    printf("\t%d",i+1);
    for(int j=0;j<n;j++)
    {
        if(a[i][j]==1 && visit[j]==0)
        {
            DFS(a,n,j);
            visit[j]=1;
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

    DFS(a,n,0);


/*
0 1 0 1 0 1 0
0 0 1 0 1 0 1
0 0 0 0 0 0 0
0 1 0 0 0 0 0
0 0 1 0 0 0 0 
0 1 0 0 0 0 0
0 0 1 0 0 0 0
*/
}