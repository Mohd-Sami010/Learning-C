#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    int id;
    char name[50];
    int age;
    char course[50];
};

struct Teacher {
    int id;
    char name[50];
    int age;
    char subject[50];
};

struct Staff {
    int id;
    char name[50];
    int age;
    char position[50];
};

int main() {
    struct Student students[MAX];
    struct Teacher teachers[MAX];
    struct Staff staff[MAX];
    int n_students = 0, n_teachers = 0, n_staff = 0;

    // Example: Add a student
    students[n_students].id = 1;
    strcpy(students[n_students].name, "Alice");
    students[n_students].age = 20;
    strcpy(students[n_students].course, "BSc Computer Science");
    n_students++;

    // Example: Add a teacher
    teachers[n_teachers].id = 1;
    strcpy(teachers[n_teachers].name, "Dr. Smith");
    teachers[n_teachers].age = 40;
    strcpy(teachers[n_teachers].subject, "Mathematics");
    n_teachers++;

    // Example: Add a staff member
    staff[n_staff].id = 1;
    strcpy(staff[n_staff].name, "Mr. John");
    staff[n_staff].age = 35;
    strcpy(staff[n_staff].position, "Librarian");
    n_staff++;

    // Print all students
    printf("Students:\n");
    for (int i = 0; i < n_students; i++)
        printf("ID: %d, Name: %s, Age: %d, Course: %s\n", students[i].id, students[i].name, students[i].age, students[i].course);

    // Print all teachers
    printf("\nTeachers:\n");
    for (int i = 0; i < n_teachers; i++)
        printf("ID: %d, Name: %s, Age: %d, Subject: %s\n", teachers[i].id, teachers[i].name, teachers[i].age, teachers[i].subject);

    // Print all staff
    printf("\nStaff:\n");
    for (int i = 0; i < n_staff; i++)
        printf("ID: %d, Name: %s, Age: %d, Position: %s\n", staff[i].id, staff[i].name, staff[i].age, staff[i].position);

    return 0;
}