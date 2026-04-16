#include <stdio.h>
int main() {
    int r, c;
    printf("Enter the number of rows and columns in the 2D Array\n");
    scanf("%d %d", &r, &c);
    int arr[r][c];
    printf("Enter the elements of the array\n");
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int top = 0, bottom = r - 1, left = 0, right = c - 1;
    printf("Spiral traversal of the array:\n");
    while(top <= bottom && left <= right){
        for(int i = left; i <= right; i++){
            printf("%d ", arr[top][i]);}
        top++;
        for(int i = top; i <= bottom; i++){
            printf("%d ", arr[i][right]);}
        right--;
        if(top <= bottom){
            for (int i = right; i >= left; i--){
                printf("%d ", arr[bottom][i]);}
            bottom--;
        }
        if(left <= right){
            for(int i = bottom; i >= top; i--){
                printf("%d ", arr[i][left]);}
            left++;
        }
    }
    printf("\n");
    return 0;
}