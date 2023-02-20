#include <stdio.h>

#define maxsize 20

int costAdjacencyMatrix[maxsize][maxsize] = {0}, visited[maxsize] = {0}, NoOfNodes, min, mincost = 0, NoOfEdges = 1;

void readCostAdj();
void prims();

void main()
{
    readCostAdj();
    prims();
}
void readCostAdj()
{
    int i, j;
    printf("Enter the number of nodes: ");
    scanf("%d", &NoOfNodes);
    printf("\noEnter the corresponding costs for the following edges");
    for (i = 1; i <= NoOfNodes; i++)
        for (j = 1; j <= NoOfNodes; j++)
        {
            printf("(%d-%d): ", i, j);
            scanf("%d", &costAdjacencyMatrix[i][j]);
            if (costAdjacencyMatrix[i][j] == 0) // check if cost of the edge is 0. ie the edge doesn't exist. So make the edge distance to infinity so it doesn't effect the excecution of our code, since we only consider the minimum node. And infinity will never be a minium value.
            {
                costAdjacencyMatrix[i][j] = 999;
            }
        }
}

void prims()
{
    int i, j, u, v, a, b;
    visited[1] = 1;
    while (NoOfEdges < NoOfNodes) // node can have a maximum of n-1 edges so the loop will run n-1 times, n being the total number of nodes.
    {
        for (i = 1, min = 999; i <= NoOfNodes; i++)
            for (j = 1; j <= NoOfNodes; j++)         // for loop to get the i,j parts for taking cost from cost Adjuacency matrix of our graph
                if (costAdjacencyMatrix[i][j] < min) // if the cost of an edge is lower than min cost(starting min cost of each iteration will be 999 or infinity cost of the first considered edge will always be lower than the min(infinity)).
                {
                    if (visited[i]) // when we start excecutoion only node 1 will be set as visited. As the first while loop completes an iteration the next node {example 2} will be marked as visited and will be considered for next while loop iteration because it is now visited
                    {
                        min = costAdjacencyMatrix[i][j]; // if weight of this particular edge if lower than the previous min, then it is taken as the new minimum. After iteration this min value will be added to the mincost to calculate the final cost of the MST.
                        a = u = i;
                        b = v = j;
                    }
                }
        if (!visited[u] || !visited[v])
        {
            printf("\nEdge %d: (%d %d): Cost: %d", NoOfEdges++, a, b, min); // print new min edge and increment no of edges by 1. If we are n edges we can have atmost n-1 edges so the while loop will stop at n-1 edges
            mincost += min;                                                 // add newly found min edge to mincost
        }
        costAdjacencyMatrix[a][b] = costAdjacencyMatrix[b][a] = 999; // set completed edge's cost to infinity as to never again take those into account during iteration.
        visited[b] = 1;
    }
    printf("\nMinimum cost = %d", mincost);
}