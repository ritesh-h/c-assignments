#include <stdio.h>
int main() {
    int m, n;
    printf("Enter the number of students\n");
    scanf("%d", &m);
    printf("Enter the number of subjects\n");
    scanf("%d", &n);
    int marks[m][n];
    for (int i = 0; i < m; i++){
        printf("Enter the marks of student %d in the different subjects\n", i + 1);
        for (int j = 0; j < n; j++){
            scanf("%d", &marks[i][j]);
        }
    }
    for (int i = 0; i < m; i++){
        float sum = 0;
        for (int j = 0; j < n; j++){
            sum += marks[i][j];
        }
        printf("The average marks of student %d = %.2f\n", i+1, sum/n);
    }
    return 0;
}