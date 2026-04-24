#include<stdio.h>
#define MAX 4
int stack[MAX], top = -1;

void push(int val){
    if(top == MAX - 1){
        printf("Stack Overflow! Cannot push element.\n");
        return;
    }
    top++;
    stack[top] = val;
    printf("Pushed %d into stack\n",val);
}
void pop(){
    if(top == -1){
        printf("Stack Underflow! Cannot pop.\n");
        return;
    }
    printf("Popped element = %d\n",stack[top]);
    top--;
}
void peek(){
    if(top == -1){
        printf("Stack is empty. No top element.\n");
        return;
    }
    printf("Top element = %d\n",stack[top]);
}
int main(){
    int val, ch;
    printf("----- STACK MENU -----\n1. PUSH\n2. POP\n3. PEEK\n4. EXIT\n\n(Stack size = %d)\n", MAX);
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter element: ");
                scanf("%d",&val);
                push(val);
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
                printf("Invalid choice!\n");
                break;
        }
    }
}