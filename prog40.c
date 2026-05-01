#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->exp == 0)
            printf("%d", temp->coeff);
        else
            printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

struct Node* addPolynomials(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            insertAtEnd(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p1->exp < p2->exp) {
            insertAtEnd(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0)
                insertAtEnd(&result, sum, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        insertAtEnd(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insertAtEnd(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return result;
}

int main() {
    struct Node* poly1 = NULL, *poly2 = NULL;
    int n, coeff, exp;
    printf("Enter number of terms in Polynomial 1: ");
    scanf("%d", &n);
    printf("Enter coefficient and exponent:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertAtEnd(&poly1, coeff, exp);
    }
    printf("Enter number of terms in Polynomial 2: ");
    scanf("%d", &n);
    printf("Enter coefficient and exponent:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertAtEnd(&poly2, coeff, exp);
    }
    printf("\nPolynomial 1:\n");
    display(poly1);
    printf("Polynomial 2:\n");
    display(poly2);
    struct Node* result = addPolynomials(poly1, poly2);
    printf("Resultant Polynomial after addition:\n");
    display(result);
    return 0;
}