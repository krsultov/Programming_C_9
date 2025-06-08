#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef enum {
    NO_EDUCATION,
    PRIMARY_EDUCATION,
    SECONDARY_EDUCATION,
    HIGHER_EDUCATION
} Education;

typedef enum {
    UNEMPLOYED,
    EMPLOYED
} WorkStatus;

typedef enum {
    SINGLE,
    MARRIED
} MaritalStatus;

typedef struct {
    char egn[11];
    char name[MAX_NAME_LENGTH];
    unsigned char age;
    Education education;
    WorkStatus work_status;
    MaritalStatus marital_status;
} Citizen;

void add_record(FILE *file) {
    Citizen citizen;
    printf("Enter EGN (10 digits): ");
    scanf("%10s", citizen.egn);
    printf("Enter name (max 255 characters): ");
    getchar();
    fgets(citizen.name, MAX_NAME_LENGTH, stdin);
    citizen.name[strcspn(citizen.name, "\n")] = '\0';
    printf("Enter age: ");
    scanf("%hhu", &citizen.age);
    printf("Enter education (0: No, 1: Primary, 2: Secondary, 3: Higher): ");
    scanf("%d", (int *) &citizen.education);
    printf("Enter work status (0: Unemployed, 1: Employed): ");
    scanf("%d", (int *) &citizen.work_status);
    printf("Enter marital status (0: Single, 1: Married): ");
    scanf("%d", (int *) &citizen.marital_status);

    fwrite(&citizen, sizeof(Citizen), 1, file);
    printf("Record added successfully.\n");
}

void print_records(FILE *file) {
    Citizen citizen;
    rewind(file);
    while (fread(&citizen, sizeof(Citizen), 1, file)) {
        printf("EGN: %s\n", citizen.egn);
        printf("Name: %s\n", citizen.name);
        printf("Age: %hhu\n", citizen.age);
        printf("Education: %d\n", citizen.education);
        printf("Work Status: %d\n", citizen.work_status);
        printf("Marital Status: %d\n", citizen.marital_status);
        printf("--------------------\n");
    }
}

void delete_record(FILE *file, const char *filename) {
    char egn_to_delete[11];
    FILE *temp_file = fopen("temp.bin", "wb");
    if (!temp_file) {
        perror("Failed to create temporary file");
        return;
    }

    printf("Enter EGN to delete: ");
    scanf("%10s", egn_to_delete);

    Citizen citizen;
    rewind(file);
    int found = 0;
    while (fread(&citizen, sizeof(Citizen), 1, file)) {
        if (strcmp(citizen.egn, egn_to_delete) != 0) {
            fwrite(&citizen, sizeof(Citizen), 1, temp_file);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp_file);

    remove(filename);
    rename("temp.bin", filename);

    file = fopen(filename, "rb+");
    if (!file) {
        perror("Failed to reopen file");
        return;
    }

    if (found) {
        printf("Record deleted successfully.\n");
    } else {
        printf("Record not found.\n");
    }
}

int main() {
    char filename[256];

    printf("Enter binary file name: ");
    scanf("%255s", filename);

    FILE *file = fopen(filename, "rb+");
    if (!file) {
        file = fopen(filename, "wb+");
        if (!file) {
            perror("Failed to create file");
            return 1;
        }
        printf("File created successfully.\n");
    } else {
        printf("File opened successfully.\n");
    }

    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add record\n");
        printf("2. Print records\n");
        printf("3. Delete record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record(file);
                break;
            case 2:
                print_records(file);
                break;
            case 3:
                delete_record(file, filename);
                break;
            case 4:
                fclose(file);
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
