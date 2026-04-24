#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->next = NULL;
    return n;
}

void insertEnd(struct Node** head, int val) {
    struct Node* n = newNode(val);
    if (*head == NULL) {
        *head = n;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = n;
}

struct Node* mergeSorted(struct Node* l1, struct Node* l2) {
    struct Node dummy;        // dummy head — no malloc needed
    struct Node* tail = &dummy;
    dummy.next = NULL;
    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = (l1 != NULL) ? l1 : l2;
    return dummy.next;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *l1 = NULL, *l2 = NULL;
    int n, val;
    printf("Enter the number of elements in the first linked list:\n");
    scanf("%d", &n);
    printf("Enter the elements in the first linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(&l1, val);
    }
    printf("Enter the number of elements in the second linked list:\n");
    scanf("%d", &n);
    printf("Enter the elements in the second linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        insertEnd(&l2, val);
    }
    struct Node* merged = mergeSorted(l1, l2);
    printf("Sorted Linked List:\n");
    printList(merged);
    return 0;
}