#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee {
    char name[100];
    int subordinate_count;
    struct Employee **subordinates;
} Employee;

Employee *create_employee(const char *name, int subordinate_count) {
    Employee *employee = malloc(sizeof(Employee));
    strncpy(employee->name, name, sizeof(employee->name) - 1);
    employee->name[sizeof(employee->name) - 1] = '\0';
    employee->subordinate_count = subordinate_count;
    if (subordinate_count > 0) {
        employee->subordinates = (Employee **)malloc(subordinate_count * sizeof(Employee *));
    } else {
        employee->subordinates = NULL;
    }
    return employee;
}

void serialize_employee(FILE *file, Employee *employee) {
    fwrite(employee->name, sizeof(char), 100, file);
    fwrite(&employee->subordinate_count, sizeof(int), 1, file);
    for (int i = 0; i < employee->subordinate_count; i++) {
        serialize_employee(file, employee->subordinates[i]);
    }
}

int main() {
    Employee *worker1 = create_employee("Worker 1", 0);
    Employee *worker2 = create_employee("Worker 2", 0);
    Employee *worker3 = create_employee("Worker 3", 0);
    Employee *worker4 = create_employee("Worker 4", 0);
    Employee *worker5 = create_employee("Worker 5", 0);
    Employee *worker6 = create_employee("Worker 6", 0);

    Employee *manager1 = create_employee("Manager 1", 3);
    manager1->subordinates[0] = worker1;
    manager1->subordinates[1] = worker2;
    manager1->subordinates[2] = worker3;

    Employee *manager2 = create_employee("Manager 2", 3);
    manager2->subordinates[0] = worker4;
    manager2->subordinates[1] = worker5;
    manager2->subordinates[2] = worker6;

    Employee *director = create_employee("Director", 2);
    director->subordinates[0] = manager1;
    director->subordinates[1] = manager2;

    FILE *file = fopen("employees.bin", "wb");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }
    serialize_employee(file, director);
    fclose(file);

    free(worker1);
    free(worker2);
    free(worker3);
    free(worker4);
    free(worker5);
    free(worker6);
    free(manager1->subordinates);
    free(manager1);
    free(manager2->subordinates);
    free(manager2);
    free(director->subordinates);
    free(director);

    return 0;
}