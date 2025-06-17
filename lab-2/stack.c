#include <stdio.h>
#define MAX 5

struct Stack
{
    int arr[MAX];
    int top;
};

void initStack(struct Stack* s)
{
    s->top = -1;
}

void push(struct Stack* s, int data)
{
    if (s->top >= (MAX - 1))
    {
        printf("stack overflow!!!\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = data;
    }
}

int pop(struct Stack* s){
    if(s->top == -1){
        printf("stack underflow!!!\n");
        return -1;
    }
    int temp = s->arr[s->top];
    s->top--;
    return temp;
}

int peep(struct Stack* s, int idx){
    if(s->top-idx+1 < 0){
        printf("stack underflow");
        return -1;
    }
    int temp = s->arr[s->top-idx+1]; 
    return temp;
}

void change(struct Stack* s, int idx, int newData){
    if(s->top-idx+1 < 0){
        printf("stack underflow");
    }else{
        s->arr[s->top-idx+1] = newData;
    }

}

void printStack(struct Stack* s){
    for(int i=0; i<=s->top; i++){
        printf("%d\n", s->arr[i]);
    }
}

void main()
{
    struct Stack s; 
    initStack(&s);
    push(&s, 5);
    push(&s, 2);
    push(&s, 10);
    push(&s, 20);
    push(&s, 4);
    change(&s, 3, 100);
    printStack(&s);
    // int value = peep(&s, 3);
    // printf("peeped value : %d", value);
}
