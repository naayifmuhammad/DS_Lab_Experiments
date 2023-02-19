#include <stdio.h>

void DFS(int);
int G[10][10], visited[10], n, startingVertex;
void main()
{
    int i, j;
    printf("Enter number of vertices:");

    scanf("%d", &n);
    printf("\nEnter adjacency matrix of the graph:");

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &G[i][j]);
    for (i = 1; i <= n; i++)
        visited[i] = 0;
    printf("\nEnter a starting vertex");
    scanf("%d", &startingVertex);
    DFS(startingVertex);
}
void DFS(int i)
{
    int j;
    printf("\n%d", i);
    visited[i] = 1;
    for (j = 1; j <= n; j++)
        if (!visited[j] && G[i][j] == 1)
            DFS(j);
}