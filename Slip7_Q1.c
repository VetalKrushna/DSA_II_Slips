/* Q1) Write a C program for the implementation of Floyd Warshall’s algorithm 
   for finding all pairs shortest path using adjacency cost matrix.
*/

#include <stdio.h>

#define INF 999  // Define a large number as infinity

int i, j, k, n;

void printMatrix(int a[10][10])
{
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int a[10][10])
{
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (a[i][k] + a[k][j] < a[i][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }

        printf("\nDistance Matrix after iteration %d:\n", k + 1);
        printf("\nd(%d):\n",k+1);
        printMatrix(a);
    }
}

int main()
{
    int a[10][10];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency cost matrix (use %d for INF):\n", INF);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nInitial Distance Matrix:\n");
    printMatrix(a);

    floydWarshall(a);

    printf("\nFinal All-Pairs Shortest Path Matrix:\n");
    printMatrix(a);

    return 0;

/*
input matrix
 0 3 999 5
2 0 999 4
999 1 0 999
999 999 2 0

*/
}
