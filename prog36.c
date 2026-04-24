#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int main() {
    char expr[MAX];
    printf("Enter the infix expression :\n");
    scanf("%s", expr);
    printf("The postfix expression is :\n");
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            printf("%c", c);
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && peek() != '(') printf("%c", pop());
            pop();
        } else if (isOperator(c)) {
            while (top != -1 && peek() != '(' &&(c == '^' ? precedence(peek()) > precedence(c) : precedence(peek()) >= precedence(c))) {
                printf("%c", pop());
            }
            push(c);
        }
    }
    while (top != -1) printf("%c", pop());
    printf("\n");
    return 0;
}