#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* insert(struct node* head, int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));       //malloc check
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL) return newnode;
    struct node* temp = head;
    while (temp->next != NULL)       //standard insertion
        temp = temp->next;
    temp->next = newnode;
    return head;
}

struct node* reverse(struct node* head) {
    struct node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void display(struct node* head) {
    if (head == NULL) {        //when n=0 empty
        printf("List is empty\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, val;
    struct node* head = NULL;
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input.\n");
        return 1;
    }
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = insert(head, val);
    }
    printf("Original Linked List:\n");
    display(head);
    head = reverse(head);
    printf("Reversed Linked List:\n");
    display(head);
    struct node* temp; 
    while (head != NULL) {   // Free allocated memory
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}