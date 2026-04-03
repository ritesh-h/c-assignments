#include <stdio.h>
struct student {
    int roll;
    char name[50];
    char gender;
    int marks;
};
int main() {
    int n, i, searchRoll, found = 0;
    printf("Enter the number of students\n");
    scanf("%d", &n);
    struct student s[n];
    for (i = 0; i < n; i++) {
        printf("Enter the roll number of the student %d\n", i + 1);
        scanf("%d", &s[i].roll);
        printf("Enter the name of the student %d\n", i + 1);
        scanf("%s", s[i].name);
        printf("Enter the gender of the student %d\n", i + 1);
        scanf(" %c", &s[i].gender);
        printf("Enter the marks of the student %d\n", i + 1);
        scanf("%d", &s[i].marks);
    }
    printf("\n----------------Student Information----------------\n");
    printf("%-12s %-20s %-10s %-10s\n", "Roll", "Name", "Marks", "Gender");
    for (i = 0; i < n; i++) {
        printf("%-12d %-20.20s %-10d %-10c\n",s[i].roll, s[i].name, s[i].marks, s[i].gender);
    }
    printf("\nEnter the roll number of the student you want to search\n");
    scanf("%d", &searchRoll);
    for (i = 0; i < n; i++) {
        if (s[i].roll == searchRoll) {
            printf("\n%-12s %-20s %-10s %-10s\n", "Roll", "Name", "Marks", "Gender");
            printf("%-12d %-20.20s %-10d %-10c\n",s[i].roll, s[i].name, s[i].marks, s[i].gender);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("Student data is not found in the record\n");
    }
    return 0;
}