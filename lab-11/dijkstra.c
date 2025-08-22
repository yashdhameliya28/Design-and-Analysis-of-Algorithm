#include <stdio.h>
#include <limits.h>

#define V 5

int findMinKey(int visited[], int distance[])
{
    int min = INT_MAX;
    int key = -1;

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0 && distance[i] < min)
        {
            min = distance[i];
            key = i;
        }
    }
    return key;
}

void printArray(int dist[])
{
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V])
{
    int distance[V];
    int visited[V];

    for (int i = 0; i < V; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }

    distance[0] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = findMinKey(visited, distance);
        visited[u] = 1;

        for (int j = 0; j < V; j++)
        {
            if (visited[j] == 0 && graph[u][j] != 0)
            {
                if (distance[u] + graph[u][j] < distance[j])
                {
                    distance[j] = distance[u] + graph[u][j];
                }
            }
        }

        printArray(distance);
    }
}

int main()
{
    int graph[V][V] = {
        {0, 10, 0, 0, 5},
        {10, 0, 1, 0, 2},
        {0, 1, 0, 4, 9},
        {0, 0, 4, 0, 7},
        {5, 2, 9, 7, 0}};

    dijkstra(graph);
    return 0;
}
