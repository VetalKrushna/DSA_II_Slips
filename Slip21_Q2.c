/*
Q 2) Write a C program for the Implementation of Prim’s Minimum spanning tree algorithm. -
 */
#include<stdio.h>
void prims(int a[20][20],int n)
{
  int min,e,i,j,u,v;
  int b,c,mincost=0;
  int visit[20]={0};
  visit[0]=1;
  for(e=0;e<=n-1;e++)
  {
   for(i=0,min=999;i<n;i++)
   {
   for(j=0;j<n;j++)
    {
      if(a[i][j]<min)
      {
      if(visit[i]!=0)
      {
      min=a[i][j];
      u=b=i;
      v=c=j;
      }
    }
    }
    }
   
   if(visit[u]==0||visit[v]==0)
   {
      printf("\nEdge- %d-%d cost-%d",u+1,v+1,min);
       visit[v]=1;
       mincost+=min;
      }
       a[u][v]=a[v][u]=999;
   }
   
   printf("\nMinimun Cost%d",mincost);
   
  }


void main()
{
int a[20][20],n,i,j;
printf("Enter limit");
scanf("%d",&n);

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
if(a[i][j]==0)
  a[i][j]=999;
  }
  }
  prims(a,n);
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