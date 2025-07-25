#include <stdio.h>
#include <limits.h>
#define V 5

void primsAlgorithm()
{
    int weight[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    int visited[V] = {0};
    visited[0] = 1;
    int edge = 0;
    int min_cost = 0;

    while (edge < V - 1)
    {
        int minWeight = INT_MAX;
        int x = 0, y = 0;

        for (int i = 0; i < V; i++)
        {
            if (visited[i] != 0)
            {
                for (int j = 0; j < V; j++)
                {
                    if (visited[j] == 0 && weight[i][j] != 0)
                    {
                        if (weight[i][j] < minWeight)
                        {
                            minWeight = weight[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("Edge %d: %d -- %d, weight: %d\n", edge + 1, x, y, weight[x][y]);
        visited[y] = 1;
        min_cost += weight[x][y];
        edge++;
    }
    printf("Min_Cost : %d", min_cost);
}

int main()
{
    primsAlgorithm();
    return 0;
}