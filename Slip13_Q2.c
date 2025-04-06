/*Q 2) Write a C program that accepts the vertices and edges of a graph and store it as an adjacency matrix.
Implement function to traverse the graph using Breadth First Search (BFS) traversal
*/
#include<stdio.h>
#define MAX 20

struct queue
{
    int data[MAX];
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

void add(int key)
{
    q.data[++q.rear] = key;
}

int rm()
{
    return q.data[++q.front];
}

void BFS(int a[10][10], int n, int v, int visit[10])
{
    int i, j;
    init();
    add(v);
    visit[v] = 1;

    printf("BFS Traversal: ");

    while(!isempty())
    {
        i = rm();
        printf("V%d ", i+1);

        for(j = 0; j < n; j++)
        {
            if(a[i][j] == 1 && visit[j] == 0)
            {
                add(j);
                visit[j] = 1;
            }
        }
    }
}

int main()
{
    int a[10][10], n, i, j;
    int visit[10] = {0};

    printf("Enter limit of vertices: ");
    scanf("%d", &n);

    printf("Enter the edges (1:Yes, 0:No):\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
                a[i][j]=0;
            else
            {
                printf("Edge between V%d and V%d: ", i+1, j+1);
                scanf("%d", &a[i][j]);
            }
        }
    }

    BFS(a, n, 0, visit);

    return 0;




/*
input 
Enter limit of vertices: 4
Enter the edges:
Edge between V1 and V2: 1
Edge between V1 and V3: 0
Edge between V1 and V4: 1
Edge between V2 and V1: 0
Edge between V2 and V3: 1
Edge between V2 and V4: 0
Edge between V3 and V1: 0
Edge between V3 and V2: 0
Edge between V3 and V4: 1
Edge between V4 and V1: 0
Edge between V4 and V2: 0
Edge between V4 and V3: 0
 0 1 0 1
 0 0 1 0
 0 0 0 1
 0 0 0 0

*/
}