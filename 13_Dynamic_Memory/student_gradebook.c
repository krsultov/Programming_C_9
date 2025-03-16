#include <stdio.h>
#include <stdlib.h>

#define CHECK_ALLOC(ptr) if ((ptr) == NULL) { \
    printf("Memory allocation failed\n"); \
    exit(1); \
}

float * read_grades(int num_grades) {
    float *grades = malloc(num_grades * sizeof(float));
    CHECK_ALLOC(grades);

    for (int i = 0; i < num_grades; i++) {
        printf("Enter grade %d: ", i + 1);
        scanf("%f", &grades[i]);
    }
    return grades;
}

float calculate_average(const float *grades, int num_grades) {
    float sum = 0;
    for (int i = 0; i < num_grades; i++) {
        sum += grades[i];
    }
    return sum / (float)num_grades;
}

float * add_grade(float *grades, int *num_grades, float new_grade) {
    float *new_grades = realloc(grades, (*num_grades + 1) * sizeof(float));
    CHECK_ALLOC(new_grades);

    new_grades[*num_grades] = new_grade;
    (*num_grades)++;
    return new_grades;
}

float * delete_last_grade(float *grades, int *num_grades) {
    if (*num_grades == 0) {
        printf("No grades to delete\n");
        return grades;
    }

    if (*num_grades == 1) {
        free(grades);
        (*num_grades)--;
        return NULL;
    }

    float *new_grades = realloc(grades, (*num_grades - 1) * sizeof(float));
    CHECK_ALLOC(new_grades);

    (*num_grades)--;
    return new_grades;
}

void print_grades(float *grades, int num_grades) {
    printf("Grades: \n");
    for (int i = 0; i < num_grades; i++) {
        printf("%.2f ", grades[i]);
    }
    printf("\n");
}

int main(void) {
    int num_grades;
    do {
        printf("Enter the number of grades: ");
        scanf("%d", &num_grades);
        if (num_grades < 0) {
            printf("Number of grades cannot be negative. Please enter a valid number.\n");
        }
    } while (num_grades < 0);

    float* grades = read_grades(num_grades);
    print_grades(grades, num_grades);

    while (1) {
        int choice;
        printf("Menu:\n");
        printf("1. Add grade\n");
        printf("2. Delete last grade\n");
        printf("3. Calculate average\n");
        printf("4. Exit\n");
        printf("Enter an option: ");

        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                float new_grade;
                printf("Enter the new grade: ");
                scanf("%f", &new_grade);
                grades = add_grade(grades, &num_grades, new_grade);
                print_grades(grades, num_grades);
                break;
            }
            case 2: {
                grades = delete_last_grade(grades, &num_grades);
                print_grades(grades, num_grades);
                break;
            }
            case 3: {
                if (num_grades == 0) {
                    printf("No grades available to calculate average.\n");
                } else {
                    printf("Average: %.2f\n", calculate_average(grades, num_grades));
                }
                break;
            }
            case 4: {
                free(grades);
                exit(0);
            }
            default: {
                printf("Invalid option\n");
                break;
            }
        }
    }
}