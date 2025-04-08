#include <stdio.h>

enum weekdays {
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main(void) {
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case MONDAY: printf("Monday\n"); break;
        case TUESDAY: printf("Tuesday\n"); break;
        case WEDNESDAY: printf("Wednesday\n"); break;
        case THURSDAY: printf("Thursday\n"); break;
        case FRIDAY: printf("Friday\n"); break;
        case SATURDAY: printf("Saturday\n"); break;
        case SUNDAY: printf("Sunday\n"); break;
        default: printf("Invalid choice\n"); break;
    }

    return 0;
}