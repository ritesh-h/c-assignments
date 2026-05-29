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

Node* insertBST(Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insertBST(root->left, data);
    else if (data > root->data)
        root->right = insertBST(root->right, data);
    return root;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteBST(Node* root, int key, int printMsg) {
    if (root == NULL) return root;
    if (key < root->data) {
        root->left = deleteBST(root->left, key, printMsg);
    } else if (key > root->data) {
        root->right = deleteBST(root->right, key, printMsg);
    } else {
        if (printMsg) printf("Element %d deleted\n", key);
        
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data, 0);
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

int searchBST(Node* root, int key) {
    if (root == NULL) return 0;
    if (root->data == key) return 1;
    if (root->data > key) return searchBST(root->left, key);
    return searchBST(root->right, key);
}

int main() {
    Node* root = NULL;
    int choice, val;

    while (1) {
        printf("\n------ BINARY SEARCH TREE MENU ------\n");
        printf("1. Insert\n2. Delete\n3. Display (Level Order)\n");
        printf("4. Preorder Traversal\n5. Inorder Traversal\n");
        printf("6. Postorder Traversal\n7. Search\n8. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &val);
                root = insertBST(root, val);
                printf("Inserted %d\n", val);
                break;
            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &val);
                root = deleteBST(root, val, 1);
                break;
            case 3:
                printf("BST (Level Order): ");
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
                if (searchBST(root, val))
                    printf("Element %d found in the BST\n", val);
                else
                    printf("Element %d not found in the BST\n", val);
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