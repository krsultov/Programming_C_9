#include <stdio.h>
#include <string.h>

typedef enum {
    false,
    true
} Bool;

typedef struct {
    short hour;
    short minutes;
} Time;

typedef struct {
    char first_name[50];
    char second_name[50];
    char last_name[50];
    char email[50];
    char phone[15];
} Volunteer;

typedef struct {
    Volunteer volunteer;
    Bool is_enrolled;
} Response;

typedef struct {
    char name[50];
    char description[100];

    struct {
        short day;
        short month;
        int year;
        struct {
            short hour;
            short minutes;
        } time;
    } dateTime;

    Response responses[100];
} Cause;

void print_response(Response *response) {
    printf("Volunteer Name: %s %s %s\n", response->volunteer.first_name, response->volunteer.second_name, response->volunteer.last_name);
    printf("Email: %s\n", response->volunteer.email);
    printf("Phone: %s\n", response->volunteer.phone);
    printf("Is Enrolled: %s\n", response->is_enrolled ? "Yes" : "No");
}

void print_cause(Cause *cause) {
    printf("Name: %s\n", cause->name);
    printf("Description: %s\n", cause->description);
    printf("Date: %02d/%02d/%04d\n", cause->dateTime.day, cause->dateTime.month, cause->dateTime.year);
    printf("Time: %02d:%02d\n", cause->dateTime.time.hour, cause->dateTime.time.minutes);
    for (int i = 0; i < 100; i++) {
        if (strlen(cause->responses[i].volunteer.first_name) > 0) {
            print_response(&cause->responses[i]);
        }
    }
}

int main(void) {
    Cause causes[2] = {
        [0] = {
            .name = "Cause 1",
            .description = "This is cause 1",
            .dateTime = {
                .day = 16,
                .month = 4,
                .year = 2025,
                .time = {
                    .hour = 4,
                    .minutes = 45
                }
            },
            .responses = {
                [0] = {
                    .volunteer = {"Will", "Harry", "Banks", "will@mail.com", "1234567890"},
                    .is_enrolled = true
                },
                [1] = {
                    .volunteer = {"Jane", "Doe", "Smith", "jane@mail.com", "0987654321"},
                    .is_enrolled = false
                }
            }
        },
        [1] = {
            .name = "Cause 2",
            .description = "This is cause 2",
            .dateTime = {
                .day = 17,
                .month = 5,
                .year = 2025,
                .time = {
                    .hour = 10,
                    .minutes = 30
                }
            },
            .responses = {
                [0] = {
                    .volunteer = {"John", "Doe", "Smith", "john@mail.com", "1122334455"},
                    .is_enrolled = true
                }
            }
        }
    };

    for (int i = 0; i < 2; i++) {
        print_cause(&causes[i]);
        printf("\n");
    }

    return 0;
}