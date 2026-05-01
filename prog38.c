#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int data) {   // 1. Insert at beginning
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtKth(int data, int k) {    // 2. Insert at kth position
    if (k == 1) {
        insertAtBeginning(data);
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < k - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void insertAtEnd(int data) {    // 3. Insert at end
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void traverse() {      //Traverse
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

void countNodes() {   //Count Nodes
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total number of nodes = %d\n", count);
}

void searchElement(int key) {    // 6. Search element
    if (head == NULL) {
        printf("The list is empty. Element not found.\n");
        return;
    }
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element not found in the list\n");
}

void updateAtKth(int k, int newVal) {    //Update at Kth Position
    struct Node* temp = head;
    for (int i = 1; i < k && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    temp->data = newVal;
}

void deleteAtBeginning() {     // 9. Delete at kth position
    if (head == NULL) {
        printf("The list is empty. Deletion not possible.\n");
        return;
    }
    struct Node* temp = head;
    printf("Deleted element = %d\n", temp->data);
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}

void deleteAtKth(int k) {     // 9. Delete at kth position
    if (head == NULL) {
        printf("The list is empty. Deletion not possible.\n");
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < k && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    printf("Deleted element at position %d = %d\n", k, temp->data);
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

void deleteAtEnd() {      // 10. Delete at end
    if (head == NULL) {
        printf("The list is empty. Deletion not possible.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Deleted element = %d\n", temp->data);
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
}

int main() {
    int choice, data, k, newVal;
    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the kth position\n");
        printf("3. Insert at the end\n");
        printf("4. Traverse\n");
        printf("5. Count nodes\n");
        printf("6. Search element\n");
        printf("7. Update kth position\n");
        printf("8. Delete at the beginning\n");
        printf("9. Delete at the kth position\n");
        printf("10. Delete at the end\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter element and position: ");
                scanf("%d %d", &data, &k);
                insertAtKth(data, k);
                break;
            case 3:
                printf("Enter element: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 4:
                traverse();
                break;
            case 5:
                countNodes();
                break;
            case 6:
                printf("Enter element to search: ");
                scanf("%d", &data);
                searchElement(data);
                break;
            case 7:
                printf("Enter position and new value: ");
                scanf("%d %d", &k, &newVal);
                updateAtKth(k, newVal);
                break;
            case 8:
                deleteAtBeginning();
                break;
            case 9:
                printf("Enter position to delete: ");
                scanf("%d", &k);
                deleteAtKth(k);
                break;
            case 10:
                deleteAtEnd();
                break;
            case 11:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}