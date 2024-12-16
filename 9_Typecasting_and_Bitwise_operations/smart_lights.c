#include <stdio.h>

void print_bits(char lights) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (lights >> i) & 1);
    }
    printf("\n");
}

void switch_light(char *lights, int room) {
    if (room < 1 || room > 8) {
        printf("Please enter a room number between 1 and 8.\n");
        return;
    }
    char mask = 1 << (room - 1);
    *lights ^= mask;
}

void print_state(char lights) {
    printf("The light is on in rooms: ");
    int any_on = 0;
    for (int i = 0; i < 8; ++i) {
        if (lights & (1 << i)) {
            printf("%d ", i + 1);
            any_on = 1;
        }
    }
    if (!any_on) {
        printf("All lights are off");
    }
    printf("\n");
}

int main(void) {
    char lights = 0; // 0000 0000
    int choice, room;

    while (1) {
        printf("1. Switch lights\n");
        printf("2. Print state\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter room number (1-8): ");
            scanf("%d", &room);
            switch_light(&lights, room);
            break;
            case 2:
                print_state(lights);
            break;
            case 3:
                return 0;
            default:
                printf("Please enter 1,2 or 3\n");
        }
    }
}
