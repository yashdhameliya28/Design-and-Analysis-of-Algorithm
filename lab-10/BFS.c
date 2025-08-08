#include <stdio.h>
#define V 7

struct Queue {
    int items[V];
    int front;
    int rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == V - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

void bfs(int arr[V][V]) {
    struct Queue q;
    initQueue(&q);

    int visited[V] = {0};
 
    visited[0] = 1;
    enqueue(&q, 0);

    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);

        for (int i = 0; i < V; i++) {
            if (arr[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
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

    printf("BFS traversal: ");
    bfs(arr);
    return 0;
}
