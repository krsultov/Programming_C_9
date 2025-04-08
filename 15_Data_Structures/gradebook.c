#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 16

typedef struct {
    char name[MAX_NAME_LENGTH];
    int class_number;
    double average_grade;
} Student;

void add_student(Student **students, int *num_students) {
    (*num_students)++;
    Student *temp = realloc(*students, *num_students * sizeof(Student));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    *students = temp;

    printf("Enter student's name: ");
    scanf("%15s", (*students)[*num_students - 1].name);

    printf("Enter student's class number: ");
    scanf("%d", &(*students)[*num_students - 1].class_number);

    printf("Enter student's average grade: ");
    scanf("%lf", &(*students)[*num_students - 1].average_grade);
}

void print_students(Student *students, int num_students) {
    if (num_students == 0) {
        printf("No students available.\n");
        return;
    }

    printf("students:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s, Class Number: %d, Average Grade: %.2f\n",
               students[i].name, students[i].class_number, students[i].average_grade);
    }
}

int main(void) {
    Student *students = NULL;
    int num_students = 0;

    while (1) {
        int choice;
        printf("Menu:\n");
        printf("1. Add student\n");
        printf("2. Print all students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student(&students, &num_students);
                break;
            case 2:
                print_students(students, num_students);
                break;
            case 3:
                free(students);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}
