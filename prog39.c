#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int data) {   // Push
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d into stack\n", data);
}

void pop() {   // Pop
    if (top == NULL) {
        printf("Stack Underflow! Cannot pop.\n");
        return;
    }
    struct Node* temp = top;
    printf("Popped element = %d\n", temp->data);
    top = top->next;
    free(temp);
}

void peek() {    // Peek
    if (top == NULL) {
        printf("Stack is empty. No top element.\n");
        return;
    }
    printf("Top element = %d\n", top->data);
}

int main() {
    int choice, data;
    while (1) {
        printf("\n----- STACK MENU -----\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}