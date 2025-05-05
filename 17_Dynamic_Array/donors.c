#include <stdio.h>

#include "DynamicArray.h"

void add_donor(DynamicArray *donors, int donor_id) {
    pushBack(donors, donor_id);
}

int main(void) {
    DynamicArray donors = init(1);

    while (1) {
        int choice;
        scanf("%d", &choice);

        printf("Choose an option:\n");
        printf("1. Add a donor\n");
        printf("2. Remove a donor\n");
        printf("3. View donor\n");
        printf("4. Exit\n");

        switch (choice) {
        }
    }

    return 0;
}
