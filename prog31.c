#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert_begin(int val) {      //simple begin insertion
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
}

void insert_end(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL) {  //inserts at 1st node as list is empty
        head = newnode;
        return;
    }
    struct node* temp = head;    //regular insert end with loop
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}

void insert_k(int val, int pos) {
    if (pos <= 0) {                //negative or 0 is invalid position
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {           //insertion at 1st node
        insert_begin(val);
        return;
    }
    struct node* temp = head;
    for (int i = 1; i < pos - 1; i++) {       
        if (temp == NULL) {                      //mid-loop check for pos > length+1
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL) {               //empty list
            printf("Invalid position\n"); 
            return;
        }
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = temp->next;
    temp->next = newnode;
}

void traverse() {
    if (head == NULL) {            //empty list
        printf("List is empty\n");
        return;
    }
    struct node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {            //regular list traversal
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

void count_nodes() {              //simple count with integer increment
    int count = 0;
    struct node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total number of nodes = %d\n", count);
}

void search(int key) {
    if (head == NULL) {                 //empty list search not possible
        printf("The list is empty. Element not found.\n");
        return;
    }
    struct node* temp = head;
    int pos = 1;
    while (temp != NULL) {               //search each node in loop
        if (temp->data == key) {
            printf("Element found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element not found in the list\n");
}

void update(int pos, int val) {
    if (pos <= 0) {              //negative or 0 is invalid position
        printf("Invalid position\n");
        return;
    }
    struct node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {       //empty list
        printf("Invalid position\n");
        return;
    }
    temp->data = val;
}

void delete_begin() {         //standard deletion
    if (head == NULL) {
        printf("The list is empty. Deletion not possible.\n");
        return;
    }
    struct node* temp = head;
    printf("Deleted element = %d\n", temp->data);
    head = head->next;
    free(temp);
}

void delete_end() {
    if (head == NULL) {                //empty list
        printf("The list is empty. Deletion not possible.\n");
        return;
    }
    if (head->next == NULL) {     //list with 1 element
        printf("Deleted element = %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct node* temp = head;
    while (temp->next->next != NULL){   //standard end deletion with loop
        temp = temp->next;}
    printf("Deleted element = %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void delete_k(int pos) {
    if (pos <= 0) {              //negative or 0 is invalid position
        printf("Invalid position\n");
        return;
    }
    if (head == NULL) {            //empty list
        printf("The list is empty. Deletion not possible.\n");
        return;
    }
    if (pos == 1) {                //same as deletion of 1st
        delete_begin();
        return;
    }
    struct node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++){
        temp = temp->next;}
    if (temp->next == NULL) {                  //pos greater than existing nodes
        printf("Invalid position\n");
        return;
    }
    struct node* del = temp->next;      //standard deletion
    printf("Deleted element at position %d = %d\n", pos, del->data);
    temp->next = del->next;
    free(del);
}

int main() {
    int choice, val, pos;
    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Insert at beginning\n2. Insert at kth position\n3. Insert at end\n");
        printf("4. Traverse\n5. Count nodes\n6. Search element\n");
        printf("7. Update kth position\n8. Delete at the beginning\n");
        printf("9. Delete at the kth position\n10. Delete at the end\n11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &val);
                insert_begin(val);
                break;
            case 2:
                printf("Enter element and position: ");
                scanf("%d %d", &val, &pos);
                insert_k(val, pos);
                break;
            case 3:
                printf("Enter element: ");
                scanf("%d", &val);
                insert_end(val);
                break;
            case 4:
                traverse();
                break;
            case 5:
                count_nodes();
                break;
            case 6:
                printf("Enter element to search: ");
                scanf("%d", &val);
                search(val);
                break;
            case 7:
                printf("Enter position and new value: ");
                scanf("%d %d", &pos, &val);
                update(pos, val);
                break;
            case 8:
                delete_begin();
                break;
            case 9:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete_k(pos);
                break;
            case 10:
                delete_end();
                break;
            case 11:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}