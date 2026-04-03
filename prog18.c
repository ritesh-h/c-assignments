#include <stdio.h>
int main() {
    int n,sum=0;
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    float average = (float)sum / n;
    printf("Average =%.2f\n", average);
    printf("The array elements less than the average value are\n");
    for (int i = 0; i < n; i++) {
        if (arr[i] < average) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
    return 0;
}