#include <stdio.h>
#include <stdlib.h>

#include "DynamicArray.h"

void add_donor(DynamicArray *donors, long long egn) {
    pushBack(donors, egn);
    printf("Donor with EGN %lld added successfully!\n", egn);
}

void remove_donor(DynamicArray *donors, long long egn) {
    int index = searchIndex(donors, egn);
    if (index != -1) {
        pop(donors, index);
        printf("Donor with EGN %lld removed successfully!\n", egn);
    } else {
        printf("Donor with EGN %lld not found!\n", egn);
    }
}

void view_donors(DynamicArray *donors) {
    if (donors->size == 0) {
        printf("No donors registered yet.\n");
        return;
    }

    printf("List of all donors (EGN):\n");
    for (int i = 0; i < donors->size; i++) {
        printf("%d. %lld\n", i + 1, donors->buffer[i]);
    }
}

int main(void) {
    DynamicArray donors = init(1);
    int choice = 0;
    long long egn;

    while (1) {
        printf("\nOrphanage Donor Management System\n");
        printf("Choose an option:\n");
        printf("1. Add a donor\n");
        printf("2. Remove a donor\n");
        printf("3. View donors\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter donor's EGN: ");
                scanf("%lld", &egn);
                add_donor(&donors, egn);
                break;

            case 2:
                printf("Enter donor's EGN to remove: ");
                scanf("%lld", &egn);
                remove_donor(&donors, egn);
                break;

            case 3:
                view_donors(&donors);
                break;

            case 4:
                release(&donors);
                return 0;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}
