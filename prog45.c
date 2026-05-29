#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

typedef struct Queue {
    Node* items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) { q->front = -1; q->rear = -1; }
int isEmpty(Queue* q) { return q->front == -1; }
void enqueue(Queue* q, Node* value) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}
Node* dequeue(Queue* q) {
    if (isEmpty(q)) return NULL;
    Node* item = q->items[q->front];
    if (q->front >= q->rear) { q->front = -1; q->rear = -1; }
    else { q->front++; }
    return item;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    Node* newNode = createNode(data);
    if (root == NULL) {
        printf("Inserted %d\n", data);
        return newNode;
    }
    
    Queue q; initQueue(&q);
    enqueue(&q, root);
    
    while (!isEmpty(&q)) {
        Node* temp = dequeue(&q);
        
        if (temp->left == NULL) {
            temp->left = newNode;
            break;
        } else {
            enqueue(&q, temp->left);
        }
        
        if (temp->right == NULL) {
            temp->right = newNode;
            break;
        } else {
            enqueue(&q, temp->right);
        }
    }
    printf("Inserted %d\n", data);
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;
    
    if (root->left == NULL && root->right == NULL) {
        if (root->data == key) {
            free(root);
            printf("Element %d deleted\n", key);
            return NULL;
        } else {
            return root;
        }
    }
    Queue q; initQueue(&q);
    enqueue(&q, root);
    Node* temp = NULL;
    Node* keyNode = NULL;
    while (!isEmpty(&q)) {
        temp = dequeue(&q);
        if (temp->data == key) keyNode = temp;
        if (temp->left) enqueue(&q, temp->left);
        if (temp->right) enqueue(&q, temp->right);
    }
    if (keyNode != NULL) {
        int x = temp->data;
        initQueue(&q);
        enqueue(&q, root);
        Node* parent = NULL;
        while (!isEmpty(&q)) {
            parent = dequeue(&q);
            if (parent->left == temp) { parent->left = NULL; break; }
            if (parent->right == temp) { parent->right = NULL; break; }
            if (parent->left) enqueue(&q, parent->left);
            if (parent->right) enqueue(&q, parent->right);
        }
        if (keyNode == temp) {
            free(temp);
        } else {
            keyNode->data = x;
            free(temp);
        }
        printf("Element %d deleted\n", key);
    }
    return root;
}

void levelOrder(Node* root) {
    if (root == NULL) return;
    Queue q; initQueue(&q);
    enqueue(&q, root);
    while (!isEmpty(&q)) {
        Node* temp = dequeue(&q);
        printf("%d ", temp->data);
        if (temp->left) enqueue(&q, temp->left);
        if (temp->right) enqueue(&q, temp->right);
    }
}

void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int search(Node* root, int key) {
    if (root == NULL) return 0;
    if (root->data == key) return 1;
    return search(root->left, key) || search(root->right, key);
}

int main() {
    Node* root = NULL;
    int choice, val;

    while (1) {
        printf("\n------ BINARY TREE MENU ------\n");
        printf("1. Insert\n2. Delete\n3. Display (Level Order)\n");
        printf("4. Preorder Traversal\n5. Inorder Traversal\n");
        printf("6. Postorder Traversal\n7. Search\n8. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                break;
            case 3:
                printf("Binary Tree (Level Order): ");
                levelOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                printf("Enter element to search: ");
                scanf("%d", &val);
                if (search(root, val))
                    printf("Element %d found in the tree\n", val);
                else
                    printf("Element %d not found in the tree\n", val);
                break;
            case 8:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}