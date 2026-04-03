#include <stdio.h>
int power(int x, int k) {
    if(k == 0) return 1; if(k<0) return 1/power(x,-k);
    return x * power(x, k - 1);
}
int main() {
    int x, k;
    printf("Enter the value of x and k: ");
    scanf("%d %d", &x, &k);
    printf("Value of x^k is %d\n", power(x, k));
    return 0;
}