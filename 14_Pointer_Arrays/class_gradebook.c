#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 16
#define CHECK_ALLOC(ptr) if ((ptr) == NULL) { \
    printf("Memory allocation failed\n"); \
    exit(1); \
}

void read_string(char *str, int length) {
    fgets(str, length, stdin);
    char *nl_pos = strchr(str, '\n');
    if (nl_pos != NULL) {
        *nl_pos = '\0';
    }
}

void initialize_subjects(char ***subjects, int *num_subjects) {
    printf("Enter the number of subjects: ");
    scanf("%d", num_subjects);
    while (*num_subjects <= 0) {
        printf("Number of subjects must be positive. Enter again: ");
        scanf("%d", num_subjects);
    }
    while (getchar() != '\n') {}

    *subjects = malloc(*num_subjects * sizeof(char *));
    CHECK_ALLOC(*subjects);

    for (int i = 0; i < *num_subjects; i++) {
        (*subjects)[i] = malloc(MAX_NAME_LENGTH * sizeof(char));
        CHECK_ALLOC((*subjects)[i]);

        printf("Enter name of subject %d: ", i + 1);
        read_string((*subjects)[i], MAX_NAME_LENGTH);
    }
}

void add_student(char ***students, float ***grades, int *num_students, int num_subjects, char **subjects) {
    (*num_students)++;

    char **temp_students = realloc(*students, *num_students * sizeof(char *));
    float **temp_grades = realloc(*grades, *num_students * sizeof(float *));
    CHECK_ALLOC(temp_students);
    CHECK_ALLOC(temp_grades);

    *students = temp_students;
    *grades = temp_grades;

    (*students)[*num_students - 1] = malloc(MAX_NAME_LENGTH * sizeof(char));
    (*grades)[*num_students - 1] = malloc(num_subjects * sizeof(float));
    CHECK_ALLOC((*students)[*num_students - 1]);
    CHECK_ALLOC((*grades)[*num_students - 1]);

    printf("Enter name of student: ");
    read_string((*students)[*num_students - 1], MAX_NAME_LENGTH);

    for (int i = 0; i < num_subjects; i++) {
        printf("Enter grade for %s: ", subjects[i]);
        scanf("%f", &(*grades)[*num_students - 1][i]);
    }
    while (getchar() != '\n') {}
}

void print_gradebook(char **students, float **grades, int num_students, char **subjects, int num_subjects) {
    printf("%-15s", "");
    for (int i = 0; i < num_subjects; i++) {
        printf("%-15s", subjects[i]);
    }
    printf("\n");

    for (int i = 0; i < num_students; i++) {
        printf("%-15s", students[i]);
        for (int j = 0; j < num_subjects; j++) {
            printf("%-15.2f", grades[i][j]);
        }
        printf("\n");
    }
}

void free_memory(char **students, float **grades, int num_students, char **subjects, int num_subjects) {
    for (int i = 0; i < num_subjects; i++) {
        free(subjects[i]);
    }
    free(subjects);

    for (int i = 0; i < num_students; i++) {
        free(students[i]);
        free(grades[i]);
    }
    free(students);
    free(grades);
}

int main(void) {
    char **subjects;
    int num_subjects;
    char **students = NULL;
    float **grades = NULL;
    int num_students = 0;

    initialize_subjects(&subjects, &num_subjects);

    while (1) {
        int choice;
        printf("Menu:\n");
        printf("1. Add student\n");
        printf("2. Print gradebook\n");
        printf("3. Exit\n");
        printf("Enter an option: ");
        scanf("%d", &choice);
        while (getchar() != '\n') {}

        switch (choice) {
            case 1:
                add_student(&students, &grades, &num_students, num_subjects, subjects);
                break;
            case 2:
                print_gradebook(students, grades, num_students, subjects, num_subjects);
                break;
            case 3:
                free_memory(students, grades, num_students, subjects, num_subjects);
                exit(0);
            default:
                printf("Invalid option\n");
                break;
        }
    }
}