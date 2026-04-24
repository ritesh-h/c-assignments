#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100

double stack[MAX];
int top = -1;

void push(double val) { stack[++top] = val; }
double pop() { return stack[top--]; }

int main() {
    char expr[MAX];
    printf("Enter the postfix expression :\n");
    fgets(expr, MAX, stdin);
    char *token = strtok(expr, " \n");
    while (token != NULL) {
        if (strlen(token) == 1 && (token[0] == '+' || token[0] == '-' ||
            token[0] == '*' || token[0] == '/' || token[0] == '^')) {
            double b = pop();
            double a = pop();
            double result;
            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0) { printf("Error: Division by zero\n"); return 1; }
                    result = a / b;
                    break;
                case '^': result = pow(a, b); break;
            }
            push(result);
        } else {
            push(atof(token));
        }
        token = strtok(NULL, " \n");
    }
    printf("Result :\n");
    double ans = pop();
    if (fabs(ans - (int)ans) < 1e-9) printf("%d\n", (int)ans);
    else printf("%.2f\n", ans);
    return 0;
}