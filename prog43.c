#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

struct Queue {
    int arr[SIZE];
    int front;
    int rear;
    int count;
};

void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isQEmpty(struct Queue* q) {
    return (q->count == 0);
}

int isQFull(struct Queue* q) {
    return (q->count == SIZE);
}

int qEnqueue(struct Queue* q, int val) {
    if (isQFull(q)) return 0;
    q->rear = (q->rear + 1) % SIZE;
    q->arr[q->rear] = val;
    q->count++;
    return 1;
}

int qDequeue(struct Queue* q) {
    if (isQEmpty(q)) return -1;
    int val = q->arr[q->front];
    q->front = (q->front + 1) % SIZE;
    q->count--;
    return val;
}

struct Queue q1, q2;

int getStackSize() {
    return q1.count + q2.count;
}

void push(int val) {
    if (getStackSize() == SIZE) {
        printf("Stack Overflow! Cannot push element.\n");
        return;
    }
    if (!qEnqueue(&q2, val)) {
        printf("Internal error: queue overflow.\n");
        return;
    }
    while (!isQEmpty(&q1)) {
        if (!qEnqueue(&q2, qDequeue(&q1))) {
            printf("Internal error during transfer.\n");
            return;
        }
    }
    struct Queue temp = q1;
    q1 = q2;
    q2 = temp;
    printf("Pushed %d into stack\n", val);
}

void pop() {
    if (isQEmpty(&q1)) {
        printf("Stack Underflow! Cannot pop.\n");
        return;
    }
    printf("Popped element = %d\n", qDequeue(&q1));
}

void peek() {
    if (isQEmpty(&q1)) {
        printf("Stack is empty. No top element.\n");
        return;
    }
    printf("Top element = %d\n", q1.arr[q1.front]);
}

int main() {
    int choice, value;
    initQueue(&q1);
    initQueue(&q2);
    printf("----- STACK MENU -----\n");
    printf("1. PUSH\n2. POP\n3. PEEK\n4. EXIT\n");
    printf("(Stack size = %d)\n", SIZE);
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Choose 1-4.\n");
        }
    }
    return 0;
}