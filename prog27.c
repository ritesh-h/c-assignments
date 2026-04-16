#include <stdio.h>
int main(){
    int r1, c1, r2, c2, i, j;
    printf("Enter the number of rows of the first matrix\n");
    scanf("%d", &r1);
    printf("Enter the number of columns of the first matrix\n");
    scanf("%d", &c1);
    printf("Enter the number of rows of the second matrix\n");
    scanf("%d", &r2);
    printf("Enter the number of columns of the second matrix\n");
    scanf("%d", &c2);
    if (c1 != r2) {
        printf("Matrix multiplication is not possible\n");
        return 0;
    }
    int A[r1][c1], B[r2][c2], C[r1][c2];
    printf("Enter the elements of the first matrix\n");
    for (i = 0; i < r1; i++){
        for (j = 0; j < c1; j++){
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter the elements of the second matrix\n");
    for (i = 0; i < r2; i++){
        for (j = 0; j < c2; j++){
            scanf("%d", &B[i][j]);
        }
    }
    for (i = 0; i < r1; i++){
        for (j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printf("Resultant matrix after matrix multiplication\n");
    for (i = 0; i < r1; i++){
        for (j = 0; j < c2; j++){
            if (j != 0) printf(" ");
            printf("%d", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}