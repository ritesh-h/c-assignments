#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

int queue[SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return ((rear + 1) % SIZE == front);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int element) {
    if (isFull()) {
        printf("Queue is full. Cannot insert element.\n");
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = element;
        printf("Inserted %d into queue\n", element);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Dequeue not possible.\n");
    } else {
        printf("Deleted element = %d\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    int printed = 0;
    do {
        if (printed++) printf(" ");
        printf("%d", queue[i]);
        i = (i + 1) % SIZE;
    } while (i != (rear + 1) % SIZE);
    printf("\n");
}

int main() {
    int choice, element;

    printf("----- CIRCULAR QUEUE MENU -----\n");
    printf("1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT\n");
    printf("(Queue size = %d)\n", SIZE);

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Choose 1-4.\n");
        }
    }
    return 0;
}