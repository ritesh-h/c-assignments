#include <stdio.h>
void sortAscending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j]   = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j]   = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n;
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    int arr[n], arr2[n];
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        arr2[i] = arr[i];
    }
    sortAscending(arr, n);
    printf("Sorting in ascending order\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    sortDescending(arr2, n);
    printf("\nSorting in descending order\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    return 0;
}