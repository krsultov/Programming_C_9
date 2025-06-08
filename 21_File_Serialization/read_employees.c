#include <stdio.h>
#include <stdlib.h>

typedef struct Employee {
    char name[100];
    int subordinate_count;
    struct Employee **subordinates;
} Employee;

Employee *deserialize_employee(FILE *file) {
    Employee *employee = malloc(sizeof(Employee));
    fread(employee->name, sizeof(char), 100, file);
    fread(&employee->subordinate_count, sizeof(int), 1, file);
    if (employee->subordinate_count > 0) {
        employee->subordinates = (Employee **)malloc(employee->subordinate_count * sizeof(Employee *));
        for (int i = 0; i < employee->subordinate_count; i++) {
            employee->subordinates[i] = deserialize_employee(file);
        }
    } else {
        employee->subordinates = NULL;
    }
    return employee;
}

void print_hierarchy(Employee *employee, int level) {
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    printf("%s\n", employee->name);
    for (int i = 0; i < employee->subordinate_count; i++) {
        print_hierarchy(employee->subordinates[i], level + 1);
    }
}

int main() {
    FILE *file = fopen("employees.bin", "rb");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }
    Employee *director = deserialize_employee(file);
    fclose(file);

    print_hierarchy(director, 0);

    free(director->subordinates[0]->subordinates[0]);
    free(director->subordinates[0]->subordinates[1]);
    free(director->subordinates[0]->subordinates[2]);
    free(director->subordinates[0]->subordinates);
    free(director->subordinates[0]);

    free(director->subordinates[1]->subordinates[0]);
    free(director->subordinates[1]->subordinates[1]);
    free(director->subordinates[1]->subordinates[2]);
    free(director->subordinates[1]->subordinates);
    free(director->subordinates[1]);

    free(director->subordinates);
    free(director);

    return 0;
}