#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next; 
};

void insertLast(int data, struct Node** head){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->data = data;
    newNode->next = NULL;
    
    if(*head == NULL){
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteLast(struct Node** head){
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if(*head == NULL){
        printf("List is empty!!!");
        return;
    }

    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

void insertFirst(int data, struct Node** head){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;  
}

void deleteFirst(struct Node** head){
    if(*head == NULL){
        printf("List is empty!!!");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void display(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void main(){
    struct Node* head = NULL;
    insertLast(10, &head);
    insertLast(20, &head);
    insertLast(30, &head);
    deleteLast(&head);
    insertFirst(40, &head);
    insertFirst(50, &head);
    deleteFirst(&head);
    display(head);
}