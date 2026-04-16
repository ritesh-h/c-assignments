#include <stdio.h>
void reverse(int arr[], int l, int r) {
    while (l < r) {
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
        r--;
    }
}
void rightRot(int arr[], int n, int k) {
    k = k % n;
    reverse(arr, 0, n - k - 1);
    reverse(arr, n - k, n - 1);  
    reverse(arr, 0, n - 1);     
}
void leftRot(int arr[], int n, int k) {
    k = k % n;
    reverse(arr, 0, k - 1);    
    reverse(arr, k, n - 1);    
    reverse(arr, 0, n - 1);  
}
void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}
int main() {
    int n, k;
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    int arr[n], temp[n];
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);}
    printf("Enter the value of k\n");
    scanf("%d", &k);
    for (int i = 0; i < n; i++){
        temp[i] = arr[i];}
    rightRot(arr, n, k);
    printf("Array after right rotation\n");
    printArr(arr, n);
    leftRot(temp, n, k);
    printf("Array after left rotation\n");
    printArr(temp, n);
    return 0;
}