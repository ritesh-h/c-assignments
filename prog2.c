#include <stdio.h>
int main(){
    int n, m,count=0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        printf("Enter %d element:", i+1);
        scanf("%d", &a[i]);
    }
    printf("Enter value of m: ");
    scanf("%d", &m);
    printf("Pairs are:\n");
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] + a[j] == m) {
                printf("(%d, %d)\n", a[i], a[j]);
                count++;
            }
        }
    }
    if(count == 0) printf("No pairs found.\n");
    else printf("Total pairs = %d\n", count);
    return 0;
}