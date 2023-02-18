#include <stdio.h>

#define maxsize 20

int a[maxsize][maxsize], visited[maxsize], stack[maxsize], top = 0, n;

void readAdjMatrix();
void topologicalSort();
void initArrays();
void topologicalSortRecursion(int);
void main()
{
    printf("Enter the number of vertices in your graph: ");
    scanf("%d", &n);
    initArrays();
    readAdjMatrix();
    topologicalSort();
}

void initArrays()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            a[i][j] = 0;
        }
    }
    for (i = 1; i <= n; i++)
    {
        visited[i] = 0;
        stack[i] = 0;
    }
}

void readAdjMatrix()
{
    int i, j;
    printf("Enter the adjacency matrix: \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void topologicalSort()
{
    int starting, i;
    printf("Enter the starting vertex: ");
    scanf("%d", &starting);
    topologicalSortRecursion(starting);
    printf("\nTopological order of given graph is\n");
    for (i = n; i >= 1; i--)
    {
        printf("%d", stack[i]);
    }
}

void topologicalSortRecursion(int u)
{
    int i;
    visited[u] = 1;
    for (i = 1; i <= n; i++)
    {
        if (a[u][i] && !visited[i])
        {
            visited[i] = 1;
            topologicalSortRecursion(i);
        }
    }
    stack[++top] = u;
}