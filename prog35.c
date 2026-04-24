#include <stdio.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int isOpen(char c) {
    return c == '(' || c == '[' || c == '{';
}

int isMatch(char open, char close) {
    return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
}

int main() {
    char expr[MAX];
    printf("Enter the input :\n");
    scanf("%s", expr);
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (isOpen(c)) {
            push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (top == -1 || !isMatch(pop(), c)) {
                printf("Parentheses are not balanced\n");
                return 0;
            }
        }
    }
    if(top == -1) printf("Parentheses are balanced\n");
    else          printf("Parentheses are not balanced\n");
    return 0;
}