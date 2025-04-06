/*Q 1) Write a C program that accepts the vertices and edges of a graph and stores it as an adjacency matrix.
Display the adjacency matrix. */

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
        printf("\nAdjcency matrix:\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%d\t",a[i][j]);
            }
            printf("\n");
        }
        
        
}   