#include <stdio.h>
void swapValue(int x, int y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
    printf("Values under the swap function (Call by Value)\n");
    printf("x=%d y=%d\n", x, y);
}
void swapAddress(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    printf("Values under the swap function (Call by Address)\n");
    printf("x=%d y=%d\n", *x, *y);
}
int main() {
    int x, y;
    printf("Enter two numbers\n");
    scanf("%d %d", &x, &y);
    swapValue(x, y);
    printf("Values under the main function\n");
    printf("x=%d y=%d\n", x, y);
    swapAddress(&x, &y);
    printf("Values under the main function\n");
    printf("x=%d y=%d\n", x, y);
    return 0;
}