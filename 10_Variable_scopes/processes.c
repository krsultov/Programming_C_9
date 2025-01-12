#include "processes.h"
#include <limits.h>
#include <stdio.h>
#include <string.h>

int process_count = 0;
struct Process processes[5];

unsigned int next_process_id() {
    static unsigned int id = 0;

    if (id == UINT_MAX) {
        return 0;
    }

    return ++id;
}

unsigned int create_new_process(char name[30]) {
    unsigned int new_id = next_process_id();

    if (new_id == 0) return 0;
    if (process_count > 4) return 0;

    struct Process new_process;
    new_process.id = new_id;
    strcpy(new_process.name, name);

    processes[process_count++] = new_process;

    return new_process.id;
}

unsigned int stop_process(unsigned int id) {
    if (id == 0) return 0;

    for (int i = 0; i < process_count; i++) {
        if (processes[i].id == id) {

            for (int j = i; j < process_count - 1; j++) {
                processes[j] = processes[j + 1];
            }

            process_count--;
            return id;
        }
    }

    return 0;
}