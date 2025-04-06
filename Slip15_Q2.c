/*Q 2) Write a C program for the implementation of Dijkstra’s shortest path algorithm for finding shortest path
from a given source vertex using adjacency cost matrix.
*/

#include <stdio.h>
//#define n 4
int i,j,n;
void dij(int a[10][10])
{
int d[20]={0},visit[20],min,v,k;

   i=0;
   visit[0]=1;
   d[0]=0;
      for (j = 1; j < n; j++) 
      {
            d[j]=a[i][j];
      }
     for (j = 0; j < n; j++) 
      { 
       printf("%d\t",d[j]);
      } 
      k=1;
      while(k<n-1)
      {
      min=999;
    
      for(j=1;j<n;j++)  
      {
           if(d[j]<min && visit[j]==0)
           {
             min=d[j];
             v=j;
           }
      }
      visit[v]=1;
      for(j=1;j<n;j++)
      {
        if(d[v]+(a[v][j]>d[j]))
        {
          d[j]=d[v]+a[v][j];
        }
      }
      k++;
      }
      printf(" \nDijktras shortest path:\n");
  for (j = 0; j < n; j++) 
      {
       printf("%d\t",d[j]);
      } 
  
}
void main() 
{
        int a[10][10] ;
        printf("Enter vertex limit:");
        scanf("%d",&n);
        printf("Enter matrix:");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
             scanf("%d",&a[i][j]);
            }
        }
  dij(a);

   /*
  0 20 0 0 0 4 0
  20 0 8 0 0 0 7
  0 8 0 6 0 0 0
  0 0 6 0 10 0 9
  0 0 0 10 0 10 11
  4 0 0 0 15 0 0
  0 7 0 9 11 0 0 
  */
}

    