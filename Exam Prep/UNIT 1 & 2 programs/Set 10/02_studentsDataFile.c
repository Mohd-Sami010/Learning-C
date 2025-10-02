#include <stdio.h>

struct Student {
    char name[50];
    float marks;
    float cgpa;
    char course[50];
};

int main() {
    struct Student students[5];
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Input student data
    for (int i = 0; i < 5; i++) {
        printf("Enter name, marks, cgpa, course for student %d:\n", i + 1);
        scanf("%s %f %f %s", students[i].name, &students[i].marks, &students[i].cgpa, students[i].course);
    }

    // Write table header
    fprintf(file, "%-15s %-10s %-10s %-15s\n", "Name", "Marks", "CGPA", "Course");
    fprintf(file, "-------------------------------------------------------------\n");

    // Write student data
    for (int i = 0; i < 5; i++) {
        fprintf(file, "%-15s %-10.2f %-10.2f %-15s\n", students[i].name, students[i].marks, students[i].cgpa, students[i].course);
    }

    fclose(file);
    printf("Student data written to students.txt\n");
    return 0;
}