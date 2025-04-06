/*Q 2) Write a C program that accepts the vertices and edges of a graph and store it as an adjacency matrix.
Implement functions to print indegree, outdegree and total degree of all vertices of graph.*/



#include<stdio.h>
#include<stdlib.h>

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
    printf("Vrtx\tIn\tOut\tTolal:\n");
    printf("--------------------------");
    int in=0,out=0;
    for(i=0;i<n;i++)
    {
        in=0;out=0;
        printf("\nV%d\t",i+1);
        for(j=0;j<n;j++)
        {
            if(a[j][i]==1)
              in++;
            if(a[i][j]==1)  
              out++;
        }
        printf("%d\t%d\t%d",in,out,in+out);
    }
    
    /*
    0 1 0 1 0
    0 0 1 1 0 
    0 0 0 1 1
    0 0 0 0 1
    0 0 0 0 0 
    */
}            
