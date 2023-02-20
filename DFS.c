#include <stdio.h>

void DFS(int);
int G[10][10], visited[10] = {0}, n, startingVertex;
void main()
{
    int i, j;
    printf("Enter number of vertices:");

    scanf("%d", &n);
    printf("\nEnter adjacency matrix of the graph:");

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &G[i][j]);
    printf("\nEnter a starting vertex");
    scanf("%d", &startingVertex);
    DFS(startingVertex);
}
void DFS(int v)
{
    int i;
    printf("\n%d", v);
    visited[v] = 1;
    for (i = 1; i <= n; i++)
        if (!visited[i] && G[v][i])
            DFS(i);
}
