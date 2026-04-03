#include <stdio.h>
#include <stdlib.h>
int main() {
    int *arr = NULL;  
    int count = 0, num, sum=0;    
    char choice;
    do {
        arr = (int *)realloc(arr, (count + 1) * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        printf("Enter integer\n");
        scanf("%d", &num);
        arr[count] = num;
        sum += num;
        count++;
        printf("Enter 'y' for giving further input; otherwise enter 'n'\n");
        scanf(" %c", &choice);
    }while (choice == 'y');
    float average = (float)sum / count;
    printf("The average is\n%.2f\n",average);
    free(arr);
    return 0;
}