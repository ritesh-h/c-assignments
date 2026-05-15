#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

struct Stack {
    int arr[SIZE];
    int top;
};
struct Stack s1, s2;

void initStack(struct Stack* s) {
    s->top = -1;
}

int isStackEmpty(struct Stack* s) {
    return (s->top == -1);
}

int isStackFull(struct Stack* s) {
    return (s->top == SIZE - 1);
}

int push(struct Stack* s, int val) {
    if (isStackFull(s)) return 0;
    s->arr[++s->top] = val;
    return 1;
}

int pop(struct Stack* s) {
    if (isStackEmpty(s)) return -1;
    int val = s->arr[s->top];
    s->top--;
    return val;
}

int getQueueSize() {
    return (s1.top + 1) + (s2.top + 1);
}

void enqueue(int val) {
    if (getQueueSize() == SIZE) {
        printf("Queue is full. Cannot insert element.\n");
        return;
    }
    if (!push(&s1, val)) {
        printf("Internal error: stack overflow.\n");
        return;
    }
    printf("Inserted %d into queue\n", val);
}

void dequeue() {
    if (isStackEmpty(&s1) && isStackEmpty(&s2)) {
        printf("Queue is empty. Dequeue not possible.\n");
        return;
    }
    if (isStackEmpty(&s2)) {
        while (!isStackEmpty(&s1)) {
            if (!push(&s2, pop(&s1))) {
                printf("Internal error during transfer.\n");
                return;
            }
        }
    }
    printf("Deleted element = %d\n", pop(&s2));
}
void display() {
    if (isStackEmpty(&s1) && isStackEmpty(&s2)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = s2.top; i >= 0; i--) {
        printf("%d ", s2.arr[i]);
    }
    for (int i = 0; i <= s1.top; i++) {
        printf("%d ", s1.arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    initStack(&s1);
    initStack(&s2);
    printf("----- QUEUE MENU -----\n");
    printf("1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT\n");
    printf("(Queue size = %d)\n", SIZE);
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &value);
                enqueue(value);
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