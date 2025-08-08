#include <stdio.h>
#define V 7

void dfsHelper(int arr[V][V], int visited[], int key) {
    visited[key] = 1;
    printf("%d ", (key+1));

    for (int i = 0; i < V; i++) {
        if (visited[i] == 0 && arr[key][i] != 0) {
            dfsHelper(arr, visited, i);
        }
    }
}

void dfs(int arr[V][V]) {
    int visited[V] = {0};
    dfsHelper(arr, visited, 0);
}

int main() {
    int arr[V][V] = {
        {0, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 1, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0},
        {1, 1, 0, 0, 1, 0, 1},
        {0, 1, 1, 1, 0, 1, 1},
        {0, 0, 1, 0, 1, 0, 1},
        {0, 0, 0, 1, 1, 1, 0}
    };

    printf("DFS traversal: ");
    dfs(arr);
    return 0;
}
