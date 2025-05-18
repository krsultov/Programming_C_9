#include "linked_list.h"
#include <stdio.h>
#include <string.h>

static const char* stateToStr(TaskState state) {
    switch (state) {
    case STATE_NEW: return "New";
    case STATE_IN_PROGRESS: return "In progress";
    case STATE_DONE: return "Finished";
    default: return "Unknown";
    }
}

static Task createTask(const char* name) {
    Task task;
    strncpy(task.name, name, MAX_NAME_LEN - 1);
    task.name[MAX_NAME_LEN - 1] = '\0';
    task.state = STATE_NEW;
    return task;
}

static void printTasks(const LinkedList* list) {
    printf("\n----- Task List -----\n");
    Node* current = list->head;
    uint i = 1;
    while (current) {
        printf("%2u. %-20s | %s\n", i, current->value.name,
               stateToStr(current->value.state));
        current = current->next;
        i++;
    }
    if (list->size == 0) printf("(empty)\n");
    printf("---------------------\n");
}

static void addTask(LinkedList* list) {
    char buffer[MAX_NAME_LEN];
    unsigned priority;
    printf("Task name: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    printf("Desired priority (1 .. %u): ", list->size + 1);
    scanf("%u", &priority);
    getchar();

    if (priority == 0) priority = 1;
    if (priority > list->size + 1) priority = list->size + 1;

    Task task = createTask(buffer);
    push(list, priority - 1, task);
}

static void changeState(LinkedList* list) {
    if (list->size == 0) {
        printf("No tasks.");
        return;
    }
    unsigned priority, choice;
    printf("Priority to change (1..%u): ", list->size);
    scanf("%u", &priority);
    getchar();
    if (priority == 0 || priority > list->size) {
        printf("Invalid priority!");
        return;
    }
    printf("New state:\n"
        " 1. New\n"
        " 2. In progress\n"
        " 3. Finished\n"
        "Choice: ");
    scanf("%u", &choice);
    getchar();
    Task task = get(list, priority - 1);
    switch (choice) {
    case 1: task.state = STATE_NEW;
        break;
    case 2: task.state = STATE_IN_PROGRESS;
        break;
    case 3: task.state = STATE_DONE;
        break;
    default: printf("Invalid choice!");
        return;
    }
    set(list, priority - 1, task);
}

static void deleteTask(LinkedList* list) {
    if (list->size == 0) {
        printf("No tasks.");
        return;
    }
    unsigned priority;
    printf("Priority to delete (1..%u): ", list->size);
    scanf("%u", &priority);
    getchar();
    if (priority == 0 || priority > list->size) {
        puts("Invalid priority!");
        return;
    }
    pop(list, priority - 1);
}

int main(void) {
    LinkedList tasks = init();
    int choice;

    do {
        printf("===== Menu =====\n");
        printf("1. Add task\n");
        printf("2. Change state\n");
        printf("3. Delete task\n");
        printf("4. Print tasks\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1: addTask(&tasks);
            break;
        case 2: changeState(&tasks);
            break;
        case 3: deleteTask(&tasks);
            break;
        case 4: printTasks(&tasks);
            break;
        case 0: break;
        default: printf("Invalid option!");
        }
    }
    while (choice != 0);

    release(&tasks);
    return 0;
}
