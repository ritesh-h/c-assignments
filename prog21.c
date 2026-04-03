#include <stdio.h>
int main() {
    int n1, n2;
    printf("Enter the size of the first array\n");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter the elements of the first array\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the size of the second array\n");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter the elements of the second array\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    int merged[n1 + n2];
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    while (i < n1) {
        merged[k++] = arr1[i++];
    }
    while (j < n2) {
        merged[k++] = arr2[j++];
    }
    printf("The combined sorted array is\n");
    for (int x = 0; x < n1 + n2; x++) {
        printf("%d ", merged[x]);
    }
    printf("\n");
    return 0;
}