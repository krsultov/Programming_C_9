#include <stdio.h>
#include <stdlib.h>

int * read_grades(int num_grades) {
    int *grades = malloc(num_grades * sizeof(int));
    if (grades == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < num_grades; i++) {
        printf("Enter grade %d: ", i + 1);
        scanf("%d", &grades[i]);
    }
    return grades;
}

float calculate_average(const int *grades, int num_grades) {
    float sum = 0;
    for (int i = 0; i < num_grades; i++) {
        sum += (float)grades[i];
    }
    return sum / (float)num_grades;
}

int * add_grade(int *grades, int *num_grades, int new_grade) {
    int *new_grades = realloc(grades, (*num_grades + 1) * sizeof(int));
    if (new_grades == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    new_grades[*num_grades] = new_grade;
    (*num_grades)++;
    return new_grades;
}

int * delete_last_grade(int *grades, int *num_grades) {
    int *new_grades = realloc(grades, (*num_grades - 1) * sizeof(int));
    if (new_grades == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    (*num_grades)--;
    return new_grades;
}

void print_grades(int *grades, int num_grades) {
    printf("Grades: \n");
    for (int i = 0; i < num_grades; i++) {
        printf("%d ", grades[i]);
    }
    printf("\n");
}

int main(void) {
    printf("Enter the number of grades: ");
    int num_grades;
    scanf("%d", &num_grades);
    int* grades = read_grades(num_grades);
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
                int new_grade;
                printf("Enter the new grade: ");
                scanf("%d", &new_grade);
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
                printf("Average: %.00f\n", calculate_average(grades, num_grades));
                break;
            }
            case 4: {
                free(grades);
                return 0;
            }
            default: {
                printf("Invalid option\n");
                break;
            }
        }
    }

}