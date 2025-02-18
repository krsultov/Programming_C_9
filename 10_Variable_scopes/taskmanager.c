#include <stdio.h>
#include "processes.h"

int main(void) {

    while (1) {
        int choice;
        printf("1. List processes\n");
        printf("2. Create new process\n");
        printf("3. Stop process\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Listing processes\n");
                if (process_count == 0) {
                    printf("\nNo processes\n\n");
                    break;
                }
                for (int i = 0; i < process_count; i++) {
                    printf("Process %d: %s\n", processes[i].id, processes[i].name);
                }
                break;
            case 2:
                printf("Create new process\n");
                char name[30];
                printf("Enter process name: ");
                scanf("%s", name);
                unsigned int new_id = create_new_process(name);
                if (new_id == 0) {
                    printf("Failed to create new process.. Maximum number of processes is 5\n");
                } else {
                    printf("New process created with id %d\n", new_id);
                }
                break;
            case 3:
                printf("Stop process\n");
                unsigned int id;
                printf("Enter process id: ");
                scanf("%u", &id);
                unsigned int stopped_id = stop_process(id);
                if (stopped_id == 0) {
                    printf("Failed to stop process with id %d\n", id);
                } else {
                    printf("Process with id %d stopped\n", stopped_id);
                }
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }

    }
}