#include <stdio.h>
#include <limits.h>
int kadane(int arr[], int n, int *start, int *end) {
    int maxSum = INT_MIN, sum = 0, tempStart = 0;
    *start = 0; *end = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum > maxSum) {
            maxSum = sum;
            *start = tempStart;
            *end = i;
        }
        if (sum < 0) {
            sum = 0;
            tempStart = i + 1;
        }
    }
    return maxSum;
}
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
    int maxSum = INT_MIN;
    int finalTop = 0, finalBottom = 0, finalLeft = 0, finalRight = 0;
    for (int left = 0; left < c; left++) {
        int temp[r];
        for (int i = 0; i < r; i++) temp[i] = 0;
        for (int right = left; right < c; right++) {
            for (int i = 0; i < r; i++){
                temp[i] += arr[i][right];
            }
            int top, bottom;
            int sum = kadane(temp, r, &top, &bottom);
            if (sum > maxSum) {
                maxSum      = sum;
                finalLeft   = left;
                finalRight  = right;
                finalTop    = top;
                finalBottom = bottom;
            }
        }
    }
    printf("The maximum sum rectangle is:\n");
    for (int i = finalTop; i <= finalBottom; i++) {
        for (int j = finalLeft; j <= finalRight; j++) {
            if (j != finalLeft) printf(" ");
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
    printf("The maximum sum is:\n%d\n", maxSum);
    return 0;
}