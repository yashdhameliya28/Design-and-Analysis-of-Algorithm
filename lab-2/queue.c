#include<stdio.h>
#define MAX 10

struct queue{
    int arr[MAX];
    int front, rear;
};

void initQueue(struct queue* q){
    q->front = 0;
    q->rear = -1;
}

void enQueue(struct queue* q, int data){
    if(q->rear >= (MAX - 1)){
        printf("queue is overflow!!!\n");
    }
    else{
        q->rear++;    
    }
    q->arr[q->rear] = data;
}

int deQueue(struct queue* q){
    if(q->front == 0){
        printf("queue underflow!!!\n");
    }
    
    int temp = q->arr[q->front];

    if(q->front == q->rear){
        q->front = 0;
        q->rear = -1;
    }else{
        q->front++;
    }
    return temp;
}

void display(struct queue* q){
    for(int i=q->front; i<=q->rear; i++){
        printf("%d \n", q->arr[i]);
    }
}

void main(){
    struct queue q;
    initQueue(&q);
    enQueue(&q, 10);
    enQueue(&q, 20);
    enQueue(&q, 30);
    deQueue(&q);
    display(&q);
}