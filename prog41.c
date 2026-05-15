#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Heap Overflow: Cannot allocate memory.\n");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Inserted %d into queue\n", val);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty. Dequeue not possible.\n");
        return;
    }
    struct Node* temp = front;
    printf("Deleted element = %d\n", temp->data);
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}

void peek() {
    if (front == NULL) {
        printf("Queue is empty. No front element.\n");
    } else {
        printf("Front element = %d\n", front->data);
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

void freeQueue() {
    while (front != NULL) {
        struct Node* temp = front;
        front = front->next;
        free(temp);
    }
    rear = NULL;
}

int main() {
    int choice, value;
    printf("----- QUEUE MENU -----\n");
    printf("1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. PEEK\n5. EXIT\n");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: peek(); break;
            case 5:
                printf("Exiting program...\n");
                freeQueue();
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}